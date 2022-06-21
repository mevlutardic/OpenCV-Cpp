#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Line(Mat input,Point P1,Point P2,Scalar scalar,int kalinlik){

  
   for (int i = P1.x; i < P2.x; i++)
   {
       for (int j = P1.y; j < P1.y+kalinlik; j++)
       {
           input.at<Vec3b>(j,i)[0]=scalar[2];
           input.at<Vec3b>(j,i)[1]=scalar[2];
           input.at<Vec3b>(j,i)[2]=scalar[2];
           
       }
       
   }
   
   
}




int main(){

    Point p1= Point(50,125);
    Point p2= Point(123,50);

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    Mat img = imread(path);
    

    
    Line(img,p1,p2,Scalar(0,0,255),12);   

    imshow("image",img);
    waitKey(0);


}
