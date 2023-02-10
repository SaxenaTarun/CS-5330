//
//  features.cpp
//  Project2
//
//  Created by Tarun Saxena on 2/5/23.
//
// FEATURE FILE INCLUDES THE VARIOUS TASKS FUNCTIONS CALLED IN MAIN.CPP

#include "features.hpp"
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <cstdio>
#include <map>

using namespace cv;

//gets the cv mat object of the image
cv::Mat getImage(std::string photo, std::string database)
{
    std::string photoPath = "/Users/tarun/MSAI/CS5330/Project2/" + database + "/" + photo;
    cv::Mat image = imread(photoPath, IMREAD_COLOR);
    return image;
}

//gets the image path manually
std::string getImagePath(std::string photo, int picNum)
{
    std::string secondImage;
    if (picNum < 10)
    {
        secondImage = "pic.000" + std::to_string(picNum) + ".jpg";
    }
    else if (picNum == 420)
    {
        secondImage = "pic.0021.jpg";
    }
    else if (picNum >= 10 && picNum < 100)
    {
        secondImage = "pic.00" + std::to_string(picNum) + ".jpg";
    }
    else if (picNum >= 100 && picNum < 1000)
    {
        secondImage = "pic.0" + std::to_string(picNum) + ".jpg";
    }
    else if (picNum >= 1000)
    {
        secondImage = "pic." + std::to_string(picNum) + ".jpg";
    }
    return secondImage;
}

//prints the top 3 matches
int printTopMatches(std::string arrOfSumsTotal[][2], int numImages, std::string topNum)
{
    //sort the array by the total numbers
    std::string cl1[2] = {topNum, "0"};
    std::string cl2[2] = {topNum, "0"};
    std::string cl3[2] = {topNum, "0"};

    for (int z = 1; z < numImages; z++)
    {

        int currentNum;
        currentNum = stoi(arrOfSumsTotal[z][0]);
        if (currentNum == 0)
        {
            continue;
        }
        if (currentNum < stoi(cl1[0]))
        {
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set first to second
            cl2[0] = cl1[0];
            cl2[1] = cl1[1];
            //set the new one equal to first place
            cl1[0] = arrOfSumsTotal[z][0];
            cl1[1] = arrOfSumsTotal[z][1];
        }
        else if (currentNum < stoi(cl2[0]))
        {
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set the new one equal to first place
            cl2[0] = arrOfSumsTotal[z][0];
            cl2[1] = arrOfSumsTotal[z][1];
        }
        else if (currentNum < stoi(cl3[0]))
        {
            //set the new one equal to first place
            cl3[0] = arrOfSumsTotal[z][0];
            cl3[1] = arrOfSumsTotal[z][1];
        }
    }
    std::cout << "\nTop similar photos: " << std::endl;
    std::string s1 = "\n1: " + cl1[1] + " has value of " + cl1[0];
    std::string s2 = "2: " + cl2[1] + " has value of " + cl2[0];
    std::string s3 = "3: " + cl3[1] + " has value of " + cl3[0] + "\n";
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    return 0;
}

