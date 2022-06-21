#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

void getCounters(Mat imgDil ,Mat img){

    vector<vector<Point>> contours,conPoly;
    vector<Vec4i> hierarchy;

    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    

    for (int i=0;i<contours.size();i++){

        int area = contourArea(contours[i]);
        drawContours(img,contours,i,Scalar(255,0,255),-1);
        cout<<area<<endl;

        vector<vector<Point>> conPoly(contours.size()); //döngünün içinde olmalıdır.
        vector<Rect> bounRect(contours.size());

        string objectType;

        if (area>1000){

            float peri = arcLength(contours[i],true);
            approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
            //drawContours(img,conPoly,i,Scalar(255,0,255),2);

            cout<<conPoly[i].size()<<endl;

            bounRect[i]=boundingRect(conPoly[i]);

            rectangle(img,bounRect[i].tl(),bounRect[i].br(),Scalar(0,255,0),2);

            int objCor = (int)conPoly[i].size();

            if (objCor==3){objectType="Tri";}
            if (objCor==4){objectType="Rect";}
            if (objCor>4){objectType="Circle";}


            putText(img,objectType,{bounRect[i].x,bounRect[i].y-5},FONT_HERSHEY_DUPLEX,0.75,Scalar(0,0,255));
         
        }

    }

}


void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/shapes.png";
    
    Mat img=imread(path);
    Mat imgHSV,mask;
    Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

    
   
    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,25,75);
    Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));

    dilate(imgCanny,imgDil,kernel);

    getCounters(imgDil,img);

    imshow("img",img);
    // imshow("imgGray",imgGray);
    // imshow("imgBlur",imgBlur);
    // imshow("imgCanny",imgCanny);
    // imshow("imgDil",imgDil);
    
    waitKey(0);


}


int main(){

    Showimage();   




}
