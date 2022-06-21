#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

Mat img ;
int counter=0;
Point XY ;
Point p1;
Point p2;
void mouse(int event, int x,int y, int flag, void* userdata){
    
    if (event==EVENT_MOUSEMOVE)
    {
    

        XY =  Point(x,y);
        
        //cout<<"BGR : ["<<B<<","<<G<<","<<R<<"]"<<endl;
        cout<<" Points: "<<XY<<endl;

        
        line(img,p1,p2,Scalar(0,0,255),2,8,0);
        imshow("window",img);
    
 

    }
    // else if(event==EVENT_RBUTTONDOWN)
    // {
    //     cout<<"sag"<<endl;
    // }


    // else if(event==EVENT_MBUTTONDOWN)
    // {
    //     cout<<"orta"<<endl;
    // }

    else if(event==EVENT_LBUTTONDOWN)
    {
        
        counter++;
        if (counter==1){

            p1 = XY;
            cout<<" Baslangıç : "<< p1<<endl;      


        }

        else if(counter==2){
            cout<<" Bitis     : "<< p2<<endl; 
            p2 = XY;     

           
           

            
            counter=0;

        }

 

        

    }   

    
    
        
        

    

}

int main(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    img = imread(path);
    namedWindow("window",WINDOW_AUTOSIZE);
    
    setMouseCallback("window",mouse,NULL);

    imshow("window",img);
    waitKey(0);
    return 0;

}
