#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{ parent } {
	setWindowTitle("Twixt Game");
	mainLayout = new QVBoxLayout;
	mainMenu = new MainMenu(this);
	boardWidget = new BoardWidget(this);
	pageInstructions = new Instruction(this);
	pageOptions = new Option(this);

	QString backgroundStyle = "MainWindow {"
		"background-image: url(/Users/Filip/Desktop/facultate/anul2/sem1/mc/backgroundWood.jpg);"
		"background-repeat: no-repeat;"
		"background-position: center;"
		" margin: 0;"
		"}";

	this->setStyleSheet(backgroundStyle);

	mainLayout->addWidget(mainMenu);
	mainLayout->addWidget(boardWidget);
	mainLayout->addWidget(pageInstructions);
	mainLayout->addWidget(pageOptions);

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);

	connect(mainMenu, SIGNAL(startGameSignal()), this, SLOT(startGame()));
	connect(mainMenu, SIGNAL(showInstructionsSignal()), this, SLOT(showInstructions()));
	connect(mainMenu, SIGNAL(showOptionSignal()), this, SLOT(showOptions()));

	connect(boardWidget, SIGNAL(backToMenuSignal()), this, SLOT(backToMenu()));
	connect(pageInstructions, SIGNAL(goBackToMenuSignalInstruction()), this, SLOT(backToMenuIntruction()));
	connect(pageOptions, SIGNAL(goBackToMenuSignalOptions()), this, SLOT(backToMenuOption()));

	mainMenu->show();
	boardWidget->hide();
	pageInstructions->hide();
	pageOptions->hide();
	setFixedSize(750, 750);
}

MainWindow::~MainWindow() {
	delete mainMenu;
	delete boardWidget;
	delete pageInstructions;
	delete pageOptions;
}

void MainWindow::startGame() {
	mainMenu->hide();
	boardWidget->show();
}

void MainWindow::backToMenu() {
	boardWidget->hide();
	mainMenu->show();
}

void MainWindow::backToMenuIntruction() {
	pageInstructions->hide();
	mainMenu->show();
}

void MainWindow::backToMenuOption()
{
	pageOptions->hide();
	mainMenu->show();
}

void MainWindow::showInstructions() {
	mainMenu->hide();
	pageInstructions->show();
}

void MainWindow::showOptions() {
	mainMenu->hide();
	pageOptions->show();
}