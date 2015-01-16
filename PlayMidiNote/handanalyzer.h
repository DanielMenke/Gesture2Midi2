#ifndef HANDANALYZER_H
#define HANDANALYZER_H

class HandAnalyzer
{
public:
    HandAnalyzer();
    cv::Mat getResultMatFromMat(const cv::Mat&source);
    int getNumberOfFingers();
    bool isSchlag();

private:
    int numberOfFingers;
};

#endif // HANDANALYZER_H
