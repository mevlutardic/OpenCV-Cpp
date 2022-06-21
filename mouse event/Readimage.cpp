#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

Mat img;
void mouse(int event, int x,int y, int flag, void* userdata){

    if (event==EVENT_MOUSEMOVE)
    {
        
        int B=img.at<Vec3b>(y,x)[0];
        int G=img.at<Vec3b>(y,x)[1];
        int R=img.at<Vec3b>(y,x)[2];
        int C=img.at<Vec3b>(y,x)[3];

        Scalar BGR = Scalar(B,G,R,C);
        Point XY =  Point(x,y);
        
        //cout<<"BGR : ["<<B<<","<<G<<","<<R<<"]"<<endl;
        cout<<"BGR : "<<BGR<<"   Points: "<<XY<<endl;

    }
    // else if(event==EVENT_RBUTTONDOWN)
    // {
    //     cout<<"sag"<<endl;
    // }


    // else if(event==EVENT_MBUTTONDOWN)
    // {
    //     cout<<"orta"<<endl;
    // }

    // else if(event==EVENT_LBUTTONDOWN)
    // {
    //     cout<<"sol"<<endl;
    // }

}

int main(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    img = imread(path);
    namedWindow("window",WINDOW_AUTOSIZE);
    
    setMouseCallback("window",mouse,NULL);

    imshow("window",img);
    waitKey(0);


}
