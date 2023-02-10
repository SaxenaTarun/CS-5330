# CS 5330: PATTERN RECOGNITION AND COMPUTER VISION

## Project 2: Content-based Image Retrieval

Content-based Image Retrieval is an important area of computer vision. This project's goal is to continue learning how to modify and analyze photos at the pixel level. Furthermore, in this project, we are using matching or pattern recognition.This project's challenges included matching two images based on RGB pixels, matching images based on histograms, matching images using multiple histograms, comparing images based on a full-color image histogram and a full-texture histogram, and constructing a custom design. The entire process is implemented as a command line program that accepts a target filename for T, an image database directory as B, the feature type, the matching method, and the number of images N to return. The filenames of the top N matching images are printed by the program.
The above processing tasks are performed using OpenCV libraries in C++ programming language in Xcode IDE (Version 14.2) on MacBook Pro (M1 Chip).

Files:
main.cpp -> MAIN FUNCTION FOR CALLING ALL THE TASKS WITH feature feature_type IN THE COMMAND LINE
features.cpp -> FEATURE FILE INCLUDES THE VARIOUS TASKS FUNCTIONS CALLED IN MAIN.CPP
features.hpp -> HEADER FILE FOR FEATURES.CPP

Execution in Xcode:
Product->Scheme->Choose Scheme
Scheme: image_name.jpg database feature feature_type number_of_images
eg. pic.1016.jpg olympus feature baseline 1108

