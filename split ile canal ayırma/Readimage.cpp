#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/shapes.png";
    
    Mat img=imread(path);
    Mat rgbChanels[3];


    split(img,rgbChanels);

    vector<Mat> kanallar;

    kanallar.push_back(rgbChanels[0]);
    kanallar.push_back(rgbChanels[1]);
    kanallar.push_back(rgbChanels[2]);

    merge(kanallar,img);
    imshow("son",img);

    waitKey(0);
   
}


int main(){

    Showimage();   




}
