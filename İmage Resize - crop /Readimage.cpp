#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/test.png";
    Mat img = imread(path);// Mat bir matris veri tipidir.

    Mat imaResize,imgCrop;

    cout<<img.size()<<endl;
   

    resize(img,imaResize,Size(),0.5,0.5);

    Rect roi(200,100,300,250);

    imgCrop=img(roi);


    imshow("image",img);
    
    imshow("imaResize",imaResize);

    imshow("imgCrop",imgCrop);

    waitKey(0);


}




void Showvideo(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/test_video.mp4";
    VideoCapture cap(path);
    Mat img;
    
    while (true){

        cap.read(img);
        imshow("video",img);

        if ( (char)27 == (char) waitKey(25) ) break;


    }


}


void ShowWebCam(){

    string path = "/dev/video0";
    VideoCapture cap(path);
    Mat img;
    
    while (true){

        cap.read(img);
        imshow("video",img);

      
        if ( (char)27 == (char) waitKey(1) ) break;

    }


}

int main(){

    Showimage();   




}
