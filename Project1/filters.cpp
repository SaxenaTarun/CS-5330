//
//  filters.cpp
//  Project1
//
//  Created by Tarun Saxena on 1/22/23.
//


#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <iostream>

int greyscale( cv::Mat &src, cv::Mat &dst) {
    dst.create(src.size(), CV_8UC1);
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            dst.at<uchar>(i, j) = (src.at<cv::Vec3b>(i, j)[0] + src.at<cv::Vec3b>(i, j)[1] + src.at<cv::Vec3b>(i, j)[2]) / 3;
        }
    }
    return 0;
}

int gaus( cv::Mat &src, cv::Mat &dst) {
    cv::Mat temp;
    temp.create(src.size(), src.type());
    dst.create(src.size(), src.type());
    cv::Vec3i result = {0, 0, 0};
    cv::Vec3i resultCol = {0, 0, 0};
    
    // 5x1 filter --> [1 2 4 2 1] horizontal
    for (int i = 2; i < src.rows-2; i++) {
        for (int j = 2; j < src.cols-2; j++){
            for (int c = 0; c < 3; c++) {
                result[c] = src.at<cv::Vec3b>(i-2, j-2)[c]*0.1 + src.at<cv::Vec3b>(i-2, j-1)[c]*0.2
                + src.at<cv::Vec3b>(i-2, j)[c]*0.4 + src.at<cv::Vec3b>(i-2, j+1)[c]*0.2
                + src.at<cv::Vec3b>(i-2, j+2)[c]*0.1;
            }
            temp.at<cv::Vec3b>(i,j) = result;
        }
    }

    // 1x5 filter --> [1 2 4 2 1] vertical
    for (int i = 2; i < temp.rows-2; i++) {
        for (int j = 2; j < temp.cols-2; j++){
            for (int c = 0; c < 3; c++) {
                result[c] = temp.at<cv::Vec3b>(i-2, j-2)[c]*0.1 + temp.at<cv::Vec3b>(i-1, j-2)[c]*0.2
                + temp.at<cv::Vec3b>(i, j-2)[c]*0.4 + temp.at<cv::Vec3b>(i+1, j-2)[c]*0.2
                + temp.at<cv::Vec3b>(i+2, j-2)[c]*0.1;
            }
            dst.at<cv::Vec3b>(i,j) = result;
        }
    }
    return 0;
}
int sobelX3x3( cv::Mat &src, cv::Mat &dst ){
    //Multiply [-1 0 1] by
    //[1
    // 2
    // 1]

    cv::Mat temp;
    temp.create(src.size(), CV_16SC3);
    dst.create(src.size(), CV_16SC3);
    cv::Vec3s result= {0, 0, 0};

    // 3x1 filter
    for (int i = 1; i < src.rows-1; i++) {
        for (int j = 1; j < src.cols-1; j++){
            for (int c = 0; c < 3; c++) {
                result[c] = src.at<cv::Vec3b>(i-1, j-1)[c]*-1 + src.at<cv::Vec3b>(i-1, j)[c]*0 + src.at<cv::Vec3b>(i-1, j+1)[c];
            }
            temp.at<cv::Vec3s>(i,j) = result;
        }
    }

    // 1x3 filter
    for (int i = 1; i < temp.rows-1; i++) {
        for (int j = 1; j < temp.cols-1; j++){
            for (int c = 0; c < 3; c++) {
                result[c] = temp.at<cv::Vec3s>(i-1, j-1)[c] + temp.at<cv::Vec3s>(i, j-1)[c]*2 + temp.at<cv::Vec3s>(i+1, j-1)[c] ;
                result[c] /= 4;
            }
            dst.at<cv::Vec3s>(i,j) = result;
        }
    }
    return 0;
}
int sobelY3x3( cv::Mat &src, cv::Mat &dst ){
    //Multiply [1 2 1] by
    //[1
    // 0
    //-1]
    
    cv::Mat temp;
    temp.create(src.size(), CV_16SC3);
    dst.create(src.size(), CV_16SC3);
    cv::Vec3s result = {0, 0, 0};
 
    // 3x1 filter
    for (int i = 1; i < src.rows-1; i++) {
        for (int j = 1; j < src.cols-1; j++){
            for (int c = 0; c < 3; c++) {
                result[c] = src.at<cv::Vec3b>(i-1, j-1)[c] + src.at<cv::Vec3b>(i-1, j)[c]*2
                + src.at<cv::Vec3b>(i-1, j+1)[c];
            
                result[c] /= 4;
            }
            temp.at<cv::Vec3s>(i,j) = result;
        }
    }

    // 1x3 filter
    for (int i = 1; i < temp.rows-1; i++) {
        for (int j = 1; j < temp.cols-1; j++){
            for (int c = 0; c < 3; c++) {
                result[c] = temp.at<cv::Vec3s>(i-1, j-1)[c] + temp.at<cv::Vec3s>(i, j-1)[c]*0
                + temp.at<cv::Vec3s>(i+1, j-1)[c]*-1 ;
            }
            dst.at<cv::Vec3s>(i,j) = result;
        }
    }
    return 0;
}

int magnitude( cv::Mat &sx, cv::Mat &sy, cv::Mat &dst ){

    dst.create(sx.size(), sx.type());
    cv::Vec3s result = {0, 0, 0};
    for (int i = 0; i < sx.rows; i++) {
        for (int j = 0; j < sx.cols; j++){
  
            for (int c = 0; c < 3; c++) {
   
                result[c] = sqrt(pow(sx.at<cv::Vec3s>(i, j)[c], 2) + pow(sy.at<cv::Vec3s>(i, j)[c], 2));
            }
            dst.at<cv::Vec3s>(i,j) = result;
        }
    }
    return 0;
}

int blurQuantize( cv::Mat &src, cv::Mat &dst, int levels ){
    
    cv::Mat temp;
    temp.create(src.size(), src.type());
    dst.create(src.size(), src.type());
    cv::Vec3i result = {0, 0, 0};
    
    gaus(src, temp);
    int b = 255 / levels;
    for (int i = 0; i < temp.rows; i++) {
        for (int j = 0; j < temp.cols; j++){
            for (int c = 0; c < 3; c++) {
                result[c] = temp.at<cv::Vec3b>(i, j)[c] / b;
                result[c] = result[c] * b;
            }
            dst.at<cv::Vec3b>(i,j) = result;
        }
    }
    return 0;
}

int cartoon( cv::Mat &src, cv::Mat&dst, int levels, int magThreshold ) {

    cv::Mat xPic;
    xPic.create(src.size(), CV_16SC3);
    cv::Mat yPic;
    yPic.create(src.size(), CV_16SC3);
    cv::Mat magImg;
    magImg.create(src.size(), CV_16SC3);
    cv::Mat temp;
    temp.create(src.size(), src.type());
    dst.create(src.size(), CV_16SC3);
    sobelX3x3(src, xPic);
    sobelY3x3(src, yPic);
    magnitude(xPic, yPic, magImg);
    blurQuantize(src, temp, levels);
    
    cv::Vec3s result = {0, 0, 0};
    cv::Vec3s thresh = {0, 0, 0};
    

    for (int i = 0; i < temp.rows; i++) {
        for (int j = 0; j < temp.cols; j++){
            for (int c = 0; c < 3; c++) {

                result[c] = temp.at<cv::Vec3b>(i, j)[c];
                thresh[c] = magImg.at<cv::Vec3s>(i, j)[c];
            }
        
            int avg = (thresh[0] + thresh[1] + thresh[2])/3;
           
            if (avg > magThreshold) {
                result = {0,0,0};
            }

            dst.at<cv::Vec3s>(i,j) = result;
        }
    }
    
    return 0;
}

int pencilSketch(cv::Mat &src, cv::Mat &dst)
{
    greyscale(src, dst);
    gaus(dst, dst);
    Laplacian(dst, dst, -1, 5);
    dst = 255 - dst;
    threshold(dst, dst, 150, 255, cv::THRESH_BINARY);
    return 0;
}

int Canny(cv::Mat &src, cv::Mat &dst, int a, int b){
    greyscale(src, dst);
    cv::Canny(dst, dst, a, b);
    return 0;
    
}

int Negative(cv::Mat &src, cv::Mat &dst){
    dst = 255 -src;
    return 0;
    
}

int Sepia(cv::Mat &src, cv::Mat &dst){
    cv::cvtColor(src, dst, cv::COLOR_BGR2RGB);
    cv::transform(dst,dst,cv::Matx33f(0.393,0.769,0.189,0.349,0.686,0.168,0.272,0.534,0.131));
    cv::cvtColor(dst,dst,cv::COLOR_RGB2BGR);
    return 0;
    
}
