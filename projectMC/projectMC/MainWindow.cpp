#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{ parent } {
	mainLayout = new QVBoxLayout;
	mainMenu = new MainMenu(this);
	boardWidget = new BoardWidget(this);

	mainLayout->addWidget(mainMenu);
	mainLayout->addWidget(boardWidget);
	
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