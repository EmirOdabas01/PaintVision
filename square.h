#ifndef SQUARE_H
#define SQUARE_H

#include <opencv2/opencv.hpp>

class Square
{
public:
    Square();

    Square& operator=(const Square&) = delete;
    Square& operator=(const Square&&) = delete;

    static Square& getInstance();

    void setCorners(const cv::Point& center);
    cv::Point getTopLftCorner();
    cv::Point getBttmRghtCorner();

    void setRadius(int newRdius);
private:

    cv::Point topLftCorner;
    cv::Point bttmRghtCorner;
    int radius;
};

#endif // SQUARE_H
