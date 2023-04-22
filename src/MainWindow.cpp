
#include "App.h"
#include <core/IANNErrors.h>
#include <exception>


#include <QtWidgets/QMenuBar>
#include <QFileDialog>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace IANN
{
    MainWindow::MainWindow(QWidget* parent) : QMainWindow{ parent }
    {
        QFrame* qf = new QFrame(this);
        QVBoxLayout* vbox = new QVBoxLayout(this);
        qf->setLayout(vbox);
        QHBoxLayout* hbox = new QHBoxLayout(this);
        // Crate widgets
        {

        }


        InitMenu();
    }

    QAction& MainWindow::GetActions(QString& menuAction)
    {
        if (menuAction.compare(MENU_OPEN) == 0)
        {
            return mOpen;
        }
        if (menuAction.compare(MENU_EXPORT) == 0)
        {
            return mExport;
        }
        if (menuAction.compare(MENU_CLOSE) == 0)
        {
            return mClose;
        }
        if (menuAction.compare(MENU_EXIT) == 0)
        {
            return mExit;
        }
        if (menuAction.compare(MENU_ANNONATEBOX) == 0)
        {
            return mAnnonateBox;
        }
        if (menuAction.compare(MENU_ANNONATESEG) == 0)
        {
            return mAnnonateSeg;
        }
        if (menuAction.compare(MENU_HELP) == 0)
        {
            return mAnnonateSeg;
        }
        if (menuAction.compare(MENU_ABOUT) == 0)
        {
            return mAnnonateSeg;
        }
    }

    void MainWindow::HandleNewFile()
    {
    }

    void MainWindow::HandleOpen()
    {
        if (mImageFile.get())
        {
            mImageFile->Close();
            mImageFile.reset();
        }

        QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "", tr("Video Files (*.mp4 *.mov  *.wmv  *.avi )"));
        
        std::string sfileName = qPrintable(fileName);
        if (!sfileName.empty())
        {
            mImageFile.reset(new ImageFile(sfileName));
        }
    }

    void MainWindow::HandleExport()
    {
    }

    void MainWindow::HandleClose()
    {
    }

    void MainWindow::HandleExit()
    {
    }

    void MainWindow::HandleAnnonateBox()
    {
    }

    void MainWindow::HandleAnnonateSeg()
    {
    }


    void MainWindow::InitMenu()
    {
        mOpen.setText(tr(MENU_OPEN));
        mExport.setText(tr(MENU_EXPORT));
        mClose.setText(tr(MENU_CLOSE));
        mExit.setText(tr(MENU_EXIT));
        mAnnonateBox.setText(tr(MENU_ANNONATEBOX));
        mAnnonateSeg.setText(tr(MENU_ANNONATESEG));
        mHelp.setText(tr(MENU_HELP));
        mAbout.setText(tr(MENU_ABOUT));

        connect(&mOpen, &QAction::triggered, this, &MainWindow::HandleOpen);
        connect(&mExport, &QAction::triggered, this, &MainWindow::HandleExport);
        connect(&mClose, &QAction::triggered, this, &MainWindow::HandleClose);
        connect(&mExit, &QAction::triggered, this, &MainWindow::HandleExit);
        connect(&mAnnonateBox, &QAction::triggered, this, &MainWindow::HandleAnnonateBox);
        connect(&mAnnonateSeg, &QAction::triggered, this, &MainWindow::HandleAnnonateSeg);

        std::list < MenuHirarchy> tMmenu{
            {"File",{ MENU_OPEN, MENU_CLOSE , MENU_EXPORT, MENU_EXIT } },
            {"Process", { MENU_ANNONATEBOX, MENU_ANNONATESEG } },
            {"Help", {MENU_HELP, MENU_ABOUT} }
        };

        QMenuBar* pMenubar = menuBar();
        for (auto& item : tMmenu)
        {
            QMenu* iMenu = pMenubar->addMenu(item.MainMenuName);
            for (auto& subitem : item.SubMenuList)
            {
                QAction& action = GetActions(subitem);
                iMenu->addAction(&action);
            }

        }

    }

    int QTmain(int argc, char* argv[])
    {
        try
        {
            MainApp mainapp(argc, argv);
            // blocking
            mainapp.RunApp();
        }
        catch (std::exception& e)
        {
            return ERRORSCODE::QTFAILED;
        }
        return 0;

    }
}