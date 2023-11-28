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
//---------------------------------------------------------------------------------------------

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
{ initializeUI(); }