#include "MainMenu.h"
#include <QPushButton>
#include <QVBoxLayout>


MainMenu::MainMenu(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Twixt Game - Meniu Principal");
    resize(200, 300);

    QVBoxLayout* layout = new QVBoxLayout;

    startButton = new QPushButton("Începe jocul");
    instructionsButton = new QPushButton("Instrucțiuni");
    leaderboardButton = new QPushButton("LeaderBoard");

    layout->addWidget(startButton);
    layout->addWidget(instructionsButton);
    layout->addWidget(leaderboardButton);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);  
}

void MainMenu::startGame() {

}

void MainMenu::showInstructions() {

}