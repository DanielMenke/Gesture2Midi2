#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "midioutput.h"
#include "videoengine.h"
#include "colorkeyerhsv.h"
#include "QTimer"
#include "QShortcut"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_note_2_clicked(bool checked);
    void on_note_3_clicked(bool checked);
    void on_note_4_clicked(bool checked);
    void on_note_5_clicked(bool checked);
    void on_note_6_clicked(bool checked);
    void on_note_7_clicked(bool checked);
    void on_note_8_clicked(bool checked);
    void on_note_9_clicked(bool checked);
    void on_note_10_clicked(bool checked);
    void on_note_11_clicked(bool checked);


    void on_midichannel_valueChanged(int arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_checkBoxMedian_toggled(bool checked);

    void on_checkBoxUseOpen_toggled(bool checked);

    void on_checkBoxMaskSmallRegions_toggled(bool checked);

    void on_hueTolerance_valueChanged(int value);

    void on_saturationTolerance_valueChanged(int value);

    void on_hueValue_valueChanged(int value);

    void on_saturationValue_valueChanged(int value);

    void sendMidiParameter();

    void on_sendMidiControllerCheckbox_toggled(bool checked);

    void on_midiMappingModeCheckBox_toggled(bool checked);

    void on_midiMappingModeButton_pressed();

    void on_midiMappingModeButton_released();

    void toggleButtonBySpaceBar();

    void on_midiControllerSpinBox_valueChanged(int arg1);

private:
    int midiControllerNumber;
    QTimer timer;
    Ui::MainWindow *ui;
    drumstick::rt::MIDIOutput midiOutput;
    int midichannel;
    VideoEngine *videoEngine;
    ColorKeyerHSV *colorKeyerHSV;
    bool sendMidiControllerEnabled;


};

#endif // MAINWINDOW_H
