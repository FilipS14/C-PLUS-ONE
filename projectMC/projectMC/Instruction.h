#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QLabel>

class Instruction : public QMainWindow
{
	Q_OBJECT
public:
	Instruction(QWidget* parent = nullptr);
	~Instruction() = default;
public slots:
	void backToMenu();

private:
	
};