//prints the top 10 matches
int printTopMatchesHist(std::string arr[][2], int numImages, std::string topNum)
{

    //sort the array by the total numbers
    std::string cl1[2] = {topNum, "0"};
    std::string cl2[2] = {topNum, "0"};
    std::string cl3[2] = {topNum, "0"};
    std::string cl4[2] = {topNum, "0"};
    std::string cl5[2] = {topNum, "0"};
    std::string cl6[2] = {topNum, "0"};
    std::string cl7[2] = {topNum, "0"};
    std::string cl8[2] = {topNum, "0"};
    std::string cl9[2] = {topNum, "0"};
    std::string cl10[2] = {topNum, "0"};

    for (int z = 1; z < numImages; z++)
    {

        //std::cout << arr[z][0];
        //std::cout << z << std::endl;
        float currentNum;
        currentNum = stof(arr[z][0]);

        if (currentNum == 0)
        {
            continue;
        }
        //SETTING TO FIRST PLACE
        else if (currentNum < stof(cl1[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 3rd to fourth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set 3rd to fourth
            cl4[0] = cl3[0];
            cl4[1] = cl3[1];
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set first to second
            cl2[0] = cl1[0];
            cl2[1] = cl1[1];
            //set the new one equal to first place
            cl1[0] = arr[z][0];
            cl1[1] = arr[z][1];
            continue;
        }
        //SETTING TO 2ND PLACE
        else if (currentNum < stof(cl2[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 4th to fifth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set 3rd to fourth
            cl4[0] = cl3[0];
            cl4[1] = cl3[1];
            //set 2nd to third
            cl3[0] = cl2[0];
            cl3[1] = cl2[1];
            //set the new one equal to second place
            cl2[0] = arr[z][0];
            cl2[1] = arr[z][1];
            continue;
        }
        //SETTING TO 3RD PLACE
        else if (currentNum < stof(cl3[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 4th to fifth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set 3rd to fourth
            cl4[0] = cl3[0];
            cl4[1] = cl3[1];

            //set the new one equal to third place
            cl3[0] = arr[z][0];
            cl3[1] = arr[z][1];
            continue;
        }

        //SETTING TO 4TH PLACE
        else if (currentNum < stof(cl4[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set 4th to fifth
            cl5[0] = cl4[0];
            cl5[1] = cl4[1];
            //set the new one equal to third place
            cl4[0] = arr[z][0];
            cl4[1] = arr[z][1];
        }
        //SETTING TO 5TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set 5th to 6
            cl6[0] = cl5[0];
            cl6[1] = cl5[1];
            //set the new one equal to third place
            cl5[0] = arr[z][0];
            cl5[1] = arr[z][1];
        }
        // SETTING TO 6TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set 6 to 7th
            cl7[0] = cl6[0];
            cl7[1] = cl6[1];
            //set the new one equal to third place
            cl6[0] = arr[z][0];
            cl6[1] = arr[z][1];
        }
        // SETTING TO 7TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set 7 to 8th
            cl8[0] = cl7[0];
            cl8[1] = cl7[1];
            //set the new one equal to third place
            cl7[0] = arr[z][0];
            cl7[1] = arr[z][1];
        }
        // SETTING TO 8TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];
            //set 8 to 9th
            cl9[0] = cl8[0];
            cl9[1] = cl8[1];
            //set the new one equal to third place
            cl8[0] = arr[z][0];
            cl8[1] = arr[z][1];
        }
        // SETTING TO 9TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set 9 to 10th
            cl10[0] = cl9[0];
            cl10[1] = cl9[1];

            //set the new one equal to third place
            cl9[0] = arr[z][0];
            cl9[1] = arr[z][1];
        }
        // SETTING TO 10TH PLACE
        else if (currentNum < stof(cl5[0]))
        {
            //set the new one equal to third place
            cl10[0] = arr[z][0];
            cl10[1] = arr[z][1];
        }
    }
    std::cout << "\nTop similar photos: " << std::endl;
    std::string s1 = "\n1: " + cl1[1] + " has a value of " + cl1[0];
    std::string s2 = "2: " + cl2[1] + " has a value of " + cl2[0];
    std::string s3 = "3: " + cl3[1] + " has a value of " + cl3[0];
    std::string s4 = "4: " + cl4[1] + " has a value of " + cl4[0];
    std::string s5 = "5: " + cl5[1] + " has a value of " + cl5[0] + "\n";
    std::string s6 = "6: " + cl6[1] + " has a value of " + cl6[0];
    std::string s7 = "7: " + cl7[1] + " has a value of " + cl7[0];
    std::string s8 = "8: " + cl8[1] + " has a value of " + cl8[0];
    std::string s9 = "9: " + cl9[1] + " has a value of " + cl9[0];
    std::string s10 = "10: " + cl10[1] + " has a value of " + cl10[0] + "\n";

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;
    std::cout << s6 << std::endl;
    std::cout << s7 << std::endl;
    std::cout << s8 << std::endl;
    std::cout << s9 << std::endl;
    std::cout << s10 << std::endl;
    return 0;
}
// FROM FIRST PROJECT
int blur5x5(const cv::Mat &src, cv::Mat &dst){
    cv::Mat tmp;
    tmp.create(src.size(), src.type());
    
    for(int i = 0; i < src.rows; i++){
        for(int j = 2; j < src.cols-2; j++){
            for(int c = 0; c < 3; c++){
                tmp.at<cv::Vec3b>(i,j)[c] = src.at<cv::Vec3b>(i,j-2)[c]*0.1 + src.at<cv::Vec3b>(i,j-1)[c]*0.2 +src.at<cv::Vec3b>(i,j)[c]*0.4 + src.at<cv::Vec3b>(i,j+1)[c]*0.2 + src.at<cv::Vec3b>(i,j+2)[c]*0.1;
            }
        }
    }

    for(int i = 2; i < src.rows-2; i++){
        for(int j = 0; j < src.cols; j++){
            for(int c = 0; c < 3; c++){
                dst.at<cv::Vec3b>(i,j)[c] = tmp.at<cv::Vec3b>(i-2,j)[c]*0.1 + tmp.at<cv::Vec3b>(i-1,j)[c]*0.2 +tmp.at<cv::Vec3b>(i,j)[c]*0.4 + tmp.at<cv::Vec3b>(i+1,j)[c]*0.2 + tmp.at<cv::Vec3b>(i+2,j)[c]*0.1;
            }
        }
    }
    return 0;
}

int blurQuantize( cv::Mat &src, cv::Mat &dst, int levels ){
    int b = 255 / levels;
    unsigned char x, xt, xf;

    cv::Mat tmp;
    src.copyTo(tmp);

    blur5x5(src, tmp);

    for(int i = 0; i < dst.rows; i++){
        for(int j = 0; j < dst.cols; j++){
            for(int c = 0; c < 3; c++){
                x = tmp.at<cv::Vec3b>(i,j)[c];
                xt = x / b;
                xf = xt * b;
                dst.at<cv::Vec3b>(i,j)[c] = xf;

            }
        }
    }
    return 0;

}
int sobelX3x3(cv::Mat &src, cv::Mat &dst)
{
    //sobel x should multiply [-1 0 1] by
    //[1
    // 2
    // 1]

    //create intermediate and dst objects with type CV_16SC3
    cv::Mat intermed;
    intermed.create(src.size(), CV_16SC3);
    dst.create(src.size(), CV_16SC3);

    //make our own initialized color channel
    //vec3s works for intermed and dst
    cv::Vec3s result = {0, 0, 0};

    //applying 3x1 filter
    for (int i = 1; i < src.rows - 1; i++)
    {
        for (int j = 1; j < src.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = src.at<cv::Vec3b>(i - 1, j - 1)[c] * -1 + src.at<cv::Vec3b>(i - 1, j)[c] * 0 + src.at<cv::Vec3b>(i - 1, j + 1)[c];
            }
            intermed.at<cv::Vec3s>(i, j) = result;
        }
    }

    //applying 1x3 filter
    for (int i = 1; i < intermed.rows - 1; i++)
    {
        for (int j = 1; j < intermed.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = intermed.at<cv::Vec3s>(i - 1, j - 1)[c] + intermed.at<cv::Vec3s>(i, j - 1)[c] * 2 + intermed.at<cv::Vec3s>(i + 1, j - 1)[c];
                result[c] /= 4;
            }
            dst.at<cv::Vec3s>(i, j) = result;
        }
    }
    return 0;
}

int sobelY3x3(cv::Mat &src, cv::Mat &dst)
{
    //sobel y should multiply [1 2 1] by
    //[1
    // 0
    //-1]

    cv::Mat intermed;
    intermed.create(src.size(), CV_16SC3);
    dst.create(src.size(), CV_16SC3);

    //make our own initialized color channel
    cv::Vec3s result = {0, 0, 0};

    //applying 3x1 filter
    for (int i = 1; i < src.rows - 1; i++)
    {
        for (int j = 1; j < src.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = src.at<cv::Vec3b>(i - 1, j - 1)[c] + src.at<cv::Vec3b>(i - 1, j)[c] * 2 + src.at<cv::Vec3b>(i - 1, j + 1)[c];

                result[c] /= 4;
            }
            intermed.at<cv::Vec3s>(i, j) = result;
        }
    }

    //applying 1x3 filter
    for (int i = 1; i < intermed.rows - 1; i++)
    {
        for (int j = 1; j < intermed.cols - 1; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                result[c] = intermed.at<cv::Vec3s>(i - 1, j - 1)[c] + intermed.at<cv::Vec3s>(i, j - 1)[c] * 0 + intermed.at<cv::Vec3s>(i + 1, j - 1)[c] * -1;
            }
            dst.at<cv::Vec3s>(i, j) = result;
        }
    }
    return 0;
}

