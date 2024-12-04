#include "circle.h"

circle::circle() : radius(2), color(0, 0, 0), thickness(1), lineType(cv::LINE_8), shift(0) {}

 cv::Point circle::getCenter()
{
    return center;
}

int circle::getRadius()
{
    return radius;
}

cv::Scalar circle::getColor()
{
    return color;
}

int circle::getThickness()
{
    return thickness;
}

int circle::getLineType()
{
    return lineType;
}

int circle::getShift()
{
    return shift;
}

void circle::setCenter(cv::Point newCenter)
{
    center = newCenter;
}

void circle::setRadius(int newRadius)
{
    radius = newRadius;
}

void circle::setColor(cv::Scalar newColor)
{
    color = newColor;
}

void circle::setThickness(int newThickness)
{
    thickness = newThickness;
}

void circle::setLineType(int newLineType)
{
    lineType = newLineType;
}

void circle::setShift(int newShift)
{
    shift = newShift;
}
circle& circle::getInstance()
{
    static circle instance;
    return instance;
}
