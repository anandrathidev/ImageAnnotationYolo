#include "App.h"

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
}

