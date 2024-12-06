#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include  "btnselectinfo.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(Scene);

    MainWindow::on_actionNew_triggered();

    defaultRadioButtonStyle = "QRadioButton::indicator {"
                              "width: 30px; "
                              "height: 30px; "
                              "border-radius: 16px; "
                              "border: 2px solid black; "
                              "background-color: %1;"
                              "}";
    view = ui->graphicsView;

    connect(view, &CustomView::cordinateChanged, this, &MainWindow::updateCordinate);

    on_primaryColor_clicked();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateCordinate(const QPointF &newCordinate)
{
    cordinate = newCordinate;
    diskForPainting.setCenter(cv::Point(newCordinate.x(), newCordinate.y()));

    paintFuncNav();
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

       // if(Main_image.rows > 800 || Main_image.cols > 600)
         //   cv::resize(Main_image, Main_image, cv::Size(800, 600));

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

    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("black"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("black"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}

void MainWindow::on_grey_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("grey"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("grey"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_brown_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("brown"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("brown"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_red_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("red"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("red"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_orange_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("orange"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("orange"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_green_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("green"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("green"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_yellow_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("yellow"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("yellow"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_lightBlue_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("lightBlue"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("lightBlue"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_darkBlue_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("darkBlue"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("darkBlue"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_purple_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("purple"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("purple"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_whiteRbutton_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("white"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("white"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_lightGrey_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("lightGrey"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("lightGrey"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_sandyBrown_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("sandyBrown"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("sandyBrown"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_pink_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("pink"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("pink"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_gold_toggled(bool checked)
{

    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("gold"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("gold"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_lightYellow_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("lightYellow"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("lightYellow"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_lightGreen_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("lightGreen"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("lightGreen"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_cyan_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("cyan"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("cyan"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }


}


void MainWindow::on_darkCyan_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("darkCyan"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("darkCyan"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }

}


void MainWindow::on_mediumPurple_toggled(bool checked)
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        rButtonStyleInfo.setSecondaryColor(colorList.at("mediumPurple"));

        ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());
    }
    else if(checked)
    {
        rButtonStyleInfo.setPrimaryColor(colorList.at("mediumPurple"));

        ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());
    }
}

void MainWindow::on_penBtn_toggled(bool checked)
{
    componentInfo.setIsPenSlc(checked);

    if(componentInfo.getIsPenSlc())
    {
        QPixmap newCursor(":/new/menuIcons/icons/penIcon");
        QPixmap scaledPixmap = newCursor.scaled(16, 16, Qt::KeepAspectRatio);
        QCursor customCursor(scaledPixmap);
        this->setCursor(customCursor);
    }
}


void MainWindow::on_fillBtn_toggled(bool checked)
{
    componentInfo.setIsFillSlc(checked);
}


void MainWindow::on_textBtn_toggled(bool checked)
{
    componentInfo.setIsTextSlc(checked);
}


void MainWindow::on_eraserBtn_toggled(bool checked)
{
    componentInfo.setIsBrushSlc(checked);

    if(componentInfo.getIsBrushSlc())
    {
        QPixmap newCursor(":/new/menuIcons/icons/eraserCursor");
        QPixmap scaledPixmap = newCursor.scaled(32, 32, Qt::KeepAspectRatio);
        QCursor customCursor(scaledPixmap);
        this->setCursor(customCursor);
    }
}


void MainWindow::on_clrPickBtn_toggled(bool checked)
{
    componentInfo.setIsClrPickSlc(checked);
}


void MainWindow::on_magnifierBtn_toggled(bool checked)
{
    componentInfo.setIsMagnifierSlc(checked);
}

void MainWindow::on_paintRadius_valueChanged(int value)
{
    diskForPainting.setRadius(value);
}

void MainWindow::paintFuncNav()
{
    if(componentInfo.getIsPenSlc()) drawToScene();
}

void MainWindow::drawToScene()
{
    if(rButtonStyleInfo.getIsSecondarySelected())
    {
        diskForPainting.setColor(rButtonStyleInfo.getSecondaryColor());
    }
    else
    {
        diskForPainting.setColor(rButtonStyleInfo.getPrimaryColor());
    }

    cv::circle(Main_image,
               diskForPainting.getCenter(),
               diskForPainting.getRadius(),
               diskForPainting.getColor(),
               diskForPainting.getFilled());

    show_image();
}

void MainWindow::on_isFilled_toggled(bool checked)
{
    if(checked)
    {
        diskForPainting.setFilled(cv::FILLED);
    }
    else
    {
        diskForPainting.setFilled(1);
    }
}


void MainWindow::on_primaryColor_clicked()
{
    rButtonStyleInfo.setIsSecondarySelected(false);

    ui->primaryColor->setStyleSheet(rButtonStyleInfo.getPrimaryColorStyle());

    ui->secondaryColor->setStyleSheet(defaultRadioButtonStyle.arg(rButtonStyleInfo.getSecondaryColor()));
}


void MainWindow::on_secondaryColor_clicked()
{
    rButtonStyleInfo.setIsSecondarySelected(true);

    ui->secondaryColor->setStyleSheet(rButtonStyleInfo.getSecondaryColorStyle());

    ui->primaryColor->setStyleSheet(defaultRadioButtonStyle.arg(rButtonStyleInfo.getPrimaryColor()));
}


void MainWindow::on_cursor_toggled(bool checked)
{
    if(checked)
        this->setCursor(Qt::ArrowCursor);
}

