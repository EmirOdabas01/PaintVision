#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <QImage>
#include <QGraphicsScene>

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

private:
    Ui::MainWindow *ui;

    cv::Mat Main_image;

    QGraphicsScene *Scene;

    QImage MatToQImage(const cv::Mat& image);


};
#endif // MAINWINDOW_H
