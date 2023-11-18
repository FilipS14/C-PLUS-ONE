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

void BoardWidget::removePiece(int row, int col)
{
	board.setValue(row, col, 0);
}

BoardWidget::BoardWidget(QWidget* parent) :
	QMainWindow{ parent }
{
	setWindowTitle("Twixt Game");
	setFixedSize(500, 500);
	m_gridLayout = new QGridLayout();
	const int row = 25;
	const int column = 25;

	for (size_t i = 0; i < row; ++i)
	{
		QList<QPushButton*>rowButtons;
		for (size_t j = 0; j < column; ++j)
		{
			QPushButton* cellButton = new QPushButton(this);
			connect(cellButton, &QPushButton::clicked, this, &BoardWidget::onCellClicked);
			m_gridLayout->addWidget(cellButton, i, j);
			rowButtons.append(cellButton);
		}
		m_boardCells.append(rowButtons);
	}
	QWidget* mainWidget = new QWidget();
	mainWidget->setLayout(m_gridLayout);
	setCentralWidget(mainWidget);
}