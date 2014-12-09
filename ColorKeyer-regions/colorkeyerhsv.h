#ifndef COLORKEYERHSV_H
#define COLORKEYERHSV_H

#include "../videoengine/videoprocessor.h"
#include <QColor>
class ColorKeyerHSV : public VideoProcessor
{
public:
    ColorKeyerHSV();
    int maxAreaIndex;
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void setHueUpperThreshold(int);
    void setHueLowerThreshold(int);
    void setSaturationThreshold(int);
    void setAlpha(float alpha);
    void setMedianEnable(bool enable);
    void setOpeningEnable(bool enable);
    void setMaskSmallRegions(bool enable);
    cv::Point center;
    QColor qColor;

private:
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
    void centerOfMass(cv::Mat& image);
    cv::Mat maskSmallRegions(cv::Mat& image);
    cv::Mat colorKeying(cv::Mat& hsvFrame);
    cv::Scalar hsvToRgb(int *r, int *g, int *b, int h, int s);
private:

    int hueUpperThreshold;
    int hueLowerThreshold;
    int saturationThreshold;
    float alpha;
    bool useMedian;
    bool useOpening;
    bool useMaskSmallRegions;
};

#endif // COLORKEYERHSV_H
