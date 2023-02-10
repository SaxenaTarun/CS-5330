//
//  main.cpp
//  Project2
//
//  Created by Tarun Saxena on 2/5/23.
//
// PROJECT - 2
// CONTENT-BASED IMAGE RETRIEVAL
// MAIN FUNCTION FOR CALLING ALL THE TASKS WITH feature feature_type IN THE COMMAND LINE


#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <cstdio>
#include "features.hpp"


using namespace cv;

int main(int argc, char *argv[])
{
    //comes in order of target, database, feature type, matching method, num of images
    std::string target = argv[1];
    std::string database = argv[2];
    std::string featureType = argv[3];
    std::string matchingMethod = argv[4];
    int numImages = atoi(argv[5]);
    cv::Mat img;
// TASK - 2 = BASELINE MATCHING
    if (matchingMethod == "baseline")
    {
        baseline(target, database, numImages);
    }
// TASK - 2 = HISTOGRAM MATCHING
    else if (matchingMethod == "histogram")
        {
            histogramMatching(target, database, numImages);
        }
// TASK - 3 = MULTI-HISTOGRAM MATCHING
    else if (matchingMethod == "multihistogram")
        {
            std::string target2 = "pic.0274.jpg";
            multiHistogramMatching(target, target2, database, numImages);
        }
// TASK - 4 = TEXTURE AND COLOR
    else if (matchingMethod == "texture")
        {
            std::string targetTexture = "pic.0535.jpg";
            texture(target, targetTexture, database, numImages);
        }
// TASK - 5 = CUSTOM DESIGN
    else if (matchingMethod == "custom")
        {
            //first image = pic.0.0747; second image below = pic.0.0748
            std::string target2 = "pic.0748.jpg";
            custom(target, target2, database, numImages);
        }
// EXTENSIONS
    else if (matchingMethod == "bluebin")
        {
            blue_bin(target, database, numImages);
        }
    else if (matchingMethod == "xsobeltexture")
        {
            int x = 0;
            sobeltexture(target, database, numImages, x);
        }
    else if (matchingMethod == "ysobeltexture") 
        {
            int x = 1;
            sobeltexture(target, database, numImages, x);
        }

    return 0;
}
