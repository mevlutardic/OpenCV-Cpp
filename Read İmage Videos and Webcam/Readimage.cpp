#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/test.png";
    Mat img = imread(path);// Mat bir matris veri tipidir.
    
    imshow("image",img);

    waitKey(1);


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

    // Showimage();   

    // Showvideo();

    ShowWebCam();


}
