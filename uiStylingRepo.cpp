#include "uiStylingRepo.h"


colorStyleInfo::colorStyleInfo() :  primaryColor("#000000"), secondaryColor("#ffffff"),isSecondarySelected(false) {}

void colorStyleInfo::setPrimaryColor(QString color)
{
    primaryColor = color;
}

void colorStyleInfo::setSecondaryColor(QString color)
{
    secondaryColor = color;
}

void colorStyleInfo::setIsSecondarySelected(bool selected)
{
    isSecondarySelected = selected;
}

QString colorStyleInfo::getPrimaryColor()
{
    return primaryColor;
}

QString colorStyleInfo::getPrimaryColorStyle()
{
    return generateRadioButtonStyle(primaryColor);
}

QString colorStyleInfo::getSecondaryColor()
{
    return secondaryColor;
}

QString colorStyleInfo::getSecondaryColorStyle()
{
    return generateRadioButtonStyle(secondaryColor);
}

bool colorStyleInfo::getIsSecondarySelected()
{
    return isSecondarySelected;
}

//Meyers' Singleton
colorStyleInfo& colorStyleInfo::getInstance() {
    static colorStyleInfo instance;
    return instance;
}

QString colorStyleInfo::generateRadioButtonStyle(const QString& colorStyle) {
    return QString(
               "QRadioButton::indicator {"
               "width: 30px; "
               "height: 30px;"
               "border-radius: 16px;"
               "border: 2px solid blue;"
               "background-color: %1;"
               "}"
               ).arg(colorStyle);
}
const std::map<QString, QString> colorList = {
        {"black", "#000000"},
        {"brown", "#a52a2a"},
        {"darkBlue", "#00008b"},
        {"darkCyan", "#008b8b"},
        {"purple", "#800080"},
        {"grey", "#808080"},

        {"lightBlue", "#add8e6"},
        {"lightGreen", "#90ee90"},
        {"lightGrey", "#d3d3d3"},
        {"lightYellow", "#ffffe0"},
        {"white", "#ffffff"},

        {"cyan", "#00ffff"},
        {"gold", "#ffd700"},
        {"green", "#008000"},
        {"orange", "#ffa500"},
        {"pink", "#ffc0cb"},
        {"red", "#ff0000"},
        {"yellow", "#ffff00"},
        {"mediumPurple", "#9370db"},
        {"sandyBrown", "#f4a460"}
    };

