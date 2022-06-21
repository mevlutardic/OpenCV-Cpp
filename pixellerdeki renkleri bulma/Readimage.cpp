#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    Mat img = imread(path);

    
    cout<<img.size()<<endl;



    int blue,green,red;
    int x=240;
    int y=250;
    blue= img.at<Vec3b>(x,y)[0];
    green= img.at<Vec3b>(x,y)[1];
    red= img.at<Vec3b>(x,y)[2];

    Mat color(480,480,CV_8UC3,Scalar(blue,green,red));

    circle(img,Point(x,y),4,Scalar(0,0,255),1);

    Mat Gray;
    cvtColor(img,Gray,COLOR_BGR2GRAY);
    int yogunluk = img.at<uchar>(x,y) ;


    cout<<"blue:"<<blue<<endl;
    cout<<"green:"<<green<<endl;
    cout<<"red:"<<red<<endl;
    cout<<"yogunluk:"<<yogunluk<<endl;



    imshow("color",color);
    imshow("img",img);

    waitKey(0);
   
}


int main(){

    Showimage();   




}
