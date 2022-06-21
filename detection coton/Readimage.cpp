#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;


class CaptureVideo{

	private:
		string Path;
		
	public:
		Mat frame;
		
    	
    Mat img;
		CaptureVideo(){
			this->Path="";
		}
		CaptureVideo(string):Path(Path){}

		void Run(){
			VideoCapture cap(Path);





		}
};

int main(){
string path = "/home/afaraarge/Masaüstü/video/video_2.mp4";
CaptureVideo Cap(path);

while (true){




}



	return 0;
}

























Mat hsv, imthresh, im;
Mat video;


int iLowH = 0;
int iHighH = 179;

int iLowS = 0;
int iHighS = 34;

int iLowV = 109;
int iHighV = 255;


void track(int, void*) {
	
	cvtColor(video, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imthresh);

	erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
	dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));

	dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
	erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));

	vector<vector<Point> > contours;
	vector<Vec4i>hierarchy;

	findContours(imthresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<Moments> mu(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i]);
	}
	vector<Point2f> mc(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
	    float mcenterx = mu[i].m10 / mu[i].m00;
		float mcentery = mu[i].m01 / mu[i].m00;
		mc[i] = Point2f((mcenterx), (mcentery));

		circle(video,Point(mcenterx,mcentery),3,Scalar(0,0,255),3,LINE_AA,0);
	}
	imshow("Renk", imthresh);
}

int main()
{
	
	VideoCapture vid("/home/afaraarge/Masaüstü/video/video_1.mp4");
	

	namedWindow("Control", WINDOW_AUTOSIZE); 

	createTrackbar("LowH", "Control", &iLowH, 255, track);
	createTrackbar("HighH", "Control", &iHighH, 255, track);

	createTrackbar("LowS", "Control", &iLowS, 255, track); 
	createTrackbar("HighS", "Control", &iHighS, 255, track);

	createTrackbar("LowV", "Control", &iLowV, 255, track);
	createTrackbar("HighV", "Control", &iHighV, 255, track);

	while (true) {

		vid.read(video);
		resize(video, video, Size(600, 600));

		imshow("Video", video);


		waitKey(100);

		if (waitKey(30) == 27) break;
	}
	
	return 0;
}