#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <iostream>

using namespace cv;

// example: create Mat
void example4_1_4() {
    // construct function
    Mat m1(2, 2, CV_8UC3, Scalar(0, 0, 255));
    std::cout << "m1: " << m1 << std::endl;  // only used in two dims img

    // create three dims
    int sz[3] = {2, 2, 2};
    Mat m2(3, sz, CV_8UC3, Scalar::all(0));

    // use create function
    Mat m3;
    m3.create(4, 4, CV_8UC(2));  // cannot set init value
    std::cout << "m3: " << m3 << std::endl;

    // operator as Matlab
    Mat E = Mat::eye(4, 4, CV_64F);
    std::cout << "E: " << E << std::endl;
    Mat O = Mat::ones(3, 3, CV_64F);
    std::cout << "O: " << O << std::endl;
    Mat Z = Mat::zeros(2, 2, CV_64F);
    std::cout << "Z: " << Z << std::endl;

    // use matrix
    Mat m4 = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    std::cout << "m4: " << m4 << std::endl;

    // clone / copyto
    Mat m5 = m4.row(1).clone();
    std::cout << "m5: " << m5 << std::endl;
}

// example: common class
void example4_2_1() {
    // Point class
    Point point;
    point.x = 10;
    point.y = 8;
    std::cout << "point: " << point << std::endl;

    // color class: Scalar
    Scalar scalar1(100, 100, 100);
    std::cout << "scalar1: " << scalar1 << std::endl;

    // Size class
    Size size1(100, 100);
    std::cout << "size1: " << size1 << std::endl;

    // Rect
    Rect rect1(100, 100, 200, 200);
    std::cout << "rect1: " << rect1 << std::endl;
}




#define WINDOW_NAME1 "pic1"
#define WINDOW_NAME2 "pic2"
#define WINDOW_WIDTH 600


void DrawEllipse(Mat &img, double angle);
void DrawFilledCircle(Mat &img, Point center);
void DrawPolygon(Mat &img);
void DrawLine(Mat &img, Point start, Point end);

// example: drae funciton
void example4_3_5() {

    Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
    Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

    DrawEllipse(atomImage, 90);
    DrawEllipse(atomImage, 0);
    DrawEllipse(atomImage, 45);
    DrawEllipse(atomImage, -45);

    DrawFilledCircle(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));

    DrawPolygon(rookImage);

    rectangle(rookImage,
               Point(0, 7 * WINDOW_WIDTH / 8 ),
               Point(WINDOW_WIDTH, WINDOW_WIDTH),
               Scalar(0, 255, 255 ),
               -1,
               8);

    DrawLine(rookImage, Point( 0, 15*WINDOW_WIDTH/16 ), Point( WINDOW_WIDTH, 15*WINDOW_WIDTH/16));
    DrawLine(rookImage, Point( WINDOW_WIDTH/4, 7*WINDOW_WIDTH/8 ), Point( WINDOW_WIDTH/4, WINDOW_WIDTH));
    DrawLine(rookImage, Point( WINDOW_WIDTH/2, 7*WINDOW_WIDTH/8 ), Point( WINDOW_WIDTH/2, WINDOW_WIDTH));
    DrawLine(rookImage, Point( 3*WINDOW_WIDTH/4, 7*WINDOW_WIDTH/8 ), Point( 3*WINDOW_WIDTH/4, WINDOW_WIDTH));

    imshow(WINDOW_NAME1, atomImage);
    moveWindow(WINDOW_NAME1, 0, 200);
    imshow(WINDOW_NAME2, rookImage);
    moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);

    waitKey(0);
}

void DrawEllipse(Mat &img, double angle ) {
    int thickness = 2;
    int lineType = 8;

    ellipse( img,
             Point( WINDOW_WIDTH/2, WINDOW_WIDTH/2 ),
             Size( WINDOW_WIDTH/4, WINDOW_WIDTH/16 ),
             angle,
             0,
             360,
             Scalar( 255, 129, 0 ),
             thickness,
             lineType );
}

void DrawFilledCircle(Mat &img, Point center) {
    int thickness = -1;
    int lineType = 8;

    circle( img,
            center,
            WINDOW_WIDTH/32,
            Scalar( 0, 0, 255 ),
            thickness,
            lineType );
}

void DrawPolygon(Mat &img ) {
    int lineType = 8;

    //创建一些点
    Point rookPoints[1][20];
    rookPoints[0][0]  = Point(    WINDOW_WIDTH/4,   7*WINDOW_WIDTH/8 );
    rookPoints[0][1]  = Point(  3*WINDOW_WIDTH/4,   7*WINDOW_WIDTH/8 );
    rookPoints[0][2]  = Point(  3*WINDOW_WIDTH/4,  13*WINDOW_WIDTH/16 );
    rookPoints[0][3]  = Point( 11*WINDOW_WIDTH/16, 13*WINDOW_WIDTH/16 );
    rookPoints[0][4]  = Point( 19*WINDOW_WIDTH/32,  3*WINDOW_WIDTH/8 );
    rookPoints[0][5]  = Point(  3*WINDOW_WIDTH/4,   3*WINDOW_WIDTH/8 );
    rookPoints[0][6]  = Point(  3*WINDOW_WIDTH/4,     WINDOW_WIDTH/8 );
    rookPoints[0][7]  = Point( 26*WINDOW_WIDTH/40,    WINDOW_WIDTH/8 );
    rookPoints[0][8]  = Point( 26*WINDOW_WIDTH/40,    WINDOW_WIDTH/4 );
    rookPoints[0][9]  = Point( 22*WINDOW_WIDTH/40,    WINDOW_WIDTH/4 );
    rookPoints[0][10] = Point( 22*WINDOW_WIDTH/40,    WINDOW_WIDTH/8 );
    rookPoints[0][11] = Point( 18*WINDOW_WIDTH/40,    WINDOW_WIDTH/8 );
    rookPoints[0][12] = Point( 18*WINDOW_WIDTH/40,    WINDOW_WIDTH/4 );
    rookPoints[0][13] = Point( 14*WINDOW_WIDTH/40,    WINDOW_WIDTH/4 );
    rookPoints[0][14] = Point( 14*WINDOW_WIDTH/40,    WINDOW_WIDTH/8 );
    rookPoints[0][15] = Point(    WINDOW_WIDTH/4,     WINDOW_WIDTH/8 );
    rookPoints[0][16] = Point(    WINDOW_WIDTH/4,   3*WINDOW_WIDTH/8 );
    rookPoints[0][17] = Point( 13*WINDOW_WIDTH/32,  3*WINDOW_WIDTH/8 );
    rookPoints[0][18] = Point(  5*WINDOW_WIDTH/16, 13*WINDOW_WIDTH/16 );
    rookPoints[0][19] = Point(    WINDOW_WIDTH/4,  13*WINDOW_WIDTH/16 );

    const Point* ppt[1] = { rookPoints[0] };
    int npt[] = { 20 };

    fillPoly( img,
              ppt,
              npt,
              1,
              Scalar( 255, 255, 255 ),
              lineType );
}

void DrawLine(Mat &img, Point start, Point end) {
    int thickness = 2;
    int lineType = 8;
    line( img,
          start,
          end,
          Scalar( 0, 0, 0 ),
          thickness,
          lineType );
}