#ifndef CIRCLE_H
#define CIRCLE_H
#include <opencv2/opencv.hpp>
#include <QString>
class circle
{
public:

    circle& operator=(const circle&) = delete;
    circle& operator=(const circle&&) = delete;

    static circle& getInstance();

    cv::Point getCenter();
    int getRadius();
    cv::Scalar getColor();
    int getFilled();

    void setFilled(int lineType);
    void setCenter(cv::Point newCenter);
    void setRadius(int newRadius);
    void setColor(QString newColor);
private:

     circle();

    cv::Point center;
    int radius;
    cv::Scalar color;
    int filled;
};

#endif // CIRCLE_H
