#pragma once
#include <QMainWindow>
#include<qpushbutton.h>


class MainMenu : public QMainWindow {
    Q_OBJECT

public:
    MainMenu(QWidget* parent = nullptr);

signals:
    void startGameSignal();
    void showInstructionsSignal();
    void showOptionSignal();
    void showLeaderboardSignal();

public slots:
    void startGame();
    void showInstructions();
    void showOptions();
    void showLeaderboard();

private:
    QPushButton* startButton;
    QPushButton* instructionsButton;
    QPushButton* leaderboardButton;
    QPushButton* optionsButton;
};
