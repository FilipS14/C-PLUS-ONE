#include "BoardWidget.h";

void BoardWidget::backToMenu() {
	emit backToMenuSignal();
}

void BoardWidget::addBackButton(QWidget* widget) {
	QString buttonStyle = "QPushButton {"
		"background-color: #D2691E;"
		"background-image: url(/Users/Filip/Desktop/facultate/backToMenu.jpg);"
		"border: 2px solid #000000;"
		"color: #ffffff;"
		"font: Bold;"
		"font-size: 40px;"
		"padding: 10px 20px;"
		"}"
		"QPushButton:hover {"
		"background-color: #DEB887;"
		"}";
	backButton = new QPushButton(widget);
	backButton->setStyleSheet(buttonStyle);
	backButton->setGeometry(10, 10, 30, 30);
	connect(backButton, SIGNAL(clicked()), this, SLOT(backToMenu()));
}

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
			clickedButton->setStyleSheet("background-color: black; border: 1px solid black; border-radius: 10px;");
		}
		else
		{
			clickedButton->setStyleSheet("background-color: red; border: 1px solid black; border-radius: 7px;");
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
	painter.fillRect(100, 100, 550, 550, "#deb887");
	painter.setPen(QPen(Qt::red, 2));
	painter.drawLine(140, 134, 610, 134);//prima linie rosie
	painter.drawLine(140, 617, 610, 617);//a doua line rosie
	painter.setPen(QPen(Qt::black, 2));
	painter.drawLine(133, 142, 133, 608);//prima linie negra
	painter.drawLine(617, 142, 617, 608);// a doua linie neagra

	const uint8_t number = 25;

	for (uint8_t num = 1; num <= number; num++) {
		QString letter = QChar('A' + num - 1);
		painter.drawText(95 + num * 21, 100, 13, 15, Qt::AlignCenter, letter);
		painter.drawText(95 + num * 21, 633, 13, 15, Qt::AlignCenter, letter);

		painter.drawText(102, 95 + num * 21, 12, 12, Qt::AlignCenter, QString::number(num));
		painter.drawText(635, 95 + num * 21, 12, 12, Qt::AlignCenter, QString::number(num));
	}
}

BoardWidget::BoardWidget(QWidget* parent) :
	QMainWindow{ parent }
{
	setWindowTitle("Twixt Game");
	setFixedSize(750, 750);

	QWidget* mainWidget = new QWidget(this);//creez un widget principal

	addBackButton(mainWidget);

	QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);//creez un layout vertical pentru widgetul principal

	mainLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));//adaug un spatiu in partea de sus a layout ului

	QFrame* boardFrame = new QFrame(mainWidget);//aici pun grid-ul cu celule

	boardLayout = new QGridLayout(boardFrame);//creez un gridlayout pentru boardFrame
	
	boardLayout->setSpacing(15);
	const uint8_t numRows = 25;
	const uint8_t numCols = 25;
	m_boardCells.resize(numRows, QVector<QPushButton*>(numCols));

	for (size_t row = 0; row < numRows; row++) {
		for (size_t col = 0; col < numCols; col++) {
			if ((row == 0 && col == 0) || (row == numRows - 1 && col == numCols - 1) || (row == numRows - 1 && col == 0) || (row == 0 && col == numCols - 1)) {
				continue;
			}
			m_boardCells[row][col] = new QPushButton(mainWidget);
			m_boardCells[row][col]->setFixedSize(7, 7);
			m_boardCells[row][col]->setStyleSheet("background-color: white; border: 1px solid black; border-radius: 3px;");
			boardLayout->addWidget(m_boardCells[row][col], row, col);

			connect(m_boardCells[row][col], &QPushButton::clicked, this, &BoardWidget::onCellClicked);
		}
	}

	mainLayout->addWidget(boardFrame, 0, Qt::AlignHCenter); // adaug frameul cu gridul in layoutul vertical al widget-ului principal si se centreaza orizontal


	mainLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));//adaug un spatiu in partea de jos a layoutului

	
	setCentralWidget(mainWidget);
}