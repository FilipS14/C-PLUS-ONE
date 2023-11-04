/********************************************************************************
** Form generated from reading UI file 'projectMC.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTMC_H
#define UI_PROJECTMC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_projectMCClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *projectMCClass)
    {
        if (projectMCClass->objectName().isEmpty())
            projectMCClass->setObjectName("projectMCClass");
        projectMCClass->resize(600, 400);
        menuBar = new QMenuBar(projectMCClass);
        menuBar->setObjectName("menuBar");
        projectMCClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(projectMCClass);
        mainToolBar->setObjectName("mainToolBar");
        projectMCClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(projectMCClass);
        centralWidget->setObjectName("centralWidget");
        projectMCClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(projectMCClass);
        statusBar->setObjectName("statusBar");
        projectMCClass->setStatusBar(statusBar);

        retranslateUi(projectMCClass);

        QMetaObject::connectSlotsByName(projectMCClass);
    } // setupUi

    void retranslateUi(QMainWindow *projectMCClass)
    {
        projectMCClass->setWindowTitle(QCoreApplication::translate("projectMCClass", "projectMC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class projectMCClass: public Ui_projectMCClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTMC_H
