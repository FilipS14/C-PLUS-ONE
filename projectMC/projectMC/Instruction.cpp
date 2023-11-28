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
	connect(goBackButton, SIGNAL(clicked()), this, SLOT(goBackToMenu()));
}

void Instruction::goBackToMenu() {
	emit goBackToMenuSignal();
}