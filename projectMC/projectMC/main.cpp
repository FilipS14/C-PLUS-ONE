#include "projectMC.h"
#include <QtWidgets/QApplication>
#include"MainMenu.h"
#include"BoardWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    return a.exec();
}
