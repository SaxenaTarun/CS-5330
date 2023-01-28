//
//  imgDisplay.cpp
//  Project1
//
//  Created by Tarun Saxena on 1/22/23.
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace std;

int main(int argc, char *argv[]) {
    
    // read image
    
    std::string img_path = cv::samples::findFile("/Users/tarun/Downloads/19A72FC2-A4C2-4D29-B9EB-7A37462C02F6.jpeg");
    cv:: Mat img = imread(img_path, cv::IMREAD_COLOR);
    
    
    // check if file exists
    
    if(img.empty())
    {
        cout << "NO IMAGE !!";
        return 1;
    }
    
    // name window for dispay
    
    cv::namedWindow("Image-1", cv::WINDOW_NORMAL);
    
    imshow("Image-1", img);
    
    // Adding Key Press functionality
    
    while (true) {
            char key = cv::waitKey(10);
            // quit the window
            if (key == 'q') {
                break;
            }
            // resize the window
            if(key == 'z')
            {
                cv::resizeWindow("Image-1", 600, 600);
                imshow("Image Display", img);
            }
                }

        cv::destroyAllWindows();
    
    return 0;
    
    
    
}
