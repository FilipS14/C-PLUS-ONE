#include "projectMC.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    projectMC w;
    w.show();
    return a.exec();
}
