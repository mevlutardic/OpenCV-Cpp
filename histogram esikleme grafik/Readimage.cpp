#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std; 
using namespace cv;

int dizi[250];


void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/lambo.png";
    
    Mat img=imread(path);
    Mat gray,canny;
    Mat Graph(800,1200,CV_8UC3,Scalar(0,0,0));
    
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

    for (int i=0; i<255 ; i++){

        line(Graph,Point(i*1200/255,800),Point(i*1200/255,800-dizi[i]/30),Scalar(50,i,dizi[i]),5,8,0);

    }


    
	imshow("orjinal", img);
    imshow("Graph", Graph);


	waitKey(0);




}

int main(){

    Showimage();   




}
