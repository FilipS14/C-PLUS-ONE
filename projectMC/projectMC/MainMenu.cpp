#include "MainMenu.h"
#include <QPushButton>
#include <QVBoxLayout>


MainMenu::MainMenu(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Twixt Game - Meniu Principal");
    resize(200, 300);

    QVBoxLayout* layout = new QVBoxLayout;

    // Adaug un spatiu vertical in partea de sus a ferestrei
    QWidget* topSpacer = new QWidget();
    topSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(topSpacer);

    startButton = new QPushButton("Începe jocul");
    instructionsButton = new QPushButton("Instrucțiuni");
    leaderboardButton = new QPushButton("LeaderBoard");

    // Setez dimensiunile butoanelor
    QSize buttonSize(200, 50);
    startButton->setFixedSize(buttonSize);
    instructionsButton->setFixedSize(buttonSize);
    leaderboardButton->setFixedSize(buttonSize);

    layout->addWidget(startButton);
    layout->addWidget(instructionsButton);
    layout->addWidget(leaderboardButton);

    // Adaug un spatiu vertical in partea de jos a ferestrei
    QWidget* bottomSpacer = new QWidget();
    bottomSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(bottomSpacer);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);  
}

void MainMenu::startGame() {

}

void MainMenu::showInstructions() {

}