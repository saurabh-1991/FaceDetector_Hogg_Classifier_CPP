# Face Detection using Hogg Classifier
![imagename](https://www.pyimagesearch.com/wp-content/uploads/2021/02/dlib_face_detection_header.png)

This Script can be used to detect Faces using Hog Classifier algorithm.
## Description-
The dlib library provides two functions that can be used for face detection:

   1) HOG + Linear SVM: dlib.get_frontal_face_detector()
   2) MMOD CNN: dlib.cnn_face_detection_model_v1(modelPath)
   
The get_frontal_face_detector function does not accept any parameters. 
A call to it returns the pre-trained HOG + Linear SVM face detector included in the dlib library.
Dlib’s HOG + Linear SVM face detector is fast and efficient. By nature of how the Histogram of Oriented Gradients (HOG) descriptor works, 
it is not invariant to changes in rotation and viewing angle.

Install Dlib in Ubuntu - [DlibLink](https://learnopencv.com/install-dlib-on-ubuntu/)
Install OpenCV 4 Ubuntu - [OpenCv Installation](https://learnopencv.com/install-opencv-4-on-ubuntu-16-04/)
   
---------------------------------------------------------------------------------------------------------------------------------------------
## Dependancies-
Inputs - 1) Input Image or Video file
         2) OpenCv 4.0 or above
         3) Dlib (latest version)
         
Output - Detected Face on Image

Note - This script will read video and process it for Face Detection and display its output on 
       screen . It will not save or write image currently. Also It needs modification to read webcam
       video.