int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst)
{

    dst.create(sx.size(), sx.type());

    //sx and sy come in as vec3s
    cv::Vec3s result = {0, 0, 0};

    //only need to go through one image since sy should be the same
    for (int i = 0; i < sx.rows; i++)
    {
        for (int j = 0; j < sx.cols; j++)
        {
            //go pixel by pixel for x and y
            for (int c = 0; c < 3; c++)
            {
                //find the euclidian distance with formula to find the new pixel values
                result[c] = sqrt(pow(sx.at<cv::Vec3s>(i, j)[c], 2) + pow(sy.at<cv::Vec3s>(i, j)[c], 2));
            }
            dst.at<cv::Vec3s>(i, j) = result;
        }
    }

    return 0;
}
//TASK 1: BASELINE
int baseline(std::string target, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    std::string arrOfSumsTotal[numImages][2];

    for (int p = 1; p < numImages; p++)
    {

        std::string secondImage;
        int picNum = 0 + p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);
        int sumSquaredDiff = 0;

        //loop over every pixel in the image and convert each RGB to an index
        for (int i = 252; i < 261; i++)
        {
            for (int j = 316; j < 325; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int diff = currentImage.at<cv::Vec3b>(i, j)[c] - targetImage.at<cv::Vec3b>(i, j)[c];
                    sumSquaredDiff = sumSquaredDiff + (diff * diff);
                }
            }
        }
        sumSquaredDiff /= 81;

        //put the answer into an array
        std::string arrOfSums[2] = {};
        arrOfSums[0] = std::to_string(sumSquaredDiff);
        arrOfSums[1] = secondImage;
        arrOfSumsTotal[p][0] = arrOfSums[0];
        arrOfSumsTotal[p][1] = arrOfSums[1];
    }

    printTopMatches(arrOfSumsTotal, numImages, "100000");
    return 0;
}

