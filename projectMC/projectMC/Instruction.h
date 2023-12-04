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
private:
	void addBackButton(QWidget*);

signals:
	void goBackToMenuSignalInstruction();

public slots:
	void goBackToMenuIntruction();

private:
	QPushButton *goBackButton;

};
