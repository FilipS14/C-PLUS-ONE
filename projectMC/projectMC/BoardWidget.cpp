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

void BoardWidget::resetBoard()
{
	board.reset();
}

void BoardWidget::removePiece(int row, int col)
{
	board.setValue(row, col, 0);
}

void BoardWidget::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 2));
	painter.drawRect(100, 100, 550, 550);
	painter.fillRect(100, 100, 550, 550, Qt::gray);
}

BoardWidget::BoardWidget(QWidget* parent) :
	QMainWindow{ parent }
{
	setWindowTitle("Twixt Game");
	setFixedSize(700, 700);
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
			//G.board.getLine();
			m_gridLayout->addWidget(cellButton, i, j);
			rowButtons.append(cellButton);
		}
		m_boardCells.append(rowButtons);
	}
	QWidget* mainWidget = new QWidget();
	mainWidget->setLayout(m_gridLayout);
	setCentralWidget(mainWidget);
}