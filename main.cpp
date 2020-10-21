#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    {
            qputenv("QT_DEVICE_PIXEL_RATIO", QByteArray("0"));
            qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", QByteArray("1"));
            qputenv("QT_SCREEN_SCALE_FACTORS", QByteArray("1"));
            qputenv("QT_SCALE_FACTOR", QByteArray("1"));
    }
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
