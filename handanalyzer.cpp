
#include "handanalyzer.h"
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "midiparametercontroller.h"
using namespace cv;

HandAnalyzer::HandAnalyzer():
    midiParameterController(new MidiParameterController())
{

}

int HandAnalyzer::getNumberOfFingers(){
    return this->numberOfFingers;
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

    int biggestArea = 0;
    int indexOfBiggestContour = -1;
    for (int count = 0; count < contours.size(); count++){
        vector<Point>contour = contours[count];
        int area = contourArea(contour);
        if (area > biggestArea){
            biggestArea = area;
            indexOfBiggestContour = count;
        }
    }
    if (indexOfBiggestContour != -1){
        Rect rect = boundingRect(contours[indexOfBiggestContour]);
        midiParameterController->setMidiController(rect.y);
        rectangle(conv,rect,(255,255,255),1,8,0);
    }

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
    if (indexOfBiggestContour != -1){
        //size_t count = contours[i].size();
        size_t count = contours[indexOfBiggestContour].size();

        if( count >=300 )
        {

            int finger = -2;
            vector<Vec4i>::iterator d=defects[indexOfBiggestContour].begin();
            while( d!=defects[indexOfBiggestContour].end() ) {
                Vec4i& v=(*d);
                int startidx=v[0]; Point ptStart( contours[indexOfBiggestContour][startidx] );
                int endidx=v[1]; Point ptEnd( contours[indexOfBiggestContour][endidx] );
                int faridx=v[2]; Point ptFar( contours[indexOfBiggestContour][faridx] );
                float depth = v[3] / 256;


                line(conv, ptStart, ptEnd, color2, 1 );
                line(conv, ptStart, ptFar, color3, 1 );
                line(conv, ptEnd, ptFar, color3, 1 );
                if (depth > 25.0f){
                    finger++;
                    circle(conv, ptFar,   10, color5, 2 );
                    circle(conv, ptStart, 12, color4, 4);
                    circle(conv, ptEnd, 12, color4, 4);



                }
                d++;
            }
            this->numberOfFingers = finger;


        }
       }

        return conv;

}

