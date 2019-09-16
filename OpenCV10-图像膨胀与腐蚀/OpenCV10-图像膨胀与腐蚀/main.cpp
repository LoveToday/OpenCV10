//
//  main.cpp
//  OpenCV10-图像膨胀与腐蚀
//
//  Created by 陈江林 on 2019/9/16.
//  Copyright © 2019 陈江林. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

char OUTPUT_WIN[] = "output image";

int element_size = 3;
int max_size = 21;

void callBack_demo(int, void*);
Mat src, dst;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    String fileName = "/Users/chenjianglin/Documents/C++/OpenCV10/OpenCV10-图像膨胀与腐蚀/OpenCV10-图像膨胀与腐蚀/three.jpg";
    src = imread(fileName);
    if (src.empty()) {
        return -1;
    }
    String outWindow = "out window";
    namedWindow(outWindow);
    imshow(outWindow, src);
    
    namedWindow(OUTPUT_WIN);
    callBack_demo(0, 0);
    
    waitKey(0);
    return 0;
}
void callBack_demo(int, void*){
    int s = element_size * 2 + 1;
    Mat structElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
    dilate(src, dst, structElement, Point(-1, -1), 1);
    imshow(OUTPUT_WIN, dst);
}
