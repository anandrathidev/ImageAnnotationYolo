#pragma once

#include <QtWidgets/QMenuBar>
#include <QDialog>

class QLabel;
class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QLabel;
class QScrollArea;
class QTextEdit;
namespace IANN
{
    class ImageFile;
    class AnnonateAutoUI : public QDialog
    {

    public:
        AnnonateAutoUI() = delete;
        explicit AnnonateAutoUI(ImageFile* imageFile);
        //~AnnonateAutoUI() {};

    
    private:
        void Init(void);
        QImage* mImage;
        QImage* mImageProcessed;

        QPushButton* mNextFrameButton;
        QPushButton* mProcessFrames;
        QPushButton* mAnnonateCVButton;
        QPushButton* mAnnonateYOLOButton;

        QLabel* mDispLabel;
        QLabel* mDispLabelProcessed;

        QTextEdit* mInfo;
        QWidget* mtmpWidget;

        QScrollArea* mMainSaveScrollArea;
        QHBoxLayout* mQHBoxLayoutImage;
        QHBoxLayout* mQHBoxLayout1;
        QHBoxLayout* mQHBoxLayout2;

        QVBoxLayout* mQVBoxLayout;
        QVBoxLayout* mQVBoxLayoutInner;

    public Q_SLOTS:
        void AnnonateCVButtonClicked();

    private:

    };

}