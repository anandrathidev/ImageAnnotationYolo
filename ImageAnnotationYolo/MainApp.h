#pragma once

#include <QtWidgets/QMainWindow>

class QCoreApplication;

namespace IANN
{
    class MainApp
    {
    public:
        MainApp() = delete;
        MainApp(int argc, char* argv[]);
        void RunApp();
    private:
        QCoreApplication* mQCoreApplication;

    };

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow() = delete;
        explicit MainWindow(QWidget* parent = 0);
        ~MainWindow() {};

    private:
        void InitMenu(void);

    private:
        QStringList mMainMenuList;
    };

}
