#include "projectMC.h"
#include <QtWidgets/QApplication>
#include"MainMenu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu menu;
    menu.show();
    return a.exec();
}
