#include "MainMenu.h"
#include <QPushButton>
#include <QVBoxLayout>


MainMenu::MainMenu(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Twixt Game - Meniu Principal");

    QWidget* mainWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget); // Creez layout vertical
    QHBoxLayout* centerLayout = new QHBoxLayout;           // Creez layout orizontal

    mainLayout->setContentsMargins(0, 200, 0, 0);


    QString backgroundStyle = "MainMenu {"
        "background-image: url(/Users/Filip/Desktop/facultate/anul2/sem1/mc/wood.jpg);"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "}";

    this->setStyleSheet(backgroundStyle);

    // Stilizez butoanele folosind CSS
    QString buttonStyle = "QPushButton {"
        "background-color: #D2691E;"
        "border: 1px solid #000000;"
        "color: #ffffff;"
        "font-size: 18px;"
        "padding: 10px 20px;"
        "}"
        "QPushButton:hover {"
        "background-color: #DEB887;"
        "}";

    startButton = new QPushButton("Start Game");
    instructionsButton = new QPushButton("Instructions");
    leaderboardButton = new QPushButton("LeaderBoard");

    startButton->setStyleSheet(buttonStyle);
    instructionsButton->setStyleSheet(buttonStyle);
    leaderboardButton->setStyleSheet(buttonStyle);

    // Setez dimensiunile butoanelor
    QSize buttonSize(200, 50);
    startButton->setFixedSize(buttonSize);
    instructionsButton->setFixedSize(buttonSize);
    leaderboardButton->setFixedSize(buttonSize);

    mainLayout->addWidget(startButton);
    mainLayout->addWidget(instructionsButton);
    mainLayout->addWidget(leaderboardButton);

    // Adaug un spatiu vertical in partea de jos a ferestrei
    QWidget* bottomSpacer = new QWidget();
    bottomSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(bottomSpacer);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Conectez butoanele la functiile corespunzatoare
    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(instructionsButton, SIGNAL(clicked()), this, SLOT(showInstructions()));
}

void MainMenu::startGame() {
    emit startGameSignal();
}

void MainMenu::showInstructions() {
    emit showInstructionsSignal();
}