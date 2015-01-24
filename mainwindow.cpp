#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include "videoengine.h"
#include "colorkeyerhsv.h"
#include "QShortcut"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    colorKeyerHSV(new ColorKeyerHSV())
{
    QShortcut *spacebar = new QShortcut(QKeySequence(Qt::Key_Space),this);
    ui->setupUi(this);
    ui->midiControllerSpinBox->setValue(16);

    QStringList connections = midiOutput.connections(true);
    ui->comboBox->addItems(connections);
    midiOutput.open("LoopBe Internal MIDI");
    midichannel = ui->midichannel->value();
    colorKeyerHSV->setHueTolerance(ui->hueTolerance->value());
    colorKeyerHSV->setHueValue(ui->hueValue->value());
    colorKeyerHSV->setSaturationTolerance(ui->saturationTolerance->value());
    colorKeyerHSV->setSaturationValue(ui->saturationValue->value());
    videoEngine = new VideoEngine();
    videoEngine -> setProcessor(colorKeyerHSV);
    connect(videoEngine, SIGNAL(sendProcessedImage(const QImage&)), ui->videoLabel, SLOT(setImage(const QImage&)));
    videoEngine -> openCamera();
    connect(spacebar, SIGNAL(activated()), this, SLOT(toggleButtonBySpaceBar()));
    videoEngine -> start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete videoEngine;
}


void MainWindow::on_note_2_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 61, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 61, 0);
    }
}
void MainWindow::on_note_3_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 62, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 62, 0);
    }
}
void MainWindow::on_note_4_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 63, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 63, 0);
    }
}
void MainWindow::on_note_5_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 64, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 64, 0);
    }
}
void MainWindow::on_note_6_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 65, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 65, 0);
    }
}
void MainWindow::on_note_7_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 66, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 66, 0);
    }
}
void MainWindow::on_note_8_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_note_9_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_note_10_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_note_11_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}


void MainWindow::on_midichannel_valueChanged(int arg1)
{
    midichannel = arg1;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    midiOutput.open(arg1);
}



void MainWindow::on_checkBoxMedian_toggled(bool checked)
{
    colorKeyerHSV->setMedianEnable(checked);
}

void MainWindow::on_checkBoxUseOpen_toggled(bool checked)
{
    colorKeyerHSV->setOpeningEnable(checked);
}

void MainWindow::on_checkBoxMaskSmallRegions_toggled(bool checked)
{
    colorKeyerHSV->setMaskSmallRegions(checked);
}

void MainWindow::on_hueTolerance_valueChanged(int value)
{
    colorKeyerHSV->setHueTolerance(value);
}

void MainWindow::on_saturationTolerance_valueChanged(int value)
{
    colorKeyerHSV->setSaturationTolerance(value);
}

void MainWindow::on_hueValue_valueChanged(int value)
{
    colorKeyerHSV->setHueValue(value);
}

void MainWindow::on_saturationValue_valueChanged(int value)
{
    colorKeyerHSV->setSaturationValue(value);
}

void MainWindow::sendMidiParameter(){
        int midiControllerValue = colorKeyerHSV->handAnalyzer->midiParameterController->getMidiController();
        midiOutput.sendController(midichannel,midiControllerValue,midiControllerValue);
        qDebug()<<"Midi-Controller-Out: "<<midiControllerValue;

}


void MainWindow::on_sendMidiControllerCheckbox_toggled(bool checked){
     this->ui->midiMappingModeCheckBox->setDisabled(checked);
     this->ui->midiMappingModeButton->setDisabled(checked);
    if(checked){
        connect(&timer, SIGNAL(timeout()),this, SLOT(sendMidiParameter()));
        timer.start(50);
    }else{
        timer.stop();
    }
}

void MainWindow::on_midiMappingModeCheckBox_toggled(bool checked){
     this->ui->sendMidiControllerCheckbox->setDisabled(checked);
    if (checked) {
        timer.stop();


    }
}

void MainWindow::on_midiMappingModeButton_pressed()
{
    midiOutput.sendController(midichannel,midiControllerNumber,127);
}

void MainWindow::on_midiMappingModeButton_released()
{
    midiOutput.sendController(midichannel,midiControllerNumber,0);
}
void MainWindow::toggleButtonBySpaceBar()
{
    this->ui->midiMappingModeButton->animateClick();
}

void MainWindow::on_midiControllerSpinBox_valueChanged(int arg1)
{
    midiControllerNumber = arg1;
}