// TASK - 2 = HISTOGRAM MATCHING
int histogramMatching(std::string target, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //make an empty 3d RGB histogram
        cv::Mat hist3d;
        const int Hsize = 32;
        int dim3[3] = {Hsize, Hsize, Hsize};
        hist3d = cv::Mat::zeros(3, dim3, CV_32F);

        //for the compared image
        cv::Mat hist3dComp;
        int dim3c[3] = {Hsize, Hsize, Hsize};
        hist3dComp = cv::Mat::zeros(3, dim3c, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        cv::Vec3i comparedImage = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    //get each pixel for target image
                    //get each pixel for the compared image
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    comparedImage[c] = currentImage.at<cv::Vec3b>(i, j)[c];

                    //divide all by 29 so we only get values from 0 to 9
                    targetImagePix[c] /= 32;
                    comparedImage[c] /= 32;
                }

                //once out of the loop, increment BOTH histograms (target, and compared)
                hist3dComp.at<float>(comparedImage[0], comparedImage[1], comparedImage[2])++;

                //increment the indexes for r, g, b in the histogram
                hist3d.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
            }
        }

        float totalCompared = 0;
        float totalTarget = 0;
        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    totalCompared += std::min(hist3dComp.at<float>(l, m, n), hist3d.at<float>(l, m, n)) / 327680;
                    totalTarget += hist3d.at<float>(l, m, n) / 327680;
                }
            }
        }

        //make an array of values to keep track of distance metrics
        float diffBwImages = totalTarget - totalCompared;
        arrOfHistImages[p][0] = std::to_string(diffBwImages);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}

