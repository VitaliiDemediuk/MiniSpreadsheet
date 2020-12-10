#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QSharedPointer>
#include <QTest>

#include "parser.h"

#include "test_lexer.h"
#include "test_cell_getvalue.h"
#include "test_cell_getvisibletext.h"

#include "lexer.h"
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

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
    w.PrepareTable();

    {
        Test_Lexer test1;
        QTest::qExec(&test1, argc, argv);
        Test_Cell_GetVisibleText test2;
        QTest::qExec(&test2, argc, argv);
        Test_Cell_GetValue test3;
        QTest::qExec(&test3, argc, argv);
    }

    w.show();
    splash->finish(&w);
    delete splash;
    return a.exec();
}
