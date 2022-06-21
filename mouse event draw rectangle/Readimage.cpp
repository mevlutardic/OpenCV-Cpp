#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

Mat img ;
Point XY ;
Point p1;
Point p2;
void mouse(int event, int x,int y, int flag, void* userdata){
    
    if (event==EVENT_MOUSEMOVE)
    {
    

        XY =  Point(x,y);
        
        //cout<<"BGR : ["<<B<<","<<G<<","<<R<<"]"<<endl;
        cout<<" Points: "<<XY<<endl;
       
    }


    if(event==EVENT_LBUTTONDOWN)
    {
        p1 = XY;   
    }


    if( event==EVENT_MOUSEMOVE && flag==EVENT_FLAG_LBUTTON)
    {
        p2 = XY;   

        Mat atempt = Mat::zeros(img.size(),CV_8SC3);
        rectangle(atempt,p1,p2,Scalar(0,255,0),4,8,0);
        atempt=atempt+img;
        imshow("kırp",atempt);


    }
    if(event==EVENT_LBUTTONUP)
    {
        Rect crop;

        crop.x=p1.x;
        crop.y=p1.y;

        crop.width  = p2.x-p1.x;
        crop.height = p2.y-p1.y;

        Mat son = img(crop);
        imshow("window",son);
    }

}

int main(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    img = imread(path);
    namedWindow("window",WINDOW_AUTOSIZE);
    
    setMouseCallback("window",mouse,NULL);

    imshow("window",img);
    waitKey(0);
    return 0;

}
