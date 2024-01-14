#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "MainMenu.h"
#include "BoardWidget.h"
#include "Instruction.h"
#include "Option.h"
#include "LeaderBoard.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;

public slots:
    void startGame();
    void showInstructions();
    void showLeaderBoard();
    void showOptions();
    void backToMenu();
    void backToMenuIntruction();
    void backToMenuOption();
    void backToMenuLeaderBoard();

private:
    QVBoxLayout* mainLayout;
    std::unique_ptr<MainMenu> m_mainMenu;
    std::unique_ptr <BoardWidget> m_boardWidget;
    std::unique_ptr <Instruction> m_pageInstructions;
    std::unique_ptr <Option> m_pageOptions;
    std::unique_ptr <LeaderBoard> m_pageLeaderBoard;
};

#endif