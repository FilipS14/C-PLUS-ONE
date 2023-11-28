#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class Instruction : public QMainWindow
{
	Q_OBJECT
public:
	Instruction(QWidget* parent = nullptr);
	~Instruction() = default;
	void addBackButton(QWidget*);
signals:
	void goBackToMenuSignal();

public slots:
	void goBackToMenu();

private:
	QPushButton *goBackButton;
};
