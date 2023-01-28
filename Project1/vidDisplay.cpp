//
//  vidDisplay.cpp
//  Project1
//
//  Created by Tarun Saxena on 1/22/23.
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "filters.cpp"
#include "filters.hpp"
#include "imgproc.hpp"


using namespace std;

int main() {
        cv::VideoCapture *capdev;

        // open the video device
        capdev = new cv::VideoCapture(0);
        if( !capdev->isOpened() ) {
                printf("Unable to open video device\n");
                return(-1);
        }

        // get some properties of the image
        cv::Size refS( (int) capdev->get(cv::CAP_PROP_FRAME_WIDTH ),
                       (int) capdev->get(cv::CAP_PROP_FRAME_HEIGHT));
        printf("Expected size: %d %d\n", refS.width, refS.height);

        cv::namedWindow("Video", 1); // identifies a window
        cv::Mat frame, filter, sobxfilter, sobyfilter;
        int count=-1;

        for(;;) {
                *capdev >> frame; // get a new frame from the camera, treat as a stream
                // If the frame is empty quit
                if( frame.empty() ) {
                  printf("frame is empty\n");
                  break;
                }
            
                // see if there is a waiting keystroke
                char key = cv::waitKey(10);
                // show original frame
                if( key == 'r') {
                    
                    cv::imshow("Original", frame);
                    filter=frame;
                }
                // quit the screen
                else if( key == 'q') {
                    break;
                }
                // save frame
                else if( key == 's') {
                    ++count;
                    cv::imwrite("/Users/tarun/MSAI/CS 5330/Project1/Project1/Images/original_"+to_string(count)+".jpeg", filter);
                }
                // applying greyscale filter
                else if( key == 'g'){
                    cv::cvtColor(frame, filter, cv::COLOR_RGBA2GRAY);
                    printf("Greyscale_Video");
                    cv::imshow("Greyscale_Video", filter);
                }
                // applying customised greyscale filter
                else if(key == 'h'){
                    greyscale(frame, filter);
                    printf("Alternate_Greyscale_Video");
                    cv::imshow("Alternate_Greyscale_Video", filter);
                // applying gausian blur
                }
                else if( key == 'b'){
                    gaus(frame, filter);
                    printf("Blurred_Video");
                    cv::imshow("Blurred_Video", filter);
                }
                // applying sobel x filter
                else if( key == 'x'){
                    sobelX3x3(frame, filter);
                    printf("SobelX_Video");
                    cv::convertScaleAbs( filter, frame );
                    cv::imshow("SobelX_Video", filter);
                }
                // applying sobel y filter
                else if( key == 'y'){
                    sobelY3x3(frame, filter);
                    printf("SobelY_Video");
                    cv::convertScaleAbs( filter, frame );
                    cv::imshow("SobelY_Video", filter);
                }
                // applying gradient magnitude filter
                else if (key == 'm') {
                    sobelX3x3(frame, sobxfilter);
                    sobelY3x3(frame, sobyfilter);
                    magnitude(sobxfilter, sobyfilter, filter);
                    cv::convertScaleAbs( filter, frame );
                    cv::imshow("Gradient_Magnitude_Video", filter);
                }
                // applying blur quantize filter
                else if (key == 'l') {
                    blurQuantize(frame, filter, 15);
                    cv::imshow("Blur_Quantize_Video", filter);
                }
                // applying cartoon filter
                else if (key == 'c') {
                    cartoon(frame, filter, 15, 15);
                    cv::imshow("Cartoon_Video", filter);
                }
                // converting to negative
                else if (key == 'n') {
                    Negative(frame, filter);
                    cv::imshow("Negative", filter);
                }
                // increasing brightness
                else if (key == '1') {
                    filter = frame + cv::Scalar(100, 100, 100);
                    cv::imshow("Bright", filter);
                }
                // decreasing brightness
                else if (key == '2') {
                    filter = frame - cv::Scalar(100, 100, 100);
                    cv::imshow("Dim", filter);
                }
                // EXTENSIONS
                // applying pencil sketch filter
                else if (key == 'p') {
                    pencilSketch(frame, filter);
                    cv::imshow("Pencil_Sketch", filter);
                }
                // applying canny edge filter
                else if (key == 'e') {
                    Canny(frame, filter, 80, 160);
                    cv::imshow("Canny_Video", filter);
                }
                // applying text on frame
                else if (key == 't'){
                    string caption;
                    printf("Write Caption on Terminal:");
                    getline(cin, caption);
                    cv::putText(frame, caption, cv::Point(20, frame.rows / 2), cv::FONT_HERSHEY_COMPLEX_SMALL, 4.0, CV_RGB(255, 0, 0));
                    cv::imshow("Text", frame);
                }
                // applying sepia filter
                else if (key == 'o') {
                    Sepia(frame, filter);
                    cv::imshow("Sepia_Video", filter);
                }


                // display frame
//                cv::imshow("Video", frame);

        }

        delete capdev;
        return(0);
}