// TASK - 3 = MULTI-HISTOGRAM MATCHING
int multiHistogramMatching(std::string target, std::string target2, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        int picNum = p;
        std::string secondImage;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //make 4 histograms here: top and bottom for both target and current images
        cv::Mat targetTopHist;
        const int Hsize = 32;
        int dimtt[3] = {Hsize, Hsize, Hsize};
        targetTopHist = cv::Mat::zeros(3, dimtt, CV_32F);

        cv::Mat targetBottomHist;
        int dimtb[3] = {Hsize, Hsize, Hsize};
        targetBottomHist = cv::Mat::zeros(3, dimtb, CV_32F);

        cv::Mat currentTopHist;
        int dimct[3] = {Hsize, Hsize, Hsize};
        currentTopHist = cv::Mat::zeros(3, dimct, CV_32F);

        cv::Mat currentBottomHist;
        int dimcb[3] = {Hsize, Hsize, Hsize};
        currentBottomHist = cv::Mat::zeros(3, dimcb, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        cv::Vec3i currentImagePix = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    currentImagePix[c] = currentImage.at<cv::Vec3b>(i, j)[c];

                    //divide all by 32 so we only get values from 0 to 9
                    targetImagePix[c] /= 32;
                    currentImagePix[c] /= 32;
                }

                //if the pixel is in the top half, add respective pixels to the histograms for top half
                if (i < 256)
                {
                    currentTopHist.at<float>(currentImagePix[0], currentImagePix[1], currentImagePix[2])++;
                    targetTopHist.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
                }
                else if (i >= 256)
                {
                    currentBottomHist.at<float>(currentImagePix[0], currentImagePix[1], currentImagePix[2])++;
                    targetBottomHist.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
                }
            }
        }

        float totalTargetTop = 0;
        float totalTargetBottom = 0;
        float totalCurrentTop = 0;
        float totalCurrentBottom = 0;

        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    totalCurrentTop += std::min(targetTopHist.at<float>(l, m, n), currentTopHist.at<float>(l, m, n)) / 327680;
                    totalTargetTop += targetTopHist.at<float>(l, m, n) / 327680;

                    totalCurrentBottom += std::min(targetBottomHist.at<float>(l, m, n), currentBottomHist.at<float>(l, m, n)) / 327680;
                    totalTargetBottom += targetBottomHist.at<float>(l, m, n) / 327680;
                }
            }
        }

        //get the difference between the currentTop and targetTop
        float topDiff = totalTargetTop - totalCurrentTop;

        //get the difference between the currentBottom and targetBottom
        float botDiff = totalTargetBottom - totalCurrentBottom;

        //get the final distance between the images
        float diffBwImages = topDiff * 0.5 + botDiff * 0.5;

        arrOfHistImages[p][0] = std::to_string(diffBwImages); //+ diffBwImages2);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}
// TASK - 4 = TEXTURE AND COLOR
int texture(std::string target, std::string target2, std::string database, int numImages)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;

    //get the magnitude version of that image
    cv::Mat targetImageFilterX;
    cv::Mat targetImageFilterY;
    cv::Mat targetImageFilterNoAbs;
    cv::Mat targetImageFilter;
    sobelX3x3(targetImage, targetImageFilterX);
    sobelY3x3(targetImage, targetImageFilterY);
    magnitude(targetImageFilterX, targetImageFilterY, targetImageFilterNoAbs);
    cv::convertScaleAbs(targetImageFilterNoAbs, targetImageFilter);
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //get the magnitude version of the current image
        cv::Mat currentImageFilterX;
        cv::Mat currentImageFilterY;
        cv::Mat currentImageFilterNoAbs;
        cv::Mat currentImageFilter;
        sobelX3x3(currentImage, currentImageFilterX);
        sobelY3x3(currentImage, currentImageFilterY);
        magnitude(currentImageFilterX, currentImageFilterY, currentImageFilterNoAbs);
        cv::convertScaleAbs(currentImageFilterNoAbs, currentImageFilter);

        //make color and texture histograms for the targetimage1 and currentImage
        cv::Mat targetColorHist;
        const int Hsize = 32;
        int dimtt[3] = {Hsize, Hsize, Hsize};
        targetColorHist = cv::Mat::zeros(3, dimtt, CV_32F);

        cv::Mat targetTextureHist;
        int dimtb[3] = {Hsize, Hsize, Hsize};
        targetTextureHist = cv::Mat::zeros(3, dimtb, CV_32F);

        cv::Mat currentColorHist;
        int dimct[3] = {Hsize, Hsize, Hsize};
        currentColorHist = cv::Mat::zeros(3, dimct, CV_32F);

        cv::Mat currentTextureHist;
        int dimcb[3] = {Hsize, Hsize, Hsize};
        currentTextureHist = cv::Mat::zeros(3, dimcb, CV_32F);

        cv::Vec3i targetColorPix = {0, 0, 0};
        cv::Vec3i targetTextPix = {0, 0, 0};
        cv::Vec3i currentColorPix = {0, 0, 0};
        cv::Vec3i currentTextPix = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {

                    targetColorPix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    targetTextPix[c] = targetImageFilter.at<cv::Vec3b>(i, j)[c];
                    currentColorPix[c] = currentImage.at<cv::Vec3b>(i, j)[c];
                    currentTextPix[c] = currentImageFilter.at<cv::Vec3b>(i, j)[c];

                    targetColorPix[c] /= 32;
                    targetTextPix[c] /= 32;
                    currentColorPix[c] /= 32;
                    currentTextPix[c] /= 32;
                }

                currentColorHist.at<float>(currentColorPix[0], currentColorPix[1], currentColorPix[2])++;
                currentTextureHist.at<float>(currentTextPix[0], currentTextPix[1], currentTextPix[2])++;
                targetColorHist.at<float>(targetColorPix[0], targetColorPix[1], targetColorPix[2])++;
                targetTextureHist.at<float>(targetTextPix[0], targetTextPix[1], targetTextPix[2])++;
            }
        }

        float totalTargetColor = 0;
        float totalTargetText = 0;
        float totalCurrentColor = 0;
        float totalCurrentText = 0;

        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    totalCurrentColor += std::min(targetColorHist.at<float>(l, m, n), currentColorHist.at<float>(l, m, n)) / 327680;
                    totalTargetColor += targetColorHist.at<float>(l, m, n) / 327680;

                    totalCurrentText += std::min(targetTextureHist.at<float>(l, m, n), currentTextureHist.at<float>(l, m, n)) / 327680;
                    totalTargetText += targetTextureHist.at<float>(l, m, n) / 327680;
                }
            }
        }

        float diffColor = totalTargetColor - totalCurrentColor;
        float diffTexture = totalTargetText - totalCurrentText;

        float totalDiff = diffColor * 0.5 + diffTexture * 0.5;

        arrOfHistImages[p][0] = std::to_string(totalDiff);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}

