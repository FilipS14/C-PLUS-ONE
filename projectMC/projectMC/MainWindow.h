#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "MainMenu.h"
#include "BoardWidget.h"
#include "Instruction.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void startGame();
    void showInstructions();
    void backToMenu();
    void backToMenuIntruction();

private:
    QVBoxLayout* mainLayout;
    MainMenu* mainMenu;
    BoardWidget* boardWidget;
    Instruction* pageInstructions;
};

#endif