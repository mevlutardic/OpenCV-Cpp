#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/cards.jpg";
    
    Mat img=imread(path);
    
    Mat matrix, imgWrap;

    float w=250,h=350; 

    //resize(img,img,Size(),0.8,0.8);

    

    Point2f src[4]={{529,142},{771,190},{405,395},{674,457}}; // görselde döndürülecek nesne köşeleri seçilir. 
    Point2f dst[4]={{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

    matrix = getPerspectiveTransform(src,dst);

    warpPerspective(img,imgWrap,matrix,Point(w,h));


    for (int i=0; i<4;i++){
        circle(img,src[i],10,Scalar(0,69,255),FILLED);
    }


    imshow("image",img);

    imshow("imgWrap",imgWrap);

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
