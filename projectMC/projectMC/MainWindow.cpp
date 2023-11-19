#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{ parent } {
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