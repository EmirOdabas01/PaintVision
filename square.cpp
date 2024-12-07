#include "square.h"

Square::Square() {}

Square& Square::getInstance()
{
    static Square instance;
    return instance;
}

void Square::setCorners(const cv::Point &center)
{
    topLftCorner = cv::Point(center.x - radius, center.y + radius);
    bttmRghtCorner = cv::Point(center.x + radius, center.y - radius);
}

cv::Point Square::getTopLftCorner()
{
    return topLftCorner;
}

cv::Point Square::getBttmRghtCorner()
{
    return bttmRghtCorner;
}

void Square::setRadius(int newRadius)
{
    radius = newRadius;
}
