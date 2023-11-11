#include "BoardWidget.h";

bool BoardWidget::getIsBlack() const {
	return m_isBlack;
}

void BoardWidget::setIsBlack(bool isBlack) {
	m_isBlack = isBlack;
}

void BoardWidget::onCellClicked()
{
	QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
	if (clickedButton)
	{
		if (getIsBlack())
		{
			clickedButton->setStyleSheet("background-color: black; border: 1px solid black; border-radius: 5px;");
		}
		else
		{
			clickedButton->setStyleSheet("background-color: red; border: 1px solid black; border-radius: 5px;");
		}
		setIsBlack(!getIsBlack());
	}
}

BoardWidget::BoardWidget(QWidget* parent) :
	QMainWindow{ parent }
{
	setWindowTitle("Twixt Game");
	setFixedSize(500, 500);
	m_gridLayout = new QGridLayout();
	const int row = 25;
	const int column = 25;
}