#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <iostream>

using namespace cv;

// example: access img elements

// use at
void colorReduce(Mat &inputImg, Mat &outputImg, int div) {
    outputImg = inputImg.clone();
    int rows = outputImg.rows;
    int cols = outputImg.cols * outputImg.channels();
    for (int i = 0; i < rows; ++i) {
        auto *data = outputImg.ptr<uchar>(i);  // get address of each rows of data
        for (int j = 0; j < cols; ++j) {
            data[j] = data[j] / div * div + div / 2;
        }
    }
}

void colorReduce01(Mat &inputImg, Mat &outputImg, int div) {
    outputImg = inputImg.clone();
    Mat_<Vec3b>::iterator iter = outputImg.begin<Vec3b>();
    Mat_<Vec3b>::iterator end = outputImg.end<Vec3b>();
    for (; iter != end; ++iter) {
        (*iter)[0] = (*iter)[0] / div * div + div / 2;
        (*iter)[1] = (*iter)[1] / div * div + div / 2;
        (*iter)[2] = (*iter)[2] / div * div + div / 2;
    }
}

void example5_1_5() {
    Mat srcImg = imread("../Images/img1.jpg");
    Mat dstImg;
    dstImg.create(srcImg.rows, srcImg.cols, srcImg.type());
    auto time0 = static_cast<double>(getTickCount());
    colorReduce(srcImg, dstImg, 32);
    time0 = ((double)getTickCount()) - time0 / getTickFrequency();
    std::cout << time0 << "sec" << std::endl;
    imshow("res: ", dstImg);
    waitKey(0);
}