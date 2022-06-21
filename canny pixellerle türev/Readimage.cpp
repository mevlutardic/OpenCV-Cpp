#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




int trackval=0;
Mat img;
Mat gray,canny;

void cannyHandle(){



}
void track(int ,void*){

    Mat dst(img.size(),CV_8UC1,Scalar(0)); 
    Mat dst2(img.size(),CV_8UC1,Scalar(0)); 

    for(int i=0;i<img.cols-1;i++)
    {

        for (int j=0;j<img.rows-1;j++)
        {
            int a=gray.at<uchar>(j+1,i)-gray.at<uchar>(j,i);
            int b=gray.at<uchar>(j,i)-gray.at<uchar>(j+1,i);

            if (a>trackval || b>trackval){
                dst.at<uchar>(j,i)=255;
            }

            else{

                dst.at<uchar>(j,i)=0;
            }

        }
    }


    for(int i=0;i<img.cols-1;i++)
    {

        for (int j=0;j<img.rows-1;j++)
        {
            int a=gray.at<uchar>(j,i+1)-gray.at<uchar>(j,i);
            int b=gray.at<uchar>(j,i)-gray.at<uchar>(j,i+1);

            if (a>trackval || b>trackval){
                dst2.at<uchar>(j,i)=255;
            }

            else{

                dst2.at<uchar>(j,i)=0;
            }

        }
    }

    imshow("orjinal",dst+dst2);

}

void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/cards.jpg";
    
    img=imread(path);
    
    
    cvtColor(img,gray,COLOR_BGR2GRAY);
	
    

	imshow("orjinal", img);
   
    createTrackbar("Türev","orjinal",&trackval,255,track);

	waitKey(0);




}

int main(){

    Showimage();   




}
