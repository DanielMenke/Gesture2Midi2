#include "colorkeyerhsv.h"
#include <QDebug>
#include <QColor>
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;


ColorKeyerHSV::ColorKeyerHSV()
    : alpha(0)
    , useMedian(false)
    , useOpening(false)
    , useMaskSmallRegions(false)
    , handAnalyzer( new HandAnalyzer())

{
}





Mat ColorKeyerHSV::process(const Mat &input){

    Mat flipped;
    flip(input,flipped,1);

    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(flipped, hsvFrame, CV_BGR2HSV);

    float h = hueValue;
    float s = saturationValue;

    qColor.setHsv(h, s, 255, 255);
    QRgb toRgb = qColor.rgb();

    int r = qRed(toRgb);
    int g = qGreen(toRgb);
    int b = qBlue(toRgb);

    Scalar color(b,g,r);

   // qDebug()<<"R:" <<r<<"G:"<<g<<"B:" <<b<<"HUT"<<h<<"SAT"<<s;



    // perform color keying
    // output: 1 channel image
    Mat binaryMask = colorKeying(hsvFrame);

    if (useMedian){
        medianBlur(binaryMask, binaryMask, 5);
    }

    if (useOpening){
        erode(binaryMask, binaryMask, Mat());
        dilate(binaryMask, binaryMask, Mat());
    }

    if (useMaskSmallRegions){
        binaryMask = maskSmallRegions(binaryMask);
    }
    Mat final;
    // calculate center of mass
    centerOfMass(binaryMask);

    final = handAnalyzer->getResultMatFromMat(binaryMask);

    Point linksOben(0, 0);
    Point rechtsUnten( + 20, final.rows/2);

    rectangle(final,linksOben,rechtsUnten,color,CV_FILLED);
    return final;
}
Mat ColorKeyerHSV::colorKeying(Mat& hsvFrame){
    // initialize Mat object for output


    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);
   // qDebug() << output.type();
    //int saturationToleranceInBounds =

    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];
            hue *= 2;
            if (x == hsvFrame.cols / 2){
                if (y == hsvFrame.rows / 2){

                }
            }
            // Maskierung und Schwerpunktsberechnung
            bool isWhite = false;
            if (hueTolerance > std::abs(hueValue - hue)){
                if (saturationTolerance > std::abs(saturationValue - saturation)){
                        isWhite = true;
                }
            }
            if (isWhite){
                output.at<uchar>(y,x) = 255;
            }
            else{
                output.at<uchar>(y,x) = 0;
            }
        }
    }
      return output;
}

cv::Mat ColorKeyerHSV::maskSmallRegions(cv::Mat& mask){
    // copy input image; findContours() will modify its contents
    Mat copyOfMask;

    mask.copyTo(copyOfMask);

    // find all regions
    vector<vector<Point> >contours;
    findContours(copyOfMask, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    // find index of largest regionIndex
    int maxArea = 0;
    int maxAreaIndex = 0;
    for(int i = 0; i < contours.size(); i++){
        vector<Point>contour = contours[i];
        int area = contourArea(contour);
        if (maxArea < area){
            maxArea = area;
            maxAreaIndex = i;
        }
    }

    // erase all smaller regions
    for(int i = 0; i < contours.size(); i++){
        if (i != maxAreaIndex){
            drawContours(mask, contours, i, Scalar(0,0,0,0), CV_FILLED);
        }
    }
   return mask;
}

void ColorKeyerHSV::centerOfMass(Mat& image){
    int sumx = 0;
    int sumy = 0;
    int count = 0;

    for(int x = 0; x < image.cols; x++){
        for (int y = 0; y < image.rows; y++){
            if (image.at<uchar>(y,x) == 255){
                sumx += x;
                sumy += y;
                count++;
            }
        }
    }
    if (count > 0){
        center = (1 - alpha) * center + alpha * Point(sumx/count, sumy/count);
    }
}

void ColorKeyerHSV::drawCross(Mat& image, Point center, int length, Scalar color){
    if(center.x > 0 && center.y > 0){
        line(image, center-Point(0, length), center+Point(0,length), color, 1);
        line(image, center-Point(length, 0), center+Point(length, 0), color, 1);
    }

}

void ColorKeyerHSV::setHueValue(int value){
    hueValue = value;
}
void ColorKeyerHSV::setHueTolerance(int value){
    hueTolerance = value;

}

void ColorKeyerHSV::setSaturationTolerance(int value){
    saturationTolerance = value;
    //qDebug() << "saturationTolerance: " << value;
}
void ColorKeyerHSV::setSaturationValue(int value){
    saturationValue = value;
    //qDebug() << "saturationValue: " << value;
}
void ColorKeyerHSV::setAlpha(float alpha){
    this->alpha = alpha;
}

void ColorKeyerHSV::setMedianEnable(bool enable){
    this->useMedian = enable;
}

void ColorKeyerHSV::setOpeningEnable(bool enable){
    this->useOpening = enable;
}

void ColorKeyerHSV::setMaskSmallRegions(bool enable){
    this->useMaskSmallRegions = enable;
}
