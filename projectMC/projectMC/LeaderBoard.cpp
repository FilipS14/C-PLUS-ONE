#include "LeaderBoard.h"

LeaderBoard::LeaderBoard(QWidget* parent) :
	QMainWindow{ parent }
{
	setWindowTitle("Twixt Game");
	QWidget* mainWidget = new QWidget(this);
	QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);
	setCentralWidget(mainWidget);
}