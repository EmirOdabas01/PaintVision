#ifndef UISTYLINGREPO_H
#define UISTYLINGREPO_H
#include <map>
#include <QString>

class colorStyleInfo{
public:

    colorStyleInfo& operator=(const colorStyleInfo&) = delete;
    colorStyleInfo& operator=(const colorStyleInfo&&) = delete;


    void setPrimaryColor(QString color);
    void setSecondaryColor(QString color);
    void setIsSecondarySelected(bool selected);

    QString getPrimaryColor();
    QString getPrimaryColorStyle();
    QString getSecondaryColor();
    QString getSecondaryColorStyle();
    bool getIsSecondarySelected();

    static colorStyleInfo& getInstance();

private:

    QString generateRadioButtonStyle(const QString& colorStyle);

    colorStyleInfo();

    QString primaryColor;
    QString primaryColorStyle;

    QString secondaryColor;
    QString secondaryColorStyle;

    bool isSecondarySelected;
};

extern const std::map<QString, QString> colorList;



#endif // UISTYLINGREPO_H
