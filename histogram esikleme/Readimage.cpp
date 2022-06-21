#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int dizi[250];


void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/cards.jpg";
    
    Mat img=imread(path);
    Mat gray,canny;
    
    cvtColor(img,gray,COLOR_BGR2GRAY);
	
    for (int i=0; i<img.cols;i++){

        for (int j=0; j<img.rows; j++){

            for (int p = 0; p<255; p++){

                if(gray.at<uchar>(j,i)==p) {dizi[p]++;}

            }
        }
    }

    for (int i=0 ; i<255;i++){

        cout<<i<<"'lerin sayisi :"<<dizi[i]<<endl;

    }
    
	imshow("orjinal", img);
    imshow("gray", gray);


	waitKey(0);




}

int main(){

    Showimage();   




}
