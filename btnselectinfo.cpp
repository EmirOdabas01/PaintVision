#include "btnselectinfo.h"

btnSelectInfo::btnSelectInfo() : isEraserSlc(false), isPenSlc(false), isClrPickSlc(false), isMagnifierSlc(false), isFillSlc(false), isTextSlc(false) {}

btnSelectInfo& btnSelectInfo::getInstance()
{
    static btnSelectInfo instance;
    return instance;
}

void btnSelectInfo::setIsEraserSlc(bool selected)
{
    isEraserSlc = selected;
}

void btnSelectInfo::setIsPenSlc(bool selected)
{
    isPenSlc = selected;
}

void btnSelectInfo::setIsClrPickSlc(bool selected)
{
    isClrPickSlc = selected;
}

void btnSelectInfo::setIsMagnifierSlc(bool selected)
{
    isMagnifierSlc = selected;
}

void btnSelectInfo::setIsFillSlc(bool selected)
{
    isFillSlc = selected;
}

void btnSelectInfo::setIsTextSlc(bool selected)
{
    isTextSlc = selected;
}

bool btnSelectInfo::getIsEraserSlc()
{
    return isEraserSlc;
}

bool btnSelectInfo::getIsPenSlc()
{
    return isPenSlc;
}

bool btnSelectInfo::getIsClrPickSlc()
{
    return isClrPickSlc;
}

bool btnSelectInfo::getIsMagnifierSlc()
{
    return isMagnifierSlc;
}

bool btnSelectInfo::getIsFillSlc()
{
    return isFillSlc;
}

bool btnSelectInfo::getIsTextSlc()
{
    return isTextSlc;
}
