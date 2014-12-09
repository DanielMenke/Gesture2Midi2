#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "midioutput.h"
#include "../videoengine/videoengine.h"
#include "../ColorKeyer-regions/colorkeyerhsv.h"

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
    void on_note_1_clicked(bool checked);
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
    void on_note_12_clicked(bool checked);
    void on_volume_valueChanged(int value);

    void on_pitchbend_valueChanged(int value);

    void on_midichannel_valueChanged(int arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_program_valueChanged(int arg1);

    void on_checkBoxMedian_toggled(bool checked);

    void on_checkBoxUseOpen_toggled(bool checked);

    void on_checkBoxMaskSmallRegions_toggled(bool checked);

    void on_sliderHueLowerTreshold_valueChanged(int value);

    void on_sliderHueUpperTreshold_valueChanged(int value);

    void on_sliderSaturationTreshold_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    drumstick::rt::MIDIOutput midiOutput;
    int midichannel;
    VideoEngine *videoEngine;
    ColorKeyerHSV *colorKeyerHSV;
};

#endif // MAINWINDOW_H
