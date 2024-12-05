#include "circle.h"

circle::circle() : radius(2), color(0, 0, 0), filled(1) {}

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
int circle::getFilled()
{
    return filled;
}

void circle::setCenter(cv::Point newCenter)
{
    center = newCenter;
}

void circle::setRadius(int newRadius)
{
    radius = newRadius;
}

void circle::setColor(QString newColor)
{
    QString rgbHex = newColor.mid(1);

    int red = rgbHex.mid(0, 2).toInt(nullptr, 16);
    int green = rgbHex.mid(2, 2).toInt(nullptr, 16);
    int blue = rgbHex.mid(4, 2).toInt(nullptr, 16);

    color = cv::Scalar(blue, green, red);
}

void circle::setFilled(int lineType)
{
    filled = lineType;
}

circle& circle::getInstance()
{
    static circle instance;
    return instance;
}
