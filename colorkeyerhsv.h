#ifndef COLORKEYERHSV_H
#define COLORKEYERHSV_H

#include "videoprocessor.h"
#include "handanalyzer.h"
#include <QColor>
class ColorKeyerHSV : public VideoProcessor
{
public:
    ColorKeyerHSV();
    int maxAreaIndex;
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void setHueTolerance(int);
    void setHueValue(int);
    void setSaturationTolerance(int);
    void setSaturationValue(int);
    void setAlpha(float alpha);
    void setTresholdEnable(bool enable);
    void setMedianEnable(bool enable);
    void setOpeningEnable(bool enable);
    void setMaskSmallRegions(bool enable);
    cv::Point center;
    QColor qColor;
    HandAnalyzer *handAnalyzer;

private:
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
    void centerOfMass(cv::Mat& image);
    cv::Mat maskSmallRegions(cv::Mat& image);
    cv::Mat colorKeying(cv::Mat &hsvFrame);
    cv::Scalar hsvToRgb(int *r, int *g, int *b, int h, int s);
private:

    int hueTolerance;
    int hueValue;
    int saturationTolerance;
    int saturationValue;
    float alpha;
    bool useMedian;
    bool useOpening;
    bool useMaskSmallRegions;


};

#endif // COLORKEYERHSV_H
