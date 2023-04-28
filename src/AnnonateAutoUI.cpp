
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
#include <QScrollArea>
#include <QTextEdit>
#include <opencv2/opencv.hpp>

#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"

namespace IANN
{

    AnnonateAutoUI::AnnonateAutoUI(ImageFile* imageFile) :QDialog{}
    {
        //mImage = new QImage(this);
        mQVBoxLayout = new QVBoxLayout{ this };
        this->setLayout(mQVBoxLayout);
        QScrollArea* mMainSaveScrollArea = new QScrollArea(this );
        mMainSaveScrollArea->setWidgetResizable(true);
        mMainSaveScrollArea->setFrameShape(QFrame::NoFrame);
        mMainSaveScrollArea->setBackgroundRole(QPalette::Dark);
        mQVBoxLayout->addWidget(mMainSaveScrollArea);

        mQVBoxLayoutInner = new QVBoxLayout{ mMainSaveScrollArea };
        mMainSaveScrollArea->setLayout(mQVBoxLayoutInner);

        mAnnonateCVButton = new QPushButton{"AnnonateCV", mMainSaveScrollArea};
        mAnnonateYOLOButton = new QPushButton{ "AnnonateYOLO", mMainSaveScrollArea};
        mNextFrameButton = new QPushButton{ "NextFrame", mMainSaveScrollArea};
        mProcessFrames = new QPushButton{ "ProcessFrames", mMainSaveScrollArea};
        mInfo = new QTextEdit{ mMainSaveScrollArea };

        const cv::Mat* mat = imageFile->ReadNextFrame();
        QImage convert{ mat->data, mat->cols, mat->rows, QImage::Format_RGB888 };
        mDispLabel = new QLabel{ mMainSaveScrollArea };
        mDispLabel->setPixmap(QPixmap::fromImage(convert));
        mDispLabelProcessed = new QLabel{ mMainSaveScrollArea };
        mDispLabelProcessed->setPixmap(QPixmap::fromImage(convert));

        mQHBoxLayoutImage = new QHBoxLayout{ mMainSaveScrollArea };

        mQVBoxLayoutInner->addLayout(mQHBoxLayoutImage);
        mQHBoxLayoutImage->addWidget(mDispLabel);
        mQHBoxLayoutImage->addWidget(mDispLabelProcessed);

        mQVBoxLayoutInner->addWidget(mInfo);
        QString frameinfo = "Channels:";
        frameinfo += frameinfo.asprintf("Frame Channels:%d, Dims:%d, Rows:%d, Cols:%d \n", mat->channels(), mat->dims, mat->rows, mat->cols);
        frameinfo += frameinfo.asprintf("FPS:%lf, FRAME COUNT:%lf, NEXT FRAME POS:%lf ",
            imageFile->mCapture->get(cv::CAP_PROP_FPS),
            imageFile->mCapture->get(cv::CAP_PROP_FRAME_COUNT),
            imageFile->mCapture->get(cv::CAP_PROP_POS_FRAMES)
            );

        mInfo->insertPlainText(frameinfo);

        mQHBoxLayout1 = new QHBoxLayout{ mMainSaveScrollArea };
        mQHBoxLayout2 = new QHBoxLayout{ mMainSaveScrollArea };
        mQVBoxLayoutInner->addLayout(mQHBoxLayout1);
        mQVBoxLayoutInner->addLayout(mQHBoxLayout2);

        mQHBoxLayout1->addWidget(mNextFrameButton);
        mQHBoxLayout1->addWidget(mProcessFrames);

        mQHBoxLayout2->addWidget(mAnnonateCVButton);
        mQHBoxLayout2->addWidget(mAnnonateYOLOButton);

        // connect(mAnnonateCVButton, QPushButton::released, this, AnnonateCVButtonClicked);

    }

    void AnnonateCVButtonClicked()
    {

    }

    void AnnonateAutoUI::Init(void)
    {

    }

    bool AnnonateAutoUI::areImageFeaturesTheSame(cv::Mat img1, cv::Mat img2)
    {

        //threshold to check if the left img 
        //feature coordinates are almost the same like the right one
        const float xyThreshold = 0.1;

        //-- Step 1: Detect the keypoints using SURF Detector, compute the descriptors
        int minHessian = 800; //smaller value finds more and bigger value less features
        Ptr<SURF> detector = SURF::create(minHessian);
        std::vector<KeyPoint> keypoints1, keypoints2;
        Mat descriptors1, descriptors2;

        detector->detectAndCompute(img1, noArray(), keypoints1, descriptors1);
        detector->detectAndCompute(img2, noArray(), keypoints2, descriptors2);

        //-- Step 2: Matching descriptor vectors with a FLANN based matcher
        // Since SURF is a floating-point descriptor NORM_L2 is used
        Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
        std::vector<DMatch> knn_matches;

        //no features images is not a screenshot
        if (descriptors1.empty() || descriptors2.empty()) {
            return false;
        }

        matcher->match(descriptors1, descriptors2, knn_matches, 2);
        //-- using a threshold for the distance of a match
        const float distanceThresh = 0.5;

        int matchCount = 0;

        for (size_t i = 0; i < knn_matches.size(); i++) {
            //check if distance of match is small. check if x and y in left are right image almost the same, keep in mind that a feature can be slightly different even in an image which looks the same for an human
            if (knn_matches[i].distance < distanceThresh &&
                abs(keypoints1[knn_matches[i].queryIdx].pt.x - keypoints2[knn_matches[i].trainIdx].pt.x) < xyThreshold &&
                abs(keypoints1[knn_matches[i].queryIdx].pt.y - keypoints2[knn_matches[i].trainIdx].pt.y) < xyThreshold) {
                matchCount++;
            }
        }

        //have at least 18 of those features, this works fine for me
        //but depending on the image you may need another value here
        return matchCount > 18;
    }

}
/*
#include "lite/lite.h"

    static void test_default()
    {
        std::string onnx_path = "../../../hub/onnx/cv/yolov5s.onnx";
        std::string test_img_path = "../../../examples/lite/resources/test_lite_yolov5_1.jpg";
        std::string save_img_path = "../../../logs/test_lite_yolov5_1.jpg";

        auto* yolov5 = new lite::cv::detection::YoloV5(onnx_path);
        std::vector<lite::types::Boxf> detected_boxes;
        cv::Mat img_bgr = cv::imread(test_img_path);
        yolov5->detect(img_bgr, detected_boxes);

        lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);
        cv::imwrite(save_img_path, img_bgr);

        delete yolov5;
    }
}
*/