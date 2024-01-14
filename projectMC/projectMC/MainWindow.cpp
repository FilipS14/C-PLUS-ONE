#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{ parent } {
	setWindowTitle("Twixt Game");
	std::shared_ptr<Game> sharedGame = std::make_shared<Game>();
	mainLayout = new QVBoxLayout;
	mainMenu = new MainMenu(this);
	boardWidget = new BoardWidget(this, sharedGame);
	pageInstructions = new Instruction(this);
	pageOptions = new Option(this, sharedGame);
	pageLeaderBoard = new LeaderBoard(this);

	QString backgroundStyle = "MainWindow {"
		"background-image: url(../Textures/backgroundWood.jpg);"
		"background-repeat: no-repeat;"
		"background-position: center;"
		" margin: 0;"
		"}";

	this->setStyleSheet(backgroundStyle);

	mainLayout->addWidget(mainMenu);
	mainLayout->addWidget(boardWidget);
	mainLayout->addWidget(pageInstructions);
	mainLayout->addWidget(pageOptions);
	mainLayout->addWidget(pageLeaderBoard);

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);

	connect(mainMenu, SIGNAL(startGameSignal()), this, SLOT(startGame()));
	connect(mainMenu, SIGNAL(showInstructionsSignal()), this, SLOT(showInstructions()));
	connect(mainMenu, SIGNAL(showOptionSignal()), this, SLOT(showOptions()));
	connect(mainMenu, SIGNAL(showLeaderboardSignal()), this, SLOT(showLeaderBoard()));


	connect(boardWidget, SIGNAL(backToMenuSignal()), this, SLOT(backToMenu()));
	connect(pageInstructions, SIGNAL(goBackToMenuSignalInstruction()), this, SLOT(backToMenuIntruction()));
	connect(pageOptions, SIGNAL(goBackToMenuSignalOptions()), this, SLOT(backToMenuOption()));
	connect(pageLeaderBoard, SIGNAL(goBackToMenuSignalLeaderBoard()), this, SLOT(backToMenuLeaderBoard()));
	connect(pageOptions, SIGNAL(playerSaved(const QString&)), pageLeaderBoard, SLOT(isPlayerSaved(const QString&)));

	mainMenu->show();
	boardWidget->close();
	pageInstructions->close();
	pageOptions->close();
	pageLeaderBoard->close();
	setFixedSize(750, 760);
}

MainWindow::~MainWindow() {
	delete mainMenu;
	delete boardWidget;
	delete pageInstructions;
	delete pageOptions;
	delete pageLeaderBoard;
}

void MainWindow::startGame() {
	mainMenu->close();
	boardWidget->show();
}

void MainWindow::backToMenu() {
	boardWidget->close();
	mainMenu->show();
}

void MainWindow::backToMenuIntruction() {
	pageInstructions->close();
	mainMenu->show();
}

void MainWindow::backToMenuOption()
{
	pageOptions->close();
	mainMenu->show();
}

void MainWindow::backToMenuLeaderBoard()
{
	pageLeaderBoard->close();
	mainMenu->show();
}

void MainWindow::showInstructions() {
	mainMenu->close();
	pageInstructions->show();
}

void MainWindow::showLeaderBoard() {
	mainMenu->close();
	pageLeaderBoard->show();
}

void MainWindow::showOptions() {
	mainMenu->close();
	pageOptions->show();
}