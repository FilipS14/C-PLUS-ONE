#include "MainMenu.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>


MainMenu::MainMenu(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Twixt Game - Meniu Principal");

    QWidget* mainWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget); // Creez layout vertical
    QHBoxLayout* centerLayout = new QHBoxLayout;           // Creez layout orizontal

    mainLayout->setContentsMargins(0, 250, 0, 0);

    QLabel* logoLabel = new QLabel(mainWidget);
    QPixmap logoPixMap("/Users/Filip/Desktop/facultate/LogoTwixt.png");
    logoLabel->setPixmap(logoPixMap.scaledToWidth(200));

    logoLabel->setGeometry(265, 70, 200, 200);

    // Stilizez butoanele folosind CSS
    QString buttonStyle = "QPushButton {"
        "background-color: #D2691E;"
        "border: 3px solid #000000;"
        "color: #ffffff;"
        "font: Bold;"
        "font-size: 40px;"
        "padding: 10px 20px;"
        "}"
        "QPushButton:hover {"
        "background-color: #DEB887;"
        "}";

    startButton = new QPushButton("Start Game");
    optionsButton = new QPushButton("Options");
    instructionsButton = new QPushButton("Instructions");
    leaderboardButton = new QPushButton("LeaderBoard");
    

    startButton->setStyleSheet(buttonStyle);
    optionsButton->setStyleSheet(buttonStyle);
    instructionsButton->setStyleSheet(buttonStyle);
    leaderboardButton->setStyleSheet(buttonStyle);
    

    // Setez dimensiunile butoanelor
    QSize buttonSize(400, 85);
    startButton->setFixedSize(buttonSize);
    optionsButton->setFixedSize(buttonSize);
    instructionsButton->setFixedSize(buttonSize);
    leaderboardButton->setFixedSize(buttonSize);

    // Adaug butoanele intr-un layout vertical
    mainLayout->addWidget(startButton);
    mainLayout->addWidget(optionsButton);
    mainLayout->addWidget(instructionsButton);
    mainLayout->addWidget(leaderboardButton);

    // Conectez butoanele la functiile corespunzatoare
    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(optionsButton, SIGNAL(clicked()), this, SLOT(showOption()));
    connect(instructionsButton, SIGNAL(clicked()), this, SLOT(showInstructions()));

    mainLayout->setAlignment(Qt::AlignHCenter);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

void MainMenu::startGame() {
    emit startGameSignal();
}

void MainMenu::showInstructions() {
    emit showInstructionsSignal();
}

void MainMenu::showOptions() {
}