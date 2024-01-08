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
