//
//  filters.hpp
//  Project1
//
//  Created by Tarun Saxena on 1/22/23.
//

#ifndef filters_hpp
#define filters_hpp

#include <stdio.h>
#include <opencv2/core.hpp>

int greyscale(cv::Mat &src, cv::Mat &dst);
int gaus( cv::Mat &src, cv::Mat &dst );
int sobelX3x3( cv::Mat &src, cv::Mat &dst );
int sobelY3x3( cv::Mat &src, cv::Mat &dst );
int magnitude( cv::Mat &sx, cv::Mat &sy, cv::Mat &dst );
int blurQuantize( cv::Mat &src, cv::Mat &dst, int levels );
int cartoon( cv::Mat &src, cv::Mat&dst, int levels, int magThreshold );
int Negative(cv::Mat &src, cv::Mat &dst);

//extensions

int pencilSketch(cv::Mat &src, cv::Mat &dst);
int Canny(cv::Mat &src, cv::Mat &dst, int a, int b);
int Sepia(cv::Mat &src, cv::Mat &dst);




#endif /* filters_hpp */
