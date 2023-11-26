#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{ parent } {
	setWindowTitle("Twixt Game");
	mainLayout = new QVBoxLayout;
	mainMenu = new MainMenu(this);
	boardWidget = new BoardWidget(this);

	QString backgroundStyle = "MainWindow {"
		"background-image: url(/Users/Filip/Desktop/facultate/anul2/sem1/mc/backgroundWood.jpg);"
		"background-repeat: no-repeat;"
		"background-position: center;"
		" margin: 0;"
		"}";

	this->setStyleSheet(backgroundStyle);

	mainLayout->addWidget(mainMenu);
	mainLayout->addWidget(boardWidget);

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);

	connect(mainMenu, SIGNAL(startGameSignal()), this, SLOT(startGame()));
	connect(mainMenu, SIGNAL(showInstructionsSignal()), this, SLOT(showInstructions()));
	
	mainMenu->show();
	boardWidget->hide();
	setFixedSize(750, 750);
}

MainWindow::~MainWindow() {
	delete mainMenu;
	delete boardWidget;
}

void MainWindow::startGame() {
	mainMenu->hide();
	boardWidget->show();
}

void MainWindow::showInstructions() {

}