#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(Scene);

    MainWindow::on_actionNew_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Images (*.png *.jpg *.bmp *.tiff);;All Files (*)");

    if (!fileName.isEmpty()) {

        Main_image = cv::imread(fileName.toStdString());

        if (Main_image.empty()) {

            QMessageBox::warning(this, "Error", "Failed to load image.");
            return;
        }

        show_image();
    }
}

void MainWindow::show_image()
{
    if(Main_image.empty()) return;

    QImage temp = MatToQImage(Main_image);

    QPixmap img_to_pix = QPixmap::fromImage(temp);

    Scene->clear();
    Scene->addPixmap(img_to_pix);

    ui->graphicsView->setSceneRect(img_to_pix.rect());

}

void MainWindow::on_actionNew_triggered()
{
    Main_image = cv::Mat::zeros(512, 512, CV_8UC3);
    Main_image.setTo(255);
    show_image();
}

QImage MainWindow::MatToQImage(const cv::Mat& Mat_image) {


    if (Mat_image.empty()) {
        return QImage();
    }

    if(Mat_image.type() == CV_8UC1)
    {
        cv::Mat Gray_image;
        cv::cvtColor(Mat_image, Gray_image, cv::COLOR_BGR2GRAY);

         return QImage(Gray_image.data, Gray_image.cols, Gray_image.rows, Gray_image.step, QImage::Format_Grayscale8).copy();
    }
    else if(Mat_image.type() == CV_8UC3)
    {
        cv::Mat Rgb_image;
        cv::cvtColor(Mat_image, Rgb_image, cv::COLOR_BGR2RGB);

        return QImage(Rgb_image.data, Rgb_image.cols, Rgb_image.rows, Rgb_image.step, QImage::Format_RGB888).copy();
    }
    else if(Mat_image.type() == CV_8UC4)
    {
        cv::Mat Argb_image;
        cv::cvtColor(Mat_image, Argb_image, cv::COLOR_BGRA2RGBA);

        return QImage(Argb_image.data, Argb_image.cols, Argb_image.rows, Argb_image.step, QImage::Format_ARGB32).copy();
    }
    else
    {
        qWarning("wrong format");
        return QImage();
    }

}