// TASK - 5 = CUSTOM DESIGN
int custom(std::string target, std::string target2, std::string database, int numImages)
{
    //first image
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;
    //second image
    cv::Mat targetImage2 = getImage(target2, database);
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);

        //make histograms for first target image, second target image, and current image
        cv::Mat firstHist;
        const int Hsize = 32;
        int dim3[3] = {Hsize, Hsize, Hsize};
        firstHist = cv::Mat::zeros(3, dim3, CV_32F);

        cv::Mat secondHist;
        int dim32[3] = {Hsize, Hsize, Hsize};
        secondHist = cv::Mat::zeros(3, dim32, CV_32F);

        cv::Mat currentImageHist;
        int dim3c[3] = {Hsize, Hsize, Hsize};
        currentImageHist = cv::Mat::zeros(3, dim3c, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        cv::Vec3i targetImagePix2 = {0, 0, 0};
        cv::Vec3i currentImagePix = {0, 0, 0};

        //the objects are generally in the bottom 2/3 of the photo so only compare pixels from there
        for (int i = 170; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    targetImagePix2[c] = targetImage2.at<cv::Vec3b>(i, j)[c];
                    currentImagePix[c] = currentImage.at<cv::Vec3b>(i, j)[c];

                    //divide all by 32 so we only get values from 0 to 9
                    targetImagePix[c] /= 32;
                    currentImagePix[c] /= 32;
                    targetImagePix2[c] /= 32;
                }

                currentImageHist.at<float>(currentImagePix[0], currentImagePix[1], currentImagePix[2])++;
                firstHist.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;
                secondHist.at<float>(targetImagePix2[0], targetImagePix2[1], targetImagePix2[2])++;
            }
        }

        float totalCurrentFirst = 0;
        float totalTargetFirst = 0;
        float totalCurrentSecond = 0;
        float totalTargetSecond = 0;
        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    //total pixels here = 342 (bottom 2/3 rows of photo) * 640 = 218880
                    totalCurrentFirst += std::min(currentImageHist.at<float>(l, m, n), firstHist.at<float>(l, m, n)) / 218880;
                    totalTargetFirst += firstHist.at<float>(l, m, n) / 218880;
                    totalCurrentSecond += std::min(currentImageHist.at<float>(l, m, n), secondHist.at<float>(l, m, n)) / 218880;
                    totalTargetSecond += secondHist.at<float>(l, m, n) / 218880;
                }
            }
        }

        float diffFirst = totalTargetFirst - totalCurrentFirst;
        float diffSecond = totalTargetSecond - totalCurrentSecond;

        float finalDiff = diffFirst * 0.5 + diffSecond * 0.5;

        arrOfHistImages[p][0] = std::to_string(finalDiff);
        arrOfHistImages[p][1] = secondImage;
    }
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}
// EXTENSION
int blue_bin(std::string target, std::string database, int numImages){
    cv::Mat image_1 = getImage(target, database);
    std::string arrOfImages[numImages][2];
    cv::Mat blur;
        image_1.copyTo(blur);
        blur5x5(image_1, blur);
        cv::Mat image_3;
        image_1.copyTo(image_3);
        blurQuantize(blur, image_3, 10);
        Mat image_2;
        image_3.copyTo(image_2);
        cvtColor(image_3, image_2, COLOR_BGR2HSV);
        for(int i = 150 ;  i < image_2.rows/2 ; i++){
            for(int j = 150 ; j< image_2.cols/2; j++){
                Vec3b hsv=image_2.at<Vec3b>(i,j);
                int H=hsv.val[0];
                int S=hsv.val[1];
                int V=hsv.val[2];

                 std::cout << " H, S , V = " << H << " , "<< S <<" , " << V <<"  (i , j) = "<< i << ","<< j  << " | ";
            }
        }
        cv::Mat image;
        image_2.copyTo(image);
        inRange(image_2, Scalar(110, 200, 100), Scalar(120, 255, 255), image);
    std::string ty =  typeToString( image_2.type() );
    printf("Matrix: %s %dx%d \n", ty.c_str(), image_2.cols, image_2.rows );

    std::vector<float> vx1;
    std::vector<float> vy1;
    int h = 0;
    for(int i = 0 ;  i < image.rows ; i++){
        for(int j = 0 ; j< image.cols; j++){
            if(image.at<uchar>(i,j) == 255){
                vx1.push_back(i);
                vy1.push_back(j);
                h++;
            }
            else{
                continue;
            }
      

        }
    }
    float a1 = 0, b1 = 0, Mi1 = 0, Mj1 = 0, var1 = 0, std1 =0;
    for(int i = 0; i < h ; i++ ){
        Mi1 += vx1[i];
        Mj1 += vy1[i];


    }
 
    // Mean of the i, j values
    a1 = Mi1 / h;
    b1 = Mj1 / h;



    for(int i = 0; i < h ; i++ ){
        var1 += (vx1[i] - a1) * (vx1[i] - a1) + (vy1[i] - b1)* (vy1[i] - b1);
    }

    std1 = sqrt(var1);
    
    
    printTopMatchesHist(arrOfImages, numImages, "1");
    return 0;
}




