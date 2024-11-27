#ifndef UISTYLINGREPO_H
#define UISTYLINGREPO_H
#include <map>
#include <QString>

class colorStyleInfo{
public:

    void setPrimaryColor(QString color);
    void setSecondaryColor(QString color);
    void setIsSecondarySelected(bool selected);

    QString getPrimaryColor();
    QString getPrimaryColorStyle();
    QString getSecondaryColor();
    QString getSecondaryColorStyle();
    bool getIsSecondarySelected();

    QString generateRadioButtonStyle(const QString& colorStyle);

    static colorStyleInfo& getInstance();

private:
    colorStyleInfo();

    QString primaryColor;
    QString primaryColorStyle;

    QString secondaryColor;
    QString secondaryColorStyle;

    bool isSecondarySelected;
};

extern const std::map<QString, QString> colorList;



#endif // UISTYLINGREPO_H
