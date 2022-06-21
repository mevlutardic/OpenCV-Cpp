#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;




void Showimage(){

    string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
    
    Mat img=imread(path);
    
   
	Mat dst,dst1;

	bilateralFilter(img, dst, 10, 50, 50);
        GaussianBlur(img, dst1, Size(7,7), 1);

	imshow("orjinal", img);
	imshow("Bilateral", dst);
        imshow("Gauss", dst1);

	waitKey(0);




}

int main(){

    Showimage();   




}
