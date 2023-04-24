#pragma once

#include <QtWidgets/QMenuBar>
#include <QDialog>

class QLabel;
class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QLabel;
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
        QPushButton* mAnnonateCVButton;
        QPushButton* mAnnonateYOLOButton;
        QLabel* dispLabel;
        QHBoxLayout* mQHBoxLayout;
        QVBoxLayout* mQVBoxLayout;

    public slots:

    private:

    };

}