#include "BoardWidget.h";

//Button
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
	m_backButton.setStyleSheet(buttonStyle);
	m_backButton.setGeometry(10, 10, 30, 30);
	
	connect(&m_backButton, &QPushButton::clicked, this, &BoardWidget::backToMenu);
}

//Game handle
void BoardWidget::paintEvent(QPaintEvent* event) {
	drawBoard();
	drawCells();
	drawLettersFromBoard();
	drawPillars();
	drawBirdges();
}

void BoardWidget::mousePressEvent(QMouseEvent* event) {
	constexpr uint32_t cellSize{ 15 };
	int32_t mouseX = event->x();
	int32_t mouseY = event->y();

	for (auto& line : game.getBoard().getMatrix()) {
		for (auto& cellCenter : line) {
			uint32_t distance = calculateDistance(cellCenter.getCoordinates(), QPoint(mouseX, mouseY));

			if (distance <= cellSize / 2) {
				processClickEvent(cellCenter, event->button());
				update();
				return;
			}
		}
	}
}

//Draw
bool BoardWidget::isCorner(size_t row, size_t col, uint8_t line, uint8_t column)
{
	return (row == line - 1 && col == column - 1) ||
		(row == 0 && col == 0) ||
		(row == line - 1 && col == 0) ||
		(row == 0 && col == column - 1);
}

void BoardWidget::drawBoard()
{
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
}