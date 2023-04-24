#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

std::string IMGPATH     = "../Images/img1.jpg";
std::string VIDEOPATH   = "../Videos/video_1.mp4";
// example: load/show image
void example1_5_1(std::string &imgPath = IMGPATH) {
    cv::Mat srcImg = cv::imread(imgPath);
    cv::imshow("source img: ", srcImg);
    cv::waitKey(0);
}

// example: erode operation
void example1_5_2(std::string &imgPath = IMGPATH) {
    cv::Mat srcImage = cv::imread(imgPath);
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
    cv::Mat dstImage;
    cv::erode(srcImage, dstImage, element);
    cv::imshow("destination img: ", dstImage);
    cv::waitKey(0);
}

// example: blur operation
void example1_5_3(std::string &imgPath = IMGPATH) {
    cv::Mat srcImg = cv::imread(imgPath);
    cv::Mat dstImg;
    cv::blur(srcImg, dstImg, cv::Size(5, 5));
    cv::imshow("blur img: ", dstImg);
    cv::waitKey(0);
}

// example: edge detection
void example1_5_4_aux(cv::Mat &srcImg) {
    cv::Mat grayImg, blurImg, edge;
    grayImg.create(srcImg.size(), srcImg.type());
    cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
    cv::blur(grayImg, blurImg, cv::Size(3, 3));
    cv::Canny(blurImg, edge, 3, 9, 3);
    cv::imshow("edge img: ", edge);
}

void example1_5_4(std::string &imgPath = IMGPATH) {
    cv::Mat srcImg = cv::imread(imgPath);
    example1_5_4_aux(srcImg);
    cv::waitKey(0);
}

// video capture and operation
void example1_6_1(std::string &videoPath = VIDEOPATH) {
    cv::VideoCapture cap(videoPath);
    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cout << "finish, restart. " << std::endl;
            cap.set(cv::CAP_PROP_POS_FRAMES,0);
            continue;
        }
        example1_5_4_aux(frame);
        // cv::imshow("video carture: ", frame);
        int key = cv::waitKey(30);
        if (key == 'q' || key == 'Q' || key == 27) {
            break;
        }
    }
    cap.release();
}
