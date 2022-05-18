#include <QtGui/QApplication>
#include <GUI/mainwindow.h>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(recursos);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
