#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <QImage>
#include <QGraphicsScene>
#include "uiStylingRepo.h"


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QMessageBox>
#include "customview.h"
#include "btnselectinfo.h"

#include "circle.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void show_image();

    void on_rotateLeft_clicked();

    void on_rotateRight_clicked();

    void on_flipHorizontal_clicked();

    void on_flipVertical_clicked();

    void on_reverse_clicked();

    void on_flip_clicked();

    void on_blackRbutton_toggled(bool checked);

    void on_grey_toggled(bool checked);

    void on_brown_toggled(bool checked);

    void on_red_toggled(bool checked);

    void on_orange_toggled(bool checked);

    void on_green_toggled(bool checked);

    void on_yellow_toggled(bool checked);

    void on_lightBlue_toggled(bool checked);

    void on_darkBlue_toggled(bool checked);

    void on_purple_toggled(bool checked);

    void on_whiteRbutton_toggled(bool checked);

    void on_lightGrey_toggled(bool checked);

    void on_sandyBrown_toggled(bool checked);

    void on_pink_toggled(bool checked);

    void on_gold_toggled(bool checked);

    void on_lightYellow_toggled(bool checked);

    void on_lightGreen_toggled(bool checked);

    void on_cyan_toggled(bool checked);

    void on_darkCyan_toggled(bool checked);

    void on_mediumPurple_toggled(bool checked);

    //void on_secondaryColor_toggled(bool checked);

    //void on_primaryColor_toggled(bool checked);

    void updateCordinate(const QPointF &newCordinate);
    void on_penBtn_toggled(bool checked);

    void on_fillBtn_toggled(bool checked);

    void on_textBtn_toggled(bool checked);

    void on_brushBtn_toggled(bool checked);

    void on_clrPickBtn_toggled(bool checked);

    void on_magnifierBtn_toggled(bool checked);

    void on_paintRadius_valueChanged(int value);

    void paintFuncNav(); // decides which operation will be performed

    void drawToScene();

    void on_isFilled_toggled(bool checked);

    void on_primaryColor_clicked();

    void on_secondaryColor_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat Main_image;

    QGraphicsScene *Scene;

    QImage MatToQImage(const cv::Mat& image);

    colorStyleInfo& rButtonStyleInfo = colorStyleInfo::getInstance();

    circle& diskForPainting = circle::getInstance();

    QString defaultRadioButtonStyle;

    QPointF cordinate;

    CustomView *view;

    btnSelectInfo& componentInfo = btnSelectInfo::getInstance();

};
#endif // MAINWINDOW_H
