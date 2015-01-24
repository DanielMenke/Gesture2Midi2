/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "../videoengine/videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *note_1;
    QPushButton *note_2;
    QPushButton *note_3;
    QPushButton *note_4;
    QPushButton *note_5;
    QPushButton *note_6;
    QPushButton *note_7;
    QPushButton *note_8;
    QSlider *volume;
    QSlider *pitchbend;
    QSpinBox *midichannel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QSpinBox *program;
    QLabel *label_6;
    QPushButton *note_9;
    QPushButton *note_10;
    QPushButton *note_11;
    QPushButton *note_12;
    VideoWidget *videoLabel;
    QCheckBox *checkBoxMedian;
    QCheckBox *checkBoxUseOpen;
    QCheckBox *checkBoxMaskSmallRegions;
    QSlider *sliderHueUpperTreshold;
    QSlider *sliderHueLowerTreshold;
    QSlider *sliderSaturationTreshold;
    QFrame *line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1153, 571);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        note_1 = new QPushButton(centralWidget);
        note_1->setObjectName(QStringLiteral("note_1"));
        note_1->setGeometry(QRect(40, 190, 16, 23));
        note_1->setCheckable(true);
        note_2 = new QPushButton(centralWidget);
        note_2->setObjectName(QStringLiteral("note_2"));
        note_2->setGeometry(QRect(60, 190, 16, 23));
        note_2->setCheckable(true);
        note_3 = new QPushButton(centralWidget);
        note_3->setObjectName(QStringLiteral("note_3"));
        note_3->setGeometry(QRect(80, 190, 16, 23));
        note_3->setCheckable(true);
        note_4 = new QPushButton(centralWidget);
        note_4->setObjectName(QStringLiteral("note_4"));
        note_4->setGeometry(QRect(100, 190, 16, 23));
        note_4->setCheckable(true);
        note_5 = new QPushButton(centralWidget);
        note_5->setObjectName(QStringLiteral("note_5"));
        note_5->setGeometry(QRect(120, 190, 16, 23));
        note_5->setCheckable(true);
        note_6 = new QPushButton(centralWidget);
        note_6->setObjectName(QStringLiteral("note_6"));
        note_6->setGeometry(QRect(140, 190, 16, 23));
        note_6->setCheckable(true);
        note_7 = new QPushButton(centralWidget);
        note_7->setObjectName(QStringLiteral("note_7"));
        note_7->setGeometry(QRect(160, 190, 16, 23));
        note_7->setCheckable(true);
        note_8 = new QPushButton(centralWidget);
        note_8->setObjectName(QStringLiteral("note_8"));
        note_8->setGeometry(QRect(180, 190, 16, 23));
        note_8->setCheckable(true);
        volume = new QSlider(centralWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(90, 270, 121, 21));
        volume->setMaximum(127);
        volume->setValue(127);
        volume->setOrientation(Qt::Horizontal);
        pitchbend = new QSlider(centralWidget);
        pitchbend->setObjectName(QStringLiteral("pitchbend"));
        pitchbend->setGeometry(QRect(300, 109, 22, 131));
        pitchbend->setMaximum(16383);
        pitchbend->setValue(8192);
        pitchbend->setOrientation(Qt::Vertical);
        midichannel = new QSpinBox(centralWidget);
        midichannel->setObjectName(QStringLiteral("midichannel"));
        midichannel->setGeometry(QRect(110, 80, 42, 22));
        midichannel->setMaximum(15);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 160, 46, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 46, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 270, 46, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 80, 46, 13));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 20, 181, 22));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 20, 91, 16));
        program = new QSpinBox(centralWidget);
        program->setObjectName(QStringLiteral("program"));
        program->setGeometry(QRect(110, 120, 42, 22));
        program->setMaximum(127);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 120, 46, 13));
        note_9 = new QPushButton(centralWidget);
        note_9->setObjectName(QStringLiteral("note_9"));
        note_9->setGeometry(QRect(200, 190, 16, 23));
        note_9->setCheckable(true);
        note_10 = new QPushButton(centralWidget);
        note_10->setObjectName(QStringLiteral("note_10"));
        note_10->setGeometry(QRect(220, 190, 16, 23));
        note_10->setCheckable(true);
        note_11 = new QPushButton(centralWidget);
        note_11->setObjectName(QStringLiteral("note_11"));
        note_11->setGeometry(QRect(240, 190, 16, 23));
        note_11->setCheckable(true);
        note_12 = new QPushButton(centralWidget);
        note_12->setObjectName(QStringLiteral("note_12"));
        note_12->setGeometry(QRect(260, 190, 16, 23));
        note_12->setCheckable(true);
        videoLabel = new VideoWidget(centralWidget);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));
        videoLabel->setGeometry(QRect(460, 30, 640, 480));
        videoLabel->setFrameShape(QFrame::Box);
        checkBoxMedian = new QCheckBox(centralWidget);
        checkBoxMedian->setObjectName(QStringLiteral("checkBoxMedian"));
        checkBoxMedian->setGeometry(QRect(60, 360, 111, 21));
        checkBoxUseOpen = new QCheckBox(centralWidget);
        checkBoxUseOpen->setObjectName(QStringLiteral("checkBoxUseOpen"));
        checkBoxUseOpen->setEnabled(true);
        checkBoxUseOpen->setGeometry(QRect(60, 400, 111, 21));
        checkBoxMaskSmallRegions = new QCheckBox(centralWidget);
        checkBoxMaskSmallRegions->setObjectName(QStringLiteral("checkBoxMaskSmallRegions"));
        checkBoxMaskSmallRegions->setEnabled(true);
        checkBoxMaskSmallRegions->setGeometry(QRect(60, 440, 111, 21));
        sliderHueUpperTreshold = new QSlider(centralWidget);
        sliderHueUpperTreshold->setObjectName(QStringLiteral("sliderHueUpperTreshold"));
        sliderHueUpperTreshold->setGeometry(QRect(220, 340, 16, 160));
        sliderHueUpperTreshold->setMinimum(0);
        sliderHueUpperTreshold->setMaximum(360);
        sliderHueUpperTreshold->setValue(360);
        sliderHueUpperTreshold->setOrientation(Qt::Vertical);
        sliderHueLowerTreshold = new QSlider(centralWidget);
        sliderHueLowerTreshold->setObjectName(QStringLiteral("sliderHueLowerTreshold"));
        sliderHueLowerTreshold->setGeometry(QRect(300, 340, 16, 160));
        sliderHueLowerTreshold->setMaximum(360);
        sliderHueLowerTreshold->setOrientation(Qt::Vertical);
        sliderSaturationTreshold = new QSlider(centralWidget);
        sliderSaturationTreshold->setObjectName(QStringLiteral("sliderSaturationTreshold"));
        sliderSaturationTreshold->setGeometry(QRect(380, 340, 16, 160));
        sliderSaturationTreshold->setMaximum(255);
        sliderSaturationTreshold->setValue(122);
        sliderSaturationTreshold->setOrientation(Qt::Vertical);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 300, 461, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1153, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        note_1->setText(QString());
        note_2->setText(QString());
        note_3->setText(QString());
        note_4->setText(QString());
        note_5->setText(QString());
        note_6->setText(QString());
        note_7->setText(QString());
        note_8->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Notes", 0));
        label_2->setText(QApplication::translate("MainWindow", "Channel:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Volume:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Pitchbend", 0));
        label_5->setText(QApplication::translate("MainWindow", "Midi Output Device:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Program:", 0));
        note_9->setText(QString());
        note_10->setText(QString());
        note_11->setText(QString());
        note_12->setText(QString());
        videoLabel->setText(QString());
        checkBoxMedian->setText(QApplication::translate("MainWindow", "Median Filter", 0));
        checkBoxUseOpen->setText(QApplication::translate("MainWindow", "Use Open", 0));
        checkBoxMaskSmallRegions->setText(QApplication::translate("MainWindow", "Mask Small Regions", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
