//
//  features.hpp
//  Project2
//
//  Created by Tarun Saxena on 2/5/23.
//
// HEADER FILE FOR FEATURES.CPP

#ifndef features_hpp
#define features_hpp
#include <opencv2/opencv.hpp>
#include <string>
#include <cstdio>
#include <stdio.h>

int sobelX3x3(cv::Mat &src, cv::Mat &dst);
int sobelY3x3(cv::Mat &src, cv::Mat &dst);
int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst);
int baseline(std::string target, std::string database, int numImages);
int histogramMatching(std::string target, std::string database, int numImages);
int multiHistogramMatching(std::string target, std::string target2, std::string database, int numImages);
int texture(std::string target, std::string target2, std::string database, int numImages);
int custom(std::string target, std::string target2, std::string database, int numImages);
// EXTENSIONS
int blue_bin(std::string target, std::string database, int numImages);
int sobeltexture(std::string target, std::string database, int numImages, int x);


#endif /* features_hpp */
