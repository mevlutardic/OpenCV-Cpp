#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    Mat img = imread(path);

    Mat newHigh,newLow;

    img.convertTo(newHigh,-1,1.6,0);//çıkış,tip değişimi 8bit kalması için -1 yapıldı, herbir pixeli çarpılacak katsayı, her pixele eklenen sayı

    img.convertTo(newLow,-1,0.2,0);
    
    cout<<img.size()<<endl;



    imshow("img",img);
    imshow("newHigh",newHigh);
    imshow("newLow",newLow);

    waitKey(0);
   
}


int main(){

    Showimage();   




}
