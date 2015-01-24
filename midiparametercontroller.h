#ifndef MIDIPARAMETERCONTROLLER_H
#define MIDIPARAMETERCONTROLLER_H


class MidiParameterController
{

public:
    ~MidiParameterController();
    int normedValue;
    MidiParameterController();
    void setMidiController(int value);
    int getMidiController();

};

#endif // MIDIPARAMETERCONTROLLER_H
