#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int lenght=4;
double top,top1,top2;

Mat FilterMat(int lenght){

     unsigned short x [lenght][lenght];
    for (int i = 0; i <lenght;i++){
            for(int j = 0; j <lenght; j++){

                x[i][j] =1;
               
            }
    
            }

    Mat mymat(lenght,lenght,CV_16U,x);
    return mymat.clone();
}

float filter[7][7] = {
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1 }
};

int filterDimension = 7;



double toplam,toplam1,toplam2;
double k,l;

Mat orgImg;
Mat dst;

int main(int argc, char** argv)
{
	string path = "/home/afaraarge/Masaüstü/OpenCV C++/Resources/inci.jpg";
	 orgImg = imread(path);
	 Mat filterImg(orgImg.rows, orgImg.cols, CV_8UC3, Scalar(0, 0, 0));

	 namedWindow("Resim", WINDOW_AUTOSIZE);
	 namedWindow("HazırFonk", WINDOW_AUTOSIZE);
	 namedWindow("KendiFonk", WINDOW_AUTOSIZE);

	 l = filterDimension*filterDimension;
	 k = 1.0 /l;

	 for (int y = 0; y<orgImg.rows- filterDimension; y++) {
		 for (int x = 0; x < orgImg.cols - filterDimension; x++) {
			 for (int t = 0; t < filterDimension; t++) {
				 for (int f = 0; f < filterDimension; f++) {

						 toplam   = toplam  + orgImg.at<Vec3b>(y+t , x+f )[0] * filter[t][f] *k;
						 toplam1  = toplam1 + orgImg.at<Vec3b>(y+t , x+f )[1] * filter[t][f] *k;
						 toplam2  = toplam2 + orgImg.at<Vec3b>(y+t , x+f )[2] * filter[t][f] *k;
					
				 }
			 }

			 filterImg.at<Vec3b>(y, x)[0] = toplam;
			 filterImg.at<Vec3b>(y, x)[1] = toplam1;
			 filterImg.at<Vec3b>(y, x)[2] = toplam2;
			 toplam = 0;
			 toplam1 = 0;
			 toplam2 = 0;
		 }	 
	}
	 blur(orgImg, dst, Size(7, 7), Point(-1, -1));


	 imshow("Resim", orgImg);
	 imshow("HazırFonk", dst);
	 imshow("KendiFonk", filterImg);

    waitKey(0);
	return 0;

}