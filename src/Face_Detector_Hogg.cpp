//============================================================================
// Name        : Face_Detector_Hogg.cpp
// Author      : Saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/video.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>

#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <dlib/opencv/cv_image.h>
#include <sstream>
#include <string.h>


//using namespace cv;
using namespace std;
using namespace dlib;

frontal_face_detector hogFaceDetector = get_frontal_face_detector();

int main(int argc, char** argv)
{
	cout<<"Capturing Video"<<endl ;
	int counter = 0;
	cv::VideoCapture cap("../OpenCv_test/input_video1.mp4");
	if(!cap.isOpened()){
		cout << "Error opening video stream or file" << endl;
		return -1;
	}
	int frame_num = cap.get(CV_CAP_PROP_FRAME_COUNT);
	//int total_frames = cap.get(CV_CAP_PROP_FRAME_COUNT);
	while(1){
		cv::Mat frame;
		cap >> frame;

		ostringstream str1 ;
		str1 << counter;
		string frameno = str1.str();

	// Convert OpenCV image format to Dlib's image format
		array2d<bgr_pixel> dlibFrame;
		assign_image(dlibFrame, cv_image<dlib::bgr_pixel>(frame));
	// Extract face co-0rdinates using Hog Detector
		std::vector<dlib::rectangle> faceRects = hogFaceDetector(dlibFrame);
		for ( size_t i = 0; i < faceRects.size(); i++ )
		{
		  int x1 = faceRects[i].left();
		  int y1 = faceRects[i].top();
		  int x2 = faceRects[i].right();
		  int y2 = faceRects[i].bottom();
		  cv::rectangle(frame, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0,255,0), 4,cv::LINE_8);
		}
		cv::putText(frame,"Frame-"+frameno,cv::Point(50,50),cv::FONT_HERSHEY_DUPLEX,1,cv::Scalar(0,0,255),2,false);
		cv::imshow("Face Detector Hog",frame);
		counter += 1;
		char c=(char)cv::waitKey(0);
		if(c==27)
		  break;
	}
	// When everything done, release the video capture object
	cap.release();

	// Closes all the frames
	cv::destroyAllWindows();

	return 0;
}
