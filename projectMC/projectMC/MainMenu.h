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

public slots:
    void startGame();
    void showInstructions();

private:
    QPushButton* startButton;
    QPushButton* instructionsButton;
    QPushButton* leaderboardButton;
};
