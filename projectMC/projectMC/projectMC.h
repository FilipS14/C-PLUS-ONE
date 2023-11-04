#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_projectMC.h"

class projectMC : public QMainWindow
{
    Q_OBJECT

public:
    projectMC(QWidget *parent = nullptr);
    ~projectMC();

private:
    Ui::projectMCClass ui;
};
