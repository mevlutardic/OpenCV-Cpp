#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

void Showimage(){

    string path = "//home/afaraarge/Masaüstü/video/24.frame.jpg";
    
    Mat img=imread(path);
    Mat imgGray,imgThresh_binary;
    Mat imgThresh_mask;
    Mat imgThresh_binary_inv;
    Mat imgThresh_otsu;
    Mat imgThresh_tozero;
    Mat imgThresh_tozero_inv;
    Mat imgThresh_triangle;
    Mat imgThresh_trunc;

    cvtColor(img,imgGray,COLOR_BGR2GRAY);

    threshold(imgGray,imgThresh_binary_inv,30,255,THRESH_BINARY_INV);
    threshold(imgGray,imgThresh_mask,30,120,THRESH_MASK);
    threshold(imgGray,imgThresh_otsu,30,255,THRESH_OTSU);
    threshold(imgGray,imgThresh_tozero,30,255,THRESH_TOZERO);
    threshold(imgGray,imgThresh_tozero_inv,30,255,THRESH_TOZERO_INV);
    threshold(imgGray,imgThresh_triangle,30,255,THRESH_TRIANGLE);
    threshold(imgGray,imgThresh_trunc,30,255,THRESH_TRUNC);
    
    imshow("img",img); 

    imshow("imgThresh_binary_inv",imgThresh_binary_inv); 
    imshow("imgThresh_mask",imgThresh_mask); 
    imshow("imgThresh_otsu",imgThresh_otsu); 
    imshow("imgThresh_tozero",imgThresh_tozero); 
    imshow("imgThresh_tozero_inv",imgThresh_tozero_inv); 
    imshow("imgThresh_triangle",imgThresh_triangle); 
    imshow("imgThresh_trunc",imgThresh_trunc); 

    waitKey(0);
   
}


int main(){

    Showimage();   




}
