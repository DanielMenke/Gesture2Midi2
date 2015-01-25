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
     void setCurrentPreset(vector<vector<int> > preset);
     void setNoteForNoteWithOctave(string note, int octave);
    vector<int> getCurrentNotes(int numberOfFingers);
     void initPreset();

private:
     //vector<int> currentlyPlaying;
     vector<vector<int>> preset;
     //bool isPlaying = false;
     int currentNote;
};

#endif // MIDINOTECONTROLLER_H
