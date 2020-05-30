#include "mainwindow.hpp"

#include <QApplication>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.addNewTab(QUrl("gemini://gemini.circumlunar.space/"));

    w.show();
    return a.exec();
}
