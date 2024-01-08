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

	for (auto& line : m_game.getBoard().getMatrix()) {
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

void BoardWidget::setupBoardCells()
{
	constexpr uint8_t numRows{ 24 };
	constexpr uint8_t numCols{ 24 };

	auto rowRange = std::views::iota(size_t{ 0 }, numRows);
	auto colRange = std::views::iota(size_t{ 0 }, numCols);

	for (const auto& row : rowRange) {
		for (const auto& col : colRange)
		{
			if (!isCorner(row, col, numRows, numCols)) {
				setupBoardCell(row, col);
			}
		}
	}
}

void BoardWidget::setupBoardCell(size_t row, size_t col) {
	const uint32_t cellSize = 15;
	const uint32_t cellSpacing = 7;

	uint32_t  x = 112 + col * (cellSize + cellSpacing);
	uint32_t y = 112 + row * (cellSize + cellSpacing);

	QPoint point;
	point.setX(x + cellSize / 2);
	point.setY(y + cellSize / 2);
	m_game.getBoard().addCell(row, col, point);
}

void BoardWidget::drawLettersFromBoard()
{
	QPainter painter(this);
	const uint8_t number = 24;
	for (uint8_t num = 1; num <= number; num++) {
		QString letter = QChar('A' + num - 1);
		painter.drawText(94 + num * 22, 100, 13, 15, Qt::AlignCenter, letter);
		painter.drawText(94 + num * 22, 633, 13, 15, Qt::AlignCenter, letter);

		painter.drawText(102, 94 + num * 22, 12, 12, Qt::AlignCenter, QString::number(num));
		painter.drawText(635, 94 + num * 22, 12, 12, Qt::AlignCenter, QString::number(num));
	}
}

void BoardWidget::drawPillars()
{
	QPainter painter(this);
	auto& pillarsMap = m_game.getBoard().getPillars();

	std::ranges::for_each(pillarsMap, [&painter](const auto& pair) {
		const Pillar& pillar = pair.second;
		const uint8_t squareSize = 8;
		painter.setPen(pillar.getColor());
		painter.setBrush(pillar.getColor());
		painter.drawRect(pillar.getCoordinates().x(), pillar.getCoordinates().y(), squareSize, squareSize);
		});
}

void BoardWidget::drawBirdges()
{
	const uint8_t cellSize = 15;
	uint8_t radius = cellSize / 4;
	QPainter painter(this);

	auto& bridgesMap = m_game.getBoard().getBridges();
	std::ranges::for_each(bridgesMap, [&painter, radius](const auto& bridgePair) {
		const Bridge& bridge = bridgePair.second;
		painter.setPen(QPen(bridge.getColor(), 2));
		painter.drawLine(
			bridge.getCoordinatesStart().x() + radius, bridge.getCoordinatesStart().y() + radius,
			bridge.getCoordinatesEnd().x() + radius, bridge.getCoordinatesEnd().y() + radius);
		});
}

void BoardWidget::drawCells()
{
	const uint8_t cellSize = 15;
	const uint8_t cellRadius = cellSize / 2;
	QPainter painter(this);
	painter.setPen(Qt::black);
	for (const auto& line : m_game.getBoard().getMatrix())
	{
		std::ranges::for_each(line, [&painter, cellSize](const Cell& element) {
			if (element.getCoordinates() != QPoint())
				painter.drawEllipse(element.getCoordinates().x(), element.getCoordinates().y(), cellSize / 2, cellSize / 2);
			});
	}
}

//Swtich player
void BoardWidget::switchToRedPlayer() {

	if (m_game.switchToRedPlayer())
	{
		m_switchButtonBlack.setVisible(false);
		m_switchButtonRed.setVisible(true);
		updatePlayerStats();
	}
	else
		QMessageBox::information(nullptr, "Info", "Place a pillar before switching.");
	update();
}

void BoardWidget::switchToBlackPlayer() {
	if (m_game.switchToBlackPlayer())
	{
		m_switchButtonRed.setVisible(false);
		m_switchButtonBlack.setVisible(true);
		updatePlayerStats();
	}
	else
		QMessageBox::information(nullptr, "Info", "Place a pillar before switching.");
	update();
}

//Game initialization
BoardWidget::BoardWidget(QWidget* parent) :
	QMainWindow{ parent }
{
	initializeUI();
	m_game.initializationGame(24,24);
	setupBoardCells();
}

QWidget* BoardWidget::createMainWidget() {
	return new QWidget(this);
}

void BoardWidget::updatePlayerStats() {
	m_numberOfPillarsForRedPlayer.setText("Red Pillars: " + QString::number(m_game.getRedPlayer().getNumberOfPillars()));
	m_numberOfBridgesForRedPlayer.setText("Red Bridges: " + QString::number(m_game.getRedPlayer().getNumberOfBridges()));

	m_numberOfPillarsForBlackPlayer.setText("Black Pillars: " + QString::number(m_game.getBlackPlayer().getNumberOfPillars()));
	m_numberOfBridgesForBlackPlayer.setText("Black Bridges: " + QString::number(m_game.getBlackPlayer().getNumberOfBridges()));
}

void BoardWidget::initializeUI() {
	setWindowTitle("Twixt Game");
	setFixedSize(750, 750);

	QWidget* mainWidget = createMainWidget();
	addBackButton(mainWidget);
	setCentralWidget(mainWidget);

	createSwitchButtons(mainWidget);
	createPlayerLabels(mainWidget);
	createPlayerInfoLabels(mainWidget);
}

void BoardWidget::createSwitchButtons(QWidget* parent) {
	m_switchButtonRed.setGeometry(450, 10, 80, 80);
	connect(&m_switchButtonRed, &QPushButton::clicked, this, &BoardWidget::switchToBlackPlayer);
	m_switchButtonRed.setVisible(true);

	m_switchButtonBlack.setGeometry(450, 660, 80, 80);
	connect(&m_switchButtonBlack, &QPushButton::clicked, this, &BoardWidget::switchToRedPlayer);
	m_switchButtonBlack.setVisible(false);
}

void BoardWidget::createPlayerInfoLabels(QWidget* parent) {
	m_numberOfPillarsForRedPlayer.setText("Red Pillars:" + QString::number(m_game.getRedPlayer().getNumberOfPillars()));
	m_numberOfPillarsForRedPlayer.setGeometry(370, 25, 120, 30);
	m_numberOfPillarsForRedPlayer.setParent(parent);

	m_numberOfBridgesForRedPlayer.setText("Red Bridges:" + QString::number(m_game.getRedPlayer().getNumberOfBridges()));
	m_numberOfBridgesForRedPlayer.setGeometry(370, 60, 120, 30);
	m_numberOfBridgesForRedPlayer.setParent(parent);

	m_numberOfPillarsForBlackPlayer.setText("Black Pillars:" + QString::number(m_game.getBlackPlayer().getNumberOfPillars()));
	m_numberOfPillarsForBlackPlayer.setGeometry(360, 680, 120, 30);
	m_numberOfPillarsForBlackPlayer.setParent(parent);

	m_numberOfBridgesForBlackPlayer.setText("Black Bridges:" + QString::number(m_game.getBlackPlayer().getNumberOfBridges()));
	m_numberOfBridgesForBlackPlayer.setGeometry(360, 710, 120, 30);
	m_numberOfBridgesForBlackPlayer.setParent(parent);
}