
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/test.png";
    Mat img = imread(path);// Mat bir matris veri tipidir.
    Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

    cvtColor(img,imgGray,COLOR_BGR2GRAY);

    GaussianBlur(img,imgBlur, Size(3,3), 3, 0);

    Canny(imgBlur,imgCanny,50,150);

    Mat karnel = getStructuringElement(MORPH_RECT,Size(5,5));

    dilate(imgCanny,imgDil,karnel);

    erode(imgDil,imgErode,karnel);
    
    imshow("image",img);

    imshow("imgGray",imgGray);

    imshow("imgBlur",imgBlur);

    imshow("imgCanny",imgCanny);

    imshow("imgDil",imgDil);

    imshow("imgErode",imgErode);

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
