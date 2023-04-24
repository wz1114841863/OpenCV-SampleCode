#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <iostream>

using namespace cv;

// example: create an alpha png
void createAlphaMat(Mat &mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            auto &rgba = mat.at<Vec4b>(i, j);
            rgba[0] = UCHAR_MAX;
            rgba[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols) * UCHAR_MAX);
            rgba[2] = saturate_cast<uchar>((float(mat.rows - j)) / ((float)mat.rows) * UCHAR_MAX);
            rgba[3] = saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
        }
    }
}

void example3_1_8() {
    cv::Mat mat(480, 640, CV_8UC4);
    createAlphaMat(mat);

    std::vector<int> compression_params;
    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    try {
        cv::imwrite("../Images/alpha.png", mat, compression_params);
    }catch (std::runtime_error &ex){
        std::cout << "error. " << std::endl;
        return ;
    }
}

// example create TrackBar
#define WINDOW_NAME "TrackBar"
const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider = 0;
double g_dAlphaValue = 0;
double g_dBetaValue = 0;

Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

void on_Trackbar(int , void*) {
    g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
    g_dBetaValue = (1.0 - g_dAlphaValue);
    addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
    imshow(WINDOW_NAME, g_dstImage);
}

void example3_1_9() {
    // load two imgs with same size
    g_srcImage1 = imread("../Images/img2.png");
    g_srcImage2 = imread("../Images/img3.png");
    //set trackbar init val
    g_nAlphaValueSlider = 70;
    // create window
    namedWindow(WINDOW_NAME, 1);
    // add trackBar
    std::string trackbarName = "Trackbar";
    createTrackbar(trackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
    on_Trackbar(g_nAlphaValueSlider, nullptr);
    waitKey(0);
}


// example: mouse event
#define MOUSE_EVENT_WINDOW_NAME "mouse_event"

void onMouseHandle(int event, int x, int y, int flags, void *param) {
    Mat &img = *(cv::Mat *)param;
    switch(event) {
        case EVENT_MOUSEMOVE: {
            if ()
            break;
        }
        case EVENT_LBUTTONDOWN: {

            break;
        }
        case EVENT_LBUTTONUP: {

            break;
        }
    }
}

void drawRectangle(cv::Mat &img, cv::Rect box);
void showHelpText();

Rect g_rectangle;
bool g_bDrawingBox = false;
RNG g_rng(12345);


void example3_1_10() {
    // set param
    g_rectangle = Rect(-1, -1, 0, 0);
    Mat srcImg(600, 800, CV_8UC3), tmpImg;
    srcImg.copyTo(tmpImg);
    srcImg = Scalar::all(0);

    // create window and set callback
    namedWindow(MOUSE_EVENT_WINDOW_NAME);
    setMouseCallback(MOUSE_EVENT_WINDOW_NAME, onMouseHandle, (void *)&srcImg);

    while (true) {
        srcImg.copyTo(tmpImg);
        if (g_bDrawingBox) {
            drawRectangle(tmpImg, g_rectangle);
        }
        imshow(MOUSE_EVENT_WINDOW_NAME, tmpImg);
        if (waitKey(0) == 27) {
            break;
        }
    }
}

