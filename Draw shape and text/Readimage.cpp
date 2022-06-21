#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

   
    Mat img (512,512,CV_8UC3,Scalar(255,255,255));

   // circle(img,Point(256,256),100,Scalar(0,100,255),15);
    
    circle(img,Point(256,256),160,Scalar(0,69,255),FILLED);
    
    rectangle(img,Point(130,226),Point(382,286),Scalar(255,255,255),FILLED);

    line(img,Point(130,296),Point(382,296),Scalar(255,255,255),5);

    //putText(img," Mevlut Ardic",Point(137,262),FONT_HERSHEY_COMPLEX,1,Scalar(0,69,255),2);
    //putText(img,"Mevlut Ardic",Point(137,262),FONT_HERSHEY_COMPLEX_SMALL,1.5,Scalar(0,69,255),2);
    //putText(img,"Mevlut Ardic",Point(137,262),FONT_HERSHEY_DUPLEX,2,Scalar(0,69,255),2);
    //putText(img,"Mevlut Ardic",Point(137,262),FONT_HERSHEY_PLAIN,2.4,Scalar(0,69,255),2);
    //putText(img,"Mevlut Ardic",Point(137,262),FONT_HERSHEY_SCRIPT_COMPLEX,1.4,Scalar(0,69,255),2);
    //putText(img,"Mevlut Ardic",Point(137,262),FONT_HERSHEY_SCRIPT_SIMPLEX,1.4,Scalar(0,69,255),2);
    //putText(img,"Mevlut Ardic",Point(137,262),FONT_HERSHEY_SIMPLEX,1.3,Scalar(0,69,255),2);
    //putText(img,"Mevlut Ardic",Point(137,262),FONT_HERSHEY_TRIPLEX,1.1,Scalar(0,69,255),2);
    putText(img,"Mevlut Ardic",Point(137,262),FONT_ITALIC,1.3,Scalar(0,69,255),2);



    imshow("image",img);

    waitKey(0);


}




// void Showvideo(){

//     string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/test_video.mp4";
//     VideoCapture cap(path);
//     Mat img;
    
//     while (true){

//         cap.read(img);
//         imshow("video",img);

//         if ( (char)27 == (char) waitKey(25) ) break;


//     }


// }


// void ShowWebCam(){

//     string path = "/dev/video0";
//     VideoCapture cap(path);
//     Mat img;
    
//     while (true){

//         cap.read(img);
//         imshow("video",img);

      
//         if ( (char)27 == (char) waitKey(1) ) break;

//     }


// }

int main(){

    Showimage();   




}
