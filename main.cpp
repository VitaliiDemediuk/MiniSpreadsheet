#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/images/splash_screen.png"));
    splash->show();
    MainWindow w;
    w.show();
    splash->finish(&w);
    delete splash;
    return a.exec();
}
