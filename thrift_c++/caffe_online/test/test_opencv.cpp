#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{
 if(argc != 2)
 {
   printf("useage: %s <imagefile>\n ", argv[0]);
   return -1;
 }
 char* imageName = argv[1];

 Mat image;
 printf("read from %s\n", imageName);
 //image = imread( imageName, CV_LOAD_IMAGE_COLOR);
 image = cvLoadImage(imageName,CV_LOAD_IMAGE_COLOR);
 if( !image.data )
 {
   printf( "error, No image data read \n " );
   return -1;
 }

 Mat gray_image;
 cvtColor( image, gray_image, CV_BGR2GRAY );
 imwrite( "Gray_Image.jpg", gray_image );

 return 0;
}
