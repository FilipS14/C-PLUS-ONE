#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QPainter>



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

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	QPushButton *goBackButton;

};
