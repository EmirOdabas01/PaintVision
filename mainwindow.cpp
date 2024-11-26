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

    PrimaryColorStyle = ui->primaryColor->styleSheet();

    secondaryColorStyle = ui->secondaryColor->styleSheet();

    isSecondaryChecked = false;
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

        if(Main_image.rows > 800 || Main_image.cols > 600)
            cv::resize(Main_image, Main_image, cv::Size(800, 600));

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
    Main_image = cv::Mat::zeros(800, 600, CV_8UC3);
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


void MainWindow::on_rotateLeft_clicked()
{
    cv::rotate(Main_image, Main_image, cv::ROTATE_90_COUNTERCLOCKWISE);

    show_image();
}


void MainWindow::on_rotateRight_clicked()
{
    cv::rotate(Main_image, Main_image, cv::ROTATE_90_CLOCKWISE);

    show_image();
}


void MainWindow::on_flipHorizontal_clicked()
{
    cv::flip(Main_image, Main_image, 1);

    show_image();
}


void MainWindow::on_flipVertical_clicked()
{
    cv::flip(Main_image, Main_image, 0);

    show_image();
}


void MainWindow::on_reverse_clicked()
{
    cv::rotate(Main_image, Main_image, cv::ROTATE_180);

    show_image();
}


void MainWindow::on_flip_clicked()
{
    cv::transpose(Main_image, Main_image);

    show_image();
}


void MainWindow::on_blackRbutton_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: black;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
           selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
                selectedColor
            );
    }

}

void MainWindow::on_grey_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: grey;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_brown_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: brown;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_red_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: red;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_orange_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: orange;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_green_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: green;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_yellow_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: yellow;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_lightBlue_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: lightBlue;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_darkBlue_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: darkBlue;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_purple_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: purple;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_whiteRbutton_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: white;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_lightGrey_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: lightGrey;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_sandyBrown_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: sandyBrown;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_pink_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: pink;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_gold_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: gold;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_lightYellow_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: lightYellow;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_lightGreen_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: lightGreen;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_cyan_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: cyan;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_darkCyan_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: darkCyan;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_mediumPurple_toggled(bool checked)
{
    selectedColor = "QRadioButton::indicator {"
                    "background-color: mediumPurple;"
                    "}";
    if(isSecondaryChecked)
    {
        ui->secondaryColor->setStyleSheet(
            secondaryColorStyle +
            selectedColor +
             "border: 2px solid blue;"
            );
    }
    else if(checked)
    {
        ui->primaryColor->setStyleSheet(
            PrimaryColorStyle +
            selectedColor
            );
    }

}


void MainWindow::on_secondaryColor_toggled(bool checked)
{
    if(checked)
    {
         isSecondaryChecked = true;

        QString secondaryCurrentStyle = ui->secondaryColor->styleSheet();

        ui->secondaryColor->setStyleSheet(
            secondaryCurrentStyle +
            "QRadioButton::indicator {"
            "border: 2px solid blue;"
            "}"
            );

        QString primaryCurrentStyle = ui->primaryColor->styleSheet();

         ui->primaryColor->setStyleSheet(
             primaryCurrentStyle +
             "QRadioButton::indicator {"
             "border: 2px solid black;"
             "}"
             );


    }


}


void MainWindow::on_primaryColor_toggled(bool checked)
{
    if(checked)
    {
        isSecondaryChecked = false;

        QString primaryCurrentStyle = ui->primaryColor->styleSheet();

        ui->primaryColor->setStyleSheet(
            primaryCurrentStyle +
            "QRadioButton::indicator {"
            "border: 2px solid blue;"
            "}"
            );

        QString secondaryCurrentStyle = ui->secondaryColor->styleSheet();

        ui->secondaryColor->setStyleSheet(
            secondaryCurrentStyle +
            "QRadioButton::indicator {"
            "border: 2px solid black;"
            "}"
            );
    }



}

