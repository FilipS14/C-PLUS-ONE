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
	m_backButton = new QPushButton(widget);
	m_backButton->setStyleSheet(buttonStyle);
	m_backButton->setGeometry(10, 10, 30, 30);
	connect(m_backButton, SIGNAL(clicked()), this, SLOT(backToMenu()));
}

bool BoardWidget::getIsBlack() const {
	return m_isBlack;
}

void BoardWidget::setIsBlack(bool isBlack) {
	m_isBlack = isBlack;
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

	const uint8_t number = 24;

	for (uint8_t num = 1; num <= number; num++) {
		QString letter = QChar('A' + num - 1);
		painter.drawText(94 + num * 22, 100, 13, 15, Qt::AlignCenter, letter);
		painter.drawText(94 + num * 22, 633, 13, 15, Qt::AlignCenter, letter);

		painter.drawText(102, 94 + num * 22, 12, 12, Qt::AlignCenter, QString::number(num));
		painter.drawText(635, 94 + num * 22, 12, 12, Qt::AlignCenter, QString::number(num));
	}
}
//----------------------------------------------------

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

//---------------------------------------------------------------------------------------------

bool BoardWidget::isCornerCell(size_t row, size_t col) const {
	return (row == 0 && col == 0) || (row == m_boardCells.size() - 1 && col == m_boardCells[0].size() - 1) ||
		(row == m_boardCells.size() - 1 && col == 0) || (row == 0 && col == m_boardCells[0].size() - 1);
}

void BoardWidget::setCellStyle(QPushButton* cellButton) const
{
	QString style = "background-color: white; border: 1px solid black; border-radius: 3px;";
	cellButton->setStyleSheet(style);
}

QFrame* BoardWidget::createBoardFrame(QWidget* mainWidget) {
	QFrame* boardFrame = new QFrame(mainWidget);
	m_boardLayout = new QGridLayout(boardFrame);
	m_boardLayout->setSpacing(15);
	return boardFrame;
}

void BoardWidget::setupBoardCells()
{
	const uint8_t numRows = 24;
	const uint8_t numCols = 24;
	m_boardCells.resize(numRows, QVector<QPushButton*>(numCols, nullptr));
	for (size_t row = 0; row < numRows; row++) {
		for (size_t col = 0; col < numCols; col++) {
			if (isCornerCell(row, col)) {
				continue;
			}
			setupBoardCell(row, col);
		}
	}
}

void BoardWidget::setupBoardCell(size_t row, size_t col) {
	m_boardCells[row][col] = new QPushButton(this);
	m_boardCells[row][col]->setFixedSize(7, 7);
	setCellStyle(m_boardCells[row][col]);
	m_boardLayout->addWidget(m_boardCells[row][col], row, col);
	connect(m_boardCells[row][col], &QPushButton::clicked, this, &BoardWidget::onCellClicked);
}

void BoardWidget::addWidgetsToLayout(QVBoxLayout* mainLayout, QFrame* boardFrame) {
	mainLayout->addWidget(boardFrame, 0, Qt::AlignHCenter);
	mainLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));
}

QWidget* BoardWidget::createMainWidget() {
	return new QWidget(this);
}

QVBoxLayout* BoardWidget::createMainLayout(QWidget* mainWidget) {
	QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);
	mainLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));
	return mainLayout;
}

void BoardWidget::initializeUI(){
	setWindowTitle("Twixt Game");
	setFixedSize(750, 750);

	QWidget* mainWidget = createMainWidget();
	addBackButton(mainWidget);

	QVBoxLayout* mainLayout = createMainLayout(mainWidget);
	QFrame* boardFrame = createBoardFrame(mainWidget);

	setupBoardCells();
	addWidgetsToLayout(mainLayout, boardFrame);

	setCentralWidget(mainWidget);
}

BoardWidget::BoardWidget(QWidget* parent) :
	QMainWindow{ parent },
	m_isBlack{ false }
{
	initializeUI();
}
