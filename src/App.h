#pragma once

#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <memory>

class QApplication;

namespace IANN
{
    class MainApp
    {
    public:
        MainApp() = delete;
        MainApp(int argc, char* argv[]);
        int RunApp();
    private:
        std::unique_ptr<QApplication> mQApplication;
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
