#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;


Mat Cont ;

void convert(Mat input, Mat output, int derinlik , float alpha, float beta)
{//-1 üç kanallı 1 tek kanallı gri resim

    if (derinlik==-1){
        for (int i = 0; i < input.rows; i++){

            for (int j = 0; j < input.cols; j++)
            {
            
                if(input.at<Vec3b>(i,j)[0]*alpha+beta>255){input.at<Vec3b>(i,j)[0]=255;}
                else if(input.at<Vec3b>(i,j)[0]*alpha+beta<0){input.at<Vec3b>(i,j)[0]=0;}
                else{input.at<Vec3b>(i,j)[0]=input.at<Vec3b>(i,j)[0]*alpha+beta;}

                if(input.at<Vec3b>(i,j)[1]*alpha>255){input.at<Vec3b>(i,j)[1]=255;}
                else if(input.at<Vec3b>(i,j)[1]*alpha+beta<0){input.at<Vec3b>(i,j)[1]=0;}
                else{input.at<Vec3b>(i,j)[1]=input.at<Vec3b>(i,j)[1]*alpha+beta;}

                if(input.at<Vec3b>(i,j)[2]*alpha>255){input.at<Vec3b>(i,j)[2]=255;}
                else if(input.at<Vec3b>(i,j)[2]*alpha+beta<0){input.at<Vec3b>(i,j)[2]=0;}
                else{input.at<Vec3b>(i,j)[2]=input.at<Vec3b>(i,j)[2]*alpha+beta;}
            
            }
            
        }
    }

    else if (derinlik==1)
    {

        cvtColor(input,input,COLOR_BGR2GRAY);

        for (int i = 0; i < input.rows; i++){

                for (int j = 0; j < input.cols; j++)
                {
                
                    if(input.at<uchar>(i,j)*alpha+beta>255){input.at<uchar>(i,j)=255;}
                    else if(input.at<uchar>(i,j)*alpha+beta<0){input.at<uchar>(i,j)=0;}
                    else{input.at<uchar>(i,j)=input.at<uchar>(i,j)*alpha+beta;}

                
                }
                
        }
    }

    Cont=input;
    
}


void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    Mat img = imread(path);
    imshow("orj",img);
    
    convert(img,Cont,-1,1.0,100);
 
    imshow("resim",Cont);

    // convert(img,Cont,1,0.5);
 
    // imshow("gri",Cont);
    

    waitKey(0);
   
}


int main(){

    Showimage();   




}
