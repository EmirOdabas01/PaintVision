#ifndef BTNSELECTINFO_H
#define BTNSELECTINFO_H

class btnSelectInfo
{
public:
    btnSelectInfo& operator=(const btnSelectInfo&) = delete;
    btnSelectInfo& operator=(const btnSelectInfo&&) = delete;

    static btnSelectInfo& getInstance();

    void setIsBrushSlc(bool selected);
    void setIsPenSlc(bool selected);
    void setIsClrPickSlc(bool selected);
    void setIsMagnifierSlc(bool selected);
    void setIsFillSlc(bool selected);
    void setIsTextSlc(bool selected);

    bool getIsBrushSlc();
    bool getIsPenSlc();
    bool getIsClrPickSlc();
    bool getIsMagnifierSlc();
    bool getIsFillSlc();
    bool getIsTextSlc();
private:
    btnSelectInfo();

    bool isPenSlc;
    bool isBrushSlc;
    bool isClrPickSlc;
    bool isMagnifierSlc;
    bool isFillSlc;
    bool isTextSlc;
};

#endif // BTNSELECTINFO_H
