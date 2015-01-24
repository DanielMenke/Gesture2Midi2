#include "midiparametercontroller.h"
#include "midioutput.h"

MidiParameterController::MidiParameterController():
    normedValue(0)

{

}


MidiParameterController::~MidiParameterController()
{

}

void MidiParameterController::setMidiController(int value)
{
    normedValue = 127-(value*0.25);

}

int MidiParameterController::getMidiController(){
    return normedValue;
}
