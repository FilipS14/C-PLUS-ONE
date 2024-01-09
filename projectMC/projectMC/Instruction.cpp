#include "Instruction.h"

Instruction::Instruction(QWidget* parent) :
	QMainWindow{parent} {
	setWindowTitle("Twixt Game");
	QWidget* mainWidget = new QWidget(this);
	addBackButton(mainWidget);
	QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);
	setCentralWidget(mainWidget);
}

void Instruction::addBackButton(QWidget* widget)
{
	goBackButton = new QPushButton(widget);
	goBackButton->setGeometry(10, 10, 40, 40);
	connect(goBackButton, SIGNAL(clicked()), this, SLOT(goBackToMenuIntruction()));
}

void Instruction::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPixmap backgroundPixmap("/Users/Filip/Desktop/facultate/anul2/signIntructions.png");
	painter.drawPixmap(20, 40, 700, 700, backgroundPixmap);
}

void Instruction::goBackToMenuIntruction() {
	emit goBackToMenuSignalInstruction();
}