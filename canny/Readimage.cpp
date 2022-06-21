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
    Mat gray,canny;
    
    cvtColor(img,gray,COLOR_BGR2GRAY);
	
    Canny(img,canny,500,200);

	imshow("orjinal", img);
    imshow("canny", canny);


	waitKey(0);




}

int main(){

    Showimage();   




}