int sobeltexture(std::string target, std::string database, int numImages, int x)
{
    cv::Mat targetImage = getImage(target, database);
    cv::Mat currentImage;

    cv::Mat targetImageFilterX;
    cv::Mat targetImageFilter;

    if (x == 0)
    {
        sobelX3x3(targetImage, targetImageFilterX);
    }
    else if (x == 1)
    {
        sobelY3x3(targetImage, targetImageFilterX);
    }
    cv::convertScaleAbs(targetImageFilterX, targetImageFilter);
    std::string arrOfHistImages[numImages][2];

    for (int p = 1; p < numImages; p++)
    {
        std::string secondImage;
        int picNum = p;
        secondImage = getImagePath(secondImage, picNum);
        currentImage = getImage(secondImage, database);
        cv::Mat secondImageFilterX;
        cv::Mat secondImageFilter;
        if (x == 0)
        {
            sobelX3x3(currentImage, secondImageFilterX);
        }
        else if (x == 1)
        {
            sobelY3x3(currentImage, secondImageFilterX);
        }
        cv::convertScaleAbs(secondImageFilterX, secondImageFilter);

        //make an empty 3d RGB histogram
        cv::Mat hist3d;
        const int Hsize = 32;
        int dim3[3] = {Hsize, Hsize, Hsize};
        hist3d = cv::Mat::zeros(3, dim3, CV_32F);

        //for the compared image
        cv::Mat hist3dComp;
        int dim3Comp[3] = {Hsize, Hsize, Hsize};
        hist3dComp = cv::Mat::zeros(3, dim3Comp, CV_32F);

        //loop over every pixel in the image and convert each RGB to an index
        cv::Vec3i targetImagePix = {0, 0, 0};
        //cv::Vec3i targetImagePix2 = {0, 0, 0};
        cv::Vec3i comparedImage = {0, 0, 0};

        for (int i = 0; i < currentImage.rows; i++)
        {
            for (int j = 0; j < currentImage.cols; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    //get each pixel for target image
                    //get each pixel for the compared image
                    targetImagePix[c] = targetImage.at<cv::Vec3b>(i, j)[c];
                    comparedImage[c] = currentImage.at<cv::Vec3b>(i, j)[c];
                    //targetImagePix2[c] = targetImage2Filter.at<cv::Vec3b>(i, j)[c];

                    //divide all by 29 so we only get values from 0 to 9
                    targetImagePix[c] /= 29;
                    comparedImage[c] /= 29;
                    //targetImagePix2[c] /= 29;
                }

                //once out of the loop, increment BOTH histograms (target, and compared)
                hist3dComp.at<float>(comparedImage[0], comparedImage[1], comparedImage[2])++;

                //increment the indexes for r, g, b in the histogram
                hist3d.at<float>(targetImagePix[0], targetImagePix[1], targetImagePix[2])++;

                //increment the indexes for r, g, b in the histogram
                //hist3d2.at<float>(targetImagePix2[0], targetImagePix2[1], targetImagePix2[2])++;
            }
        }

        //once we have the histograms, take the minimum values of each spot and add up for each of
        //the 81 values / 327680 to get a value closer/not close to one
        float totalCompared = 0;
        float totalTarget = 0;
    
        for (int l = 0; l < 10; l++)
        {
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {

                    totalCompared += std::min(hist3dComp.at<float>(l, m, n), hist3d.at<float>(l, m, n)) / 327680;
                    totalTarget += hist3d.at<float>(l, m, n) / 327680;
                }
            }
        }
        //make an array of values to keep track of distance metrics AND weight them
        float diffBwImages = (totalTarget - totalCompared) * 0.5;
        //float diffBwImages2 = (totalTarget2 - totalCompared2) * 0.5;

        arrOfHistImages[p][0] = std::to_string(diffBwImages); //+ diffBwImages2);
        arrOfHistImages[p][1] = secondImage;
    }
    
    printTopMatchesHist(arrOfHistImages, numImages, "1");
    return 0;
}

