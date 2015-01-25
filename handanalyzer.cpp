
#include "handanalyzer.h"
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "midiparametercontroller.h"
using namespace cv;

HandAnalyzer::HandAnalyzer():
    midiParameterController(new MidiParameterController())
    ,midiNoteController(new MidiNoteController())
{
    midiNoteController->setNoteForNoteWithOctave("C", 4);
    midiNoteController->initPreset();
}

cv::Mat HandAnalyzer::getResultMatFromMat(const Mat &input){
    Mat copy;
    Mat output;
    Mat conv;
    input.convertTo(output, CV_8UC1);


    Mat in[] = {output, output, output};
    merge(in,3,conv);


    input.copyTo(copy);

    erode(copy,copy, Mat());
    erode(copy,copy, Mat());
    dilate(copy,copy, Mat());
    dilate(copy,copy, Mat());

    vector<vector<Point> > contours;

    Mat converted;
    copy.convertTo(converted, CV_8UC1);

    findContours(converted, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    int indexOfLeftBiggestContour = -1;
    int indexOfRightBiggestContour = -1;
    int leftArea = 0;
    int rightArea = 0;

    int xBorder = copy.cols / 4;
    int index = 0;
    for (vector<Point> contour : contours){
        int area = contourArea(contour);
        Rect rect = boundingRect(contour);
        int xCenter = (rect.x + rect.width) / 2;
        qDebug() << "xborder: " << xBorder << "xcenter: " << xCenter;
        if (xCenter < xBorder){
            //Left side
            if (area > leftArea){
                leftArea = area;
                indexOfLeftBiggestContour = index;
            }
        } else {
            //Right side
            if (area > rightArea){
                rightArea = area;
                indexOfRightBiggestContour = index;
            }
        }

        index++;
    }

    if (indexOfRightBiggestContour != -1){
         qDebug() << "Rightside";
        Rect rect = boundingRect(contours[indexOfRightBiggestContour]);
        midiParameterController->setMidiController(rect.y);
        rectangle(conv,rect,(255,255,255),1,8,0);
    }
    if (indexOfLeftBiggestContour != -1){
         qDebug() << "löööftside";
          this->defineFingerDepth(contours[indexOfLeftBiggestContour], copy);
    }

    /*
    int secondBiggestArea=0;
    int indexOfSecondBiggestContour = -1;
    int biggestArea = 0;
    int indexOfBiggestContour = -1;

    for (int count = 0; count < contours.size(); count++){
        vector<Point>contour = contours[count];
        int area = contourArea(contour);
        if (area > biggestArea){
            secondBiggestArea=biggestArea;
            biggestArea = area;
            indexOfSecondBiggestContour = indexOfBiggestContour;
            indexOfBiggestContour = count;
        }
    }
    if (indexOfSecondBiggestContour != -1){
        Rect rect = boundingRect(contours[indexOfSecondBiggestContour]);
        midiParameterController->setMidiController(rect.y);
        this->defineFingerDepth(contours[indexOfBiggestContour], copy);
    
        rectangle(conv,rect,(255,255,255),1,8,0);
    } */

    // vector<vector<int> > hullsI(0);
    // vector<vector<Point> > hullsP(0);
   //  vector<vector<Vec4i> > defects(0);
    //if (contours.size() > 0){
        /// Find the convex hull object for each contour
        vector<vector<int> > hullsI(contours.size());
        vector<vector<Point> > hullsP(contours.size());
        vector<vector<Vec4i> > defects(contours.size());
        //vector<CvConvexityDefect> defects(contours.size());

   // }
    for(int i = 0; i <contours.size(); ++i){
        //find the hulls
        convexHull(contours[i], hullsI[i], false, false);
        convexHull(contours[i], hullsP[i], false, true);
        //find the defects
        if (contours[i].size() >3 )
        {
            convexityDefects(contours[i], hullsI[i], defects[i]);
        }

    }

    Scalar color1(255,255,0);
    //The next line causes an error
    //drawContours(output, hullsP, indexOfBiggestContour, color1, 1);
    Scalar color2(0,255,0);
    Scalar color3(0,0,255);
    Scalar color4(255,0,0);
    Scalar color5(0,255,255);

    /// Draw convexityDefects
    //for( int i = 0; i< contours.size(); i++ )
    //{
    int finger = 0;
    if (indexOfLeftBiggestContour != -1){
        //size_t count = contours[i].size();
        size_t count = contours[indexOfLeftBiggestContour].size();

        if( count >=300 )
        {

            vector<Vec4i>::iterator d=defects[indexOfLeftBiggestContour].begin();
            while( d!=defects[indexOfLeftBiggestContour].end() ) {
                Vec4i& v=(*d);
                int startidx=v[0]; Point ptStart( contours[indexOfLeftBiggestContour][startidx] );
                int endidx=v[1]; Point ptEnd( contours[indexOfLeftBiggestContour][endidx] );
                int faridx=v[2]; Point ptFar( contours[indexOfLeftBiggestContour][faridx] );
                float depth = v[3] / 256;


                line(conv, ptStart, ptEnd, color2, 1 );
                line(conv, ptStart, ptFar, color3, 1 );
                line(conv, ptEnd, ptFar, color3, 1 );
                if (depth > depthThreshold){
                    finger++;
                    circle(conv, ptFar,   10, color5, 2 );
                    circle(conv, ptStart, 12, color4, 4);
                    circle(conv, ptEnd, 12, color4, 4);



                }
                d++;
            }
            if (finger < 0){
                            finger = 0;
            } else if (finger > 5){
                            finger = 5;
            }
        }
       }
        this->setNumberOfFinger(finger);
        return conv;

}

//Neu von Finn
bool HandAnalyzer::isSchlag(){
    return this->schlag;
}

void HandAnalyzer::defineFingerDepth(cv::vector<Point> cnt, const Mat &input){
    int width = input.cols;
    int height = input.rows;
    float fingerhoehe = height * 0.25;
    Rect rect = boundingRect(cnt);
    int contourWidth = rect.width;
    int contourHeight = rect.height;
  //  qDebug() << "Rectwidth: " << contourWidth << ".Recthieght: " << contourHeight;

    float widthVerhaeltnis = width / contourWidth;
    float heightVerhaeltnis = height / contourHeight;
    float deltaAverage = (widthVerhaeltnis + heightVerhaeltnis) / 2;
    depthThreshold = fingerhoehe / deltaAverage;
   // qDebug() << "Neue Tiefe für Finger:" << depthThreshold << " Fingerhoehe: " << fingerhoehe << " deltaAverage: " << deltaAverage;
    int contourSizeAverage = (contourHeight + contourWidth) / 2;
    this->setRectAverage(contourSizeAverage);
}

void HandAnalyzer::setNumberOfFinger(int n){
    int bound = 12;
    this->fingerValues[bound] = n;
    for(int i = 0; i < bound; i++){
        this->fingerValues[i] = this->fingerValues[i+1];
    }
    int sum = 0;
    for(int i = 0; i < bound + 1; i++){
        //qDebug() << "Fingervalue #" << i << " is " << this->fingerValues[i];
        sum += this->fingerValues[i];
    }
     //qDebug() << "Summe: " << sum;
    this->numberOfFingers = sum / bound;
}

int HandAnalyzer::getNumberOfFingers(){
    return this->numberOfFingers;
}

void HandAnalyzer::setRectAverage(int rectA){
    float rectVerhaeltnis = 1.5;
    int bound = 7;
    for(int i = 0; i < bound; i++){
        this->rectAverages[i] = this->rectAverages[i+1];
    }
    this->rectAverages[bound] = rectA;
    int sum = 0;
    bound -= 2;
    for(int i = 0; i < bound + 1; i++){
        sum += this->rectAverages[i];
    }
    int averageOfTheOlderRects = sum / bound;
    if (rectA > (averageOfTheOlderRects * rectVerhaeltnis)){
        this->schlag = true;
        qDebug() << "Schlag mit " << this->numberOfFingers << " Finger.";
    } else {
        this->schlag = false;
    }

}

