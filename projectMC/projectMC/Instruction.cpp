#include "Instruction.h"

Instruction::Instruction(QWidget* parent) :
	QMainWindow{parent} {
	setWindowTitle("Twixt Game");
	QWidget* mainWidget = new QWidget(this);
	QLabel* label1 = new QLabel("Twixt is a strategy game where two players strive\n to connect opposite sides of the board. Players\n    take turns placing a peg in an empty space\n   and creating bridges between adjacent pegs.", mainWidget);
	label1->setGeometry(195, 282, 360, 120);
	label1->setFont(QFont("Arial", 13));
	label1->setStyleSheet("color: black;");

	QLabel* label2 = new QLabel("Victory goes to the player who successfully\n  forms the first complete bridge spanning\n   from one end of the board to the other.", mainWidget);
	label2->setGeometry(190, 440, 360, 120);
	label2->setFont(QFont("Arial", 14));
	label2->setStyleSheet("color: black;");

	QLabel* label3 = new QLabel("      With left click you can add a peg \n    With right click you can add bridges \nWith middle click you can remove bridges", mainWidget);
	label3->setGeometry(200, 595, 360, 120);
	label3->setFont(QFont("Arial", 14));
	label3->setStyleSheet("color: black;");

	addBackButton(mainWidget);

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
	QPixmap backgroundPixmap("../Textures/signIntructions.png");
	painter.drawPixmap(20, 40, 700, 700, backgroundPixmap);
}

void Instruction::goBackToMenuIntruction() {
	emit goBackToMenuSignalInstruction();
}