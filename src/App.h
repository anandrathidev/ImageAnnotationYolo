#pragma once

#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QAction>

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

    struct  MenuHirarchy
    {
        QString MainMenuName;
        std::list<QString> SubMenuList;
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
        QAction& GetActions(QString& menuAction);

    public slots:
        void HandleNewFile();
        void HandleOpen();
        void HandleExport();
        void HandleClose();
        void HandleExit();
        void HandleAnnonateBox();
        void HandleAnnonateSeg();

    private:
        MenuHirarchy mMenuHirarchy;

        QAction mNewFile;
        QAction mOpen;
        QAction mExport;
        QAction mClose;
        QAction mExit;
        QAction mAnnonateBox;
        QAction mAnnonateSeg;

    };
}

#define MENU_OPEN "Open"
#define MENU_CLOSE "Close"
#define MENU_EXPORT "Export"
#define MENU_EXIT "Exit" 
#define MENU_ANNONATEBOX "AnnonateBox"
#define MENU_ANNONATESEG "AnnonateSeg"
#define MENU_HELP "Help"
#define MENU_ABOUT "About"