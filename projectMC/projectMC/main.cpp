#include "projectMC.h"
#include <QtWidgets/QApplication>
#include "MainMenu.h"
#include "BoardWidget.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBaseManager data;
    data.resetDatabase();
    MainWindow w;
    w.show();
    return a.exec();
}
