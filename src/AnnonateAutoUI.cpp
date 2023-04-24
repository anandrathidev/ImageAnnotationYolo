
#include "AnnonateAutoUI.h"
#include "ImageHandler.h"

#include <QtWidgets/QWidget>
#include <QFileDialog>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <opencv2/opencv.hpp>

namespace IANN
{

    AnnonateAutoUI::AnnonateAutoUI(ImageFile* imageFile) :QDialog{}
    {
        //mImage = new QImage(this);
        mAnnonateCVButton = new QPushButton{ this };
        mAnnonateYOLOButton = new QPushButton{ this };
        const cv::Mat* mat = imageFile->ReadNextFrame();
        QImage convert{ mat->data, mat->cols, mat->rows, QImage::Format_RGB888 };
        dispLabel = new QLabel{ this };
        dispLabel->setPixmap(QPixmap::fromImage(convert));
        mQHBoxLayout = new QHBoxLayout{ this };
        mQVBoxLayout = new QVBoxLayout{ this };
        this->setLayout(mQVBoxLayout);
        mQVBoxLayout->addWidget(dispLabel);
        QWidget* tmpWidget = new QWidget(this);
        tmpWidget->setLayout(mQHBoxLayout);
        mQVBoxLayout->addWidget(tmpWidget);
        mQHBoxLayout->addWidget(mAnnonateCVButton);
        mQHBoxLayout->addWidget(mAnnonateYOLOButton);
    }


    void AnnonateAutoUI::Init(void)
    {

    }


}