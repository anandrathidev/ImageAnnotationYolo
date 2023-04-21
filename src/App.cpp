#include "App.h"
#include <QtWidgets/QMenuBar>

namespace IANN
{
    MainApp::MainApp(int argc, char* argv[])
    {
        mQApplication.reset(new QApplication(argc, argv));
    }

    int MainApp::RunApp()
    {
        if (mQApplication.get())
        {
            MainWindow mainwin(nullptr);
            mainwin.show();
            return mQApplication->exec();
        }
    }

    MainWindow::MainWindow(QWidget* parent) : QMainWindow{ parent }
    {
        InitMenu();
    }

    QAction& MainWindow::GetActions(QString& menuAction)
    {
        if (menuAction.compare(MENU_OPEN))
        {
            return mOpen;
        }
        if (menuAction.compare(MENU_EXPORT))
        {
            return mExport;
        }
        if (menuAction.compare(MENU_CLOSE))
        {
            return mClose;
        }
        if (menuAction.compare(MENU_EXIT))
        {
            return mExit;
        }
        if (menuAction.compare(MENU_ANNONATEBOX))
        {
            return mAnnonateBox;
        }
        if (menuAction.compare(MENU_ANNONATESEG))
        {
            return mAnnonateSeg;
        }
    }

    void MainWindow::HandleNewFile()
    {
    }

    void MainWindow::HandleOpen()
    {
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
        mExport.setText(tr(MENU_EXPORT));;
        mClose.setText(tr(MENU_CLOSE));;
        mExit.setText(tr(MENU_EXIT));;
        mAnnonateBox.setText(tr(MENU_ANNONATEBOX));;
        mAnnonateSeg.setText(tr(MENU_ANNONATESEG));;

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

        QMenuBar * pMenubar = menuBar();
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

}

