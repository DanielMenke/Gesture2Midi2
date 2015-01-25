#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include "videoengine.h"
#include "colorkeyerhsv.h"
#include "QShortcut"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    colorKeyerHSV(new ColorKeyerHSV())
{
    QShortcut *spacebar = new QShortcut(QKeySequence(Qt::Key_Space),this);
    ui->setupUi(this);
    ui->midiControllerSpinBox->setValue(16);
    connect(spacebar, SIGNAL(activated()), this, SLOT(toggleButtonBySpaceBar()));
    QStringList connections = midiOutput.connections(true);
    ui->comboBox->addItems(connections);

    connect(spacebar, SIGNAL(activated()), this, SLOT(toggleButtonBySpaceBar()));
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

    videoEngine -> start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete videoEngine;
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
        midiOutput.sendController(midichannel,midiControllerNumber,midiControllerValue);
        this->ui->midiControllerValueDisplay->setDigitCount(midiControllerValue);
        qDebug()<<"Midi-Controller-Out: "<<midiControllerValue;
    if (this->colorKeyerHSV->handAnalyzer->isSchlag()){
        qDebug() << "Schlag im MainWindow";

        /*
        if (this->isPlaying){
            for(vector<int>::iterator it = this->currentlyPlaying.begin(); it != this->currentlyPlaying.end(); ++it) {
                this->midiOutput.sendNoteOff(midichannel, *it, 0);
            }
            this->isPlaying = false;
        }*/
        int numberOfFingers = this->colorKeyerHSV->handAnalyzer->getNumberOfFingers();
        vector<int> currentNotes = this->colorKeyerHSV->handAnalyzer->midiNoteController->getCurrentNotes(numberOfFingers);
        this->midiOutput.sendNoteOn(midichannel, currentNotes.at(0),127);
        this->midiOutput.sendNoteOn(midichannel, currentNotes.at(1),127);
        this->midiOutput.sendNoteOn(midichannel, currentNotes.at(2),127);
        /*
        for(vector<int>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
          this->midiOutput.sendNoteOn(midichannel, *it, 127);
           this->currentlyPlaying.push_back(*it);
        }
        */
        this->isPlaying = true;

    }
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
