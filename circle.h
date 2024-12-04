#ifndef CIRCLE_H
#define CIRCLE_H
#include <opencv2/opencv.hpp>
class circle
{
public:

    circle& operator=(const circle&) = delete;
    circle& operator=(const circle&&) = delete;

    static circle& getInstance();

    cv::Point getCenter();
    int getRadius();
    cv::Scalar getColor();
    int getThickness();
    int getLineType();
    int getShift();

    void setCenter(cv::Point newCenter);
    void setRadius(int newRadius);
    void setColor(cv::Scalar newColor);
    void setThickness(int newThickness);
    void setLineType(int newLineType);
    void setShift(int newShift);
private:

     circle();

    cv::Point center;
    int radius;
    cv::Scalar color;
    int thickness;
    int lineType;
    int shift;
};

#endif // CIRCLE_H
