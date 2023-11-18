	#pragma once
#include<QMainWindow>
#include "MainMenu.h"
#include "BoardWidget.h"

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);
private:
	MainMenu* m_menu;
	BoardWidget* m_board;
};