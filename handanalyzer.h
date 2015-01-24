#ifndef HANDANALYZER_H
#define HANDANALYZER_H
#include <opencv2/opencv.hpp>
#include "midiparametercontroller.h"
class HandAnalyzer
{
public:
    HandAnalyzer();
    cv::Mat getResultMatFromMat(const cv::Mat&source);
    int getNumberOfFingers();
    bool isSchlag();
    MidiParameterController *midiParameterController;

private:
    int numberOfFingers;

};

#endif // HANDANALYZER_H
