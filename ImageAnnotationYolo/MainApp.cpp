#include "MainApp.h"
#include <QCoreApplication>
#include <QtWidgets/QMenuBar>

namespace IANN
{
    MainApp::MainApp(int argc, char* argv[])
    {
        mQCoreApplication = new QCoreApplication(argc, argv);
    }

    void MainApp::RunApp()
    {
        if (mQCoreApplication)
        {
            MainWindow mainwin(nullptr);
            mQCoreApplication->exec();

        }
    }

    void MainWindow::InitMenu()
    {
        mMainMenuList.append("File");

        QMenuBar* pMenubar =  menuBar();
        for (auto& item : mMainMenuList)
        {
            pMenubar->addMenu(item);
        }

    }

}

