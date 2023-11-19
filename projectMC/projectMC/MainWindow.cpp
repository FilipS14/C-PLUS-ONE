#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{ parent } {
	mainLayout = new QVBoxLayout;
	mainMenu = new MainMenu(this);
	boardWidget = new BoardWidget(this);

	mainLayout->addWidget(mainMenu);
	mainLayout->addWidget(boardWidget);

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);

	connect(mainMenu, SIGNAL(startGameSignal()), this, SLOT(startGame()));
	connect(mainMenu, SIGNAL(showInstructionsSignal()), this, SLOT(showInstructions()));
	
	mainMenu->show();
	boardWidget->hide();
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