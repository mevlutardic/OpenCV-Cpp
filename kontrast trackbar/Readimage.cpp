#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;
int slider=100;
Mat src;
void callTbar(int , void *){

    cout<<"value : "<<slider<<endl;
    
    Mat newHigh,newLow;

    src.convertTo(newLow,-1,1,slider-100);

    imshow("img",newLow);
}


void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    Mat img = imread(path);

    src=img;


    

    imshow("img",img);
     createTrackbar("tracbar","img",&slider,200,callTbar,&slider);
     
    // imshow("newHigh",newHigh);
    // imshow("newLow",newLow);

    waitKey(0);
   
}


int main(){

    Showimage();   




}
