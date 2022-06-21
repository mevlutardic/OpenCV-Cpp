#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;


Mat hsv,imthresh,im;

int iLowH = 0;
int iHighH = 179;

int iLowS = 0;
int iHighS = 255;

int iLowV = 0;
int iHighV = 255;

void track(int, void*) {

	cvtColor(im, hsv, COLOR_BGR2HSV);

	

	inRange(hsv, Scalar(iLowH, iLowS, iLowV),Scalar(iHighH, iHighS, iHighV), imthresh);

	erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	imshow("Control", imthresh);
}
int main()
{
	im = imread("/home/afaraarge/Masaüstü/video/24.frame.jpg");
	resize(im, im, Size(600, 600));

	imshow("Orjinal", im);

	namedWindow("Control", WINDOW_AUTOSIZE); //create a window called "Control")
	
	createTrackbar("LowH", "Control", &iLowH, 179, track); //Hue (0 - 179)
	createTrackbar("HighH", "Control", &iHighH, 179, track);

	createTrackbar("LowS", "Control", &iLowS, 255, track); //Saturation (0 - 255)
	createTrackbar("HighS", "Control", &iHighS, 255, track);

	createTrackbar("LowV", "Control", &iLowV, 255, track); //Value (0 - 255)
	createTrackbar("HighV", "Control", &iHighV, 255, track);

	waitKey(0);
	return 0;
}