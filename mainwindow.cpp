#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
QImage MainWindow::MatToQImage(const cv::Mat& mat) {

    cv::Mat temp;
    cv::cvtColor(mat, temp, cv::COLOR_BGR2RGB);

    if (mat.empty()) {
        return QImage();
    }

    switch (mat.type()) {
    case CV_8UC1: {
        QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
        return image.copy();
    }
    case CV_8UC3: {
        QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_BGR888);
        return image.copy();
    }
    case CV_8UC4: {
        QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    default:
        qWarning("wrong format");
        return QImage();
    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(Scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Images (*.png *.jpg *.bmp *.tiff);;All Files (*)");

    if (!fileName.isEmpty()) {

        image = cv::imread(fileName.toStdString());

        if (image.empty()) {

            QMessageBox::warning(this, "Error", "Failed to load image.");
            return;
        }

        QImage img = MatToQImage(image);

        QPixmap pixmap = QPixmap::fromImage(img);

        Scene->clear();
        Scene->addPixmap(pixmap);

        ui->graphicsView->setSceneRect(pixmap.rect());
    }
}

