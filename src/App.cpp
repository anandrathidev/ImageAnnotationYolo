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
            return mQApplication->exec();
        }
    }

    MainWindow::MainWindow(QWidget* parent) : QMainWindow{ parent }
    {
        InitMenu();
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

