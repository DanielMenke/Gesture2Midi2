#ifndef MIDINOTECONTROLLER_H
#define MIDINOTECONTROLLER_H

#include <map>
#include <vector>

using namespace std;

class MidiNoteController
{
public:
    ~MidiNoteController();
    MidiNoteController();
    map<string, int> midiMap();
    void setPresetWithName(string presetName);
     void setCurrentPreset(vector<vector<int> > preset);
     void setNoteForNoteWithOctave(string note, int octave);
    vector<int> getCurrentNotes(int numberOfFingers);
     void initPreset();
     void initDurianPreset();
     void initOverdurPreset();

private:
     //vector<int> currentlyPlaying;
     vector<vector<int>> preset;
     bool isWriting = true;
     int currentNote;
};

#endif // MIDINOTECONTROLLER_H
