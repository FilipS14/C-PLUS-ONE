#include "BoardWidget.h";

//Button
void BoardWidget::backToMenu() {
	emit backToMenuSignal();
}

QString BoardWidget::createBackButtonStyle() {
	return "QPushButton {"
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
}

QString BoardWidget::createSwitchButtonStyle()
{
	return "QPushButton {"
		"background-color: #D2691E;"
		"border: 3px solid #000000;"
		"color: #ffffff;"
		"font: Bold;"
		"}"
		"QPushButton:hover {"
		"background-color: #DEB887;"
		"}";
}

void BoardWidget::addBackButton(QWidget* widget) {
	m_backButton = new QPushButton(widget);
	m_backButton->setStyleSheet(createBackButtonStyle());
	m_backButton->setGeometry(10, 10, 30, 30);
	connect(m_backButton, &QPushButton::clicked, this, &BoardWidget::backToMenu);

}

//Game handle
void BoardWidget::paintEvent(QPaintEvent* event) {
	drawBoard();
	drawCells();
	drawLettersFromBoard();
	drawMines();
	drawPillars();
	drawBirdges();
	drawBuldozerist();
	drawBoxForPlayer();
	drawNamePlayer();
}

void BoardWidget::drawNamePlayer() {
	QPainter painter(this);
	painter.setPen(Qt::black);
	QFont font = painter.font();
	font.setBold(true);
	painter.setFont(font);
	painter.drawText(355, 30, "Name: " + QString::fromStdString(m_game->getRedPlayer().getName()));
	painter.drawText(353, 685, "Name: " + QString::fromStdString(m_game->getBlackPlayer().getName()));
}

void BoardWidget::handleLeftButtonClick(Cell& clickedCell) {
	if (!m_game->getCurrentPlayer().getMovePillar()) {
		if (!m_game->getBoard().isValidPillarMove(clickedCell, m_game->getCurrentPlayer())) {
		}
		else if (m_game->getBoard().getMatrix()[clickedCell.getLine()][clickedCell.getColumn()].getIsMined()) {
			m_firstPlace++;
			if (m_game->redTurn()) {
				
				m_game->mineSwitchTurn(clickedCell, m_game->getCurrentPlayer());
				switchToBlackPlayer();
			}
			else {
				m_game->mineSwitchTurn(clickedCell, m_game->getCurrentPlayer());
				switchToRedPlayer();
			}
		}
		else {
			m_firstPlace++;
			m_game->placePillar(clickedCell, m_game->getCurrentPlayer());
			m_game->getBoard().generateBuldozerist();
		}
		if (m_firstPlace == 2) {
			m_switchPlayerForFirstRound->deleteLater();
		}
		updatePlayerStats();
	}
}

void BoardWidget::handleRightButtonClick(const Cell& clickedCell) {
	if (!m_selectedCell.getCoordinates().isNull()) {
		m_game->placeBridge(clickedCell, m_selectedCell, m_game->getCurrentPlayer());
		m_selectedCell = Cell();
		updatePlayerStats();
	}
	else {
		m_selectedCell = clickedCell;
	}
}

void BoardWidget::handleMiddleButtonClick(const Cell& clickedCell) {
	if (!m_selectCellForDelete.getCoordinates().isNull()) {
		m_game->getBoard().removeBridge(clickedCell, m_selectCellForDelete);
		m_selectCellForDelete = Cell();
		updatePlayerStats();
	}
	else {
		m_selectCellForDelete = clickedCell;
	}
}

int64_t BoardWidget::calculateDistance(const QPoint& point1, const QPoint& point2) {
	return qSqrt(qPow(point1.x() - point2.x(), 2) + qPow(point1.y() - point2.y(), 2));
}

void BoardWidget::processClickEvent(Cell& clickedCell, Qt::MouseButton button) {
	if (button == Qt::LeftButton) {
		handleLeftButtonClick(clickedCell);
	}
	else if (button == Qt::RightButton) {
		handleRightButtonClick(clickedCell);
	}
	else if (button == Qt::MiddleButton) {
		handleMiddleButtonClick(clickedCell);
	}
}

void BoardWidget::mousePressEvent(QMouseEvent* event) {
	constexpr uint32_t cellSize{ 15 };
	int32_t mouseX = event->x();
	int32_t mouseY = event->y();

	for (auto& line : m_game->getBoard().getMatrix()) {
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
void BoardWidget::drawBoxForPlayer() {

	QPainter painter(this);
	//red plyer box
	painter.setPen(QPen(Qt::red, 3));
	painter.fillRect(260, 3, 190, 85, "#deb887");
	painter.drawRect(260, 3, 190, 85);
	QPixmap redPlayerImage("/Users/Filip/Desktop/facultate/REDplayer.jpeg");
	painter.drawPixmap(265, 11, redPlayerImage);

	//black player box
	painter.setPen(QPen(Qt::black, 3));
	painter.fillRect(260, 657, 190, 85, "#deb887");
	painter.drawRect(260, 657, 190, 85);
	QPixmap blackPlayerImage("/Users/Filip/Desktop/facultate/BLACKplayer.jpg");
	painter.drawPixmap(265, 664, blackPlayerImage);
}

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
	m_game->getBoard().addCell(row, col, point);
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
	auto& pillarsMap = m_game->getBoard().getPillars();

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

	auto& bridgesMap = m_game->getBoard().getBridges();
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
	for (const auto& line : m_game->getBoard().getMatrix())
	{
		std::ranges::for_each(line, [&painter, cellSize](const Cell& element) {
			if (element.getCoordinates() != QPoint())
				painter.drawEllipse(element.getCoordinates().x(), element.getCoordinates().y(), cellSize / 2, cellSize / 2);
			});
	}
}

void BoardWidget::drawMines() {
	QPainter painter(this);
	const uint8_t cellSize = 8;

	for (size_t row = 0; row < m_game->getBoard().getLine(); ++row) {
		for (size_t col = 0; col < m_game->getBoard().getColumn(); ++col) {
			const Cell& cell = m_game->getBoard().getMatrix()[row][col];
			if (cell.getIsMined() && cell.getOcupier()) {
				painter.setPen(QPen(Qt::blue));
				painter.setBrush(QBrush(Qt::blue));
				painter.drawRect(cell.getCoordinates().x(), cell.getCoordinates().y(), cellSize, cellSize);
			}
		}
	}
}

void BoardWidget::drawBuldozerist() {
	QPainter painter(this);
	constexpr uint8_t cellSize = 8;

	painter.setPen(QPen(Qt::yellow));
	painter.setBrush(QBrush(Qt::yellow));
	const Cell& cell = m_game->getBoard().getMatrix()[m_game->getBoard().getCurrentBuldozerLine()][m_game->getBoard().getCurrentBuldozerColumn()];
	QPixmap blackPlayerImage("/Users/Filip/Desktop/facultate/buldozerist.png");
	painter.drawPixmap(cell.getCoordinates().x() - 7, cell.getCoordinates().y() - 7, blackPlayerImage);
}

//Swtich player
void BoardWidget::switchToRedPlayer() {

	if (m_game->switchToRedPlayer())
	{
		m_switchButtonBlack->setVisible(false);
		m_switchButtonRed->setVisible(true);
	}
	else
		QMessageBox::information(nullptr, "Info", "Place a pillar before switching.");
	update();
}

void BoardWidget::switchToBlackPlayer() {
	if (m_game->switchToBlackPlayer())
	{
		m_switchButtonRed->setVisible(false);
		if (m_firstPlace == 1)
			m_switchPlayerForFirstRound->setVisible(true);
		m_switchButtonBlack->setVisible(true);
	}
	else
		QMessageBox::information(nullptr, "Info", "Place a pillar before switching.");
	update();
}

//Game initialization
BoardWidget::BoardWidget(QWidget* parent, std::shared_ptr<Game> game) :
	QMainWindow{ parent },
	m_game{ game }
{
	m_game->initializationGame(24, 24);
	initializeUI();
	setupBoardCells();
	m_game->getBoard().generateMines();
	m_game->getBoard().generateBuldozerist();
}

QWidget* BoardWidget::createMainWidget() {
	return new QWidget(this);
}

void BoardWidget::updatePlayerStats() {
	m_numberOfPillarsForRedPlayer.setText("Red Pillars: " + QString::number(m_game->getRedPlayer().getNumberOfPillars()));
	m_numberOfBridgesForRedPlayer.setText("Red Bridges: " + QString::number(m_game->getRedPlayer().getNumberOfBridges()));

	m_numberOfPillarsForBlackPlayer.setText("Black Pillars: " + QString::number(m_game->getBlackPlayer().getNumberOfPillars()));
	m_numberOfBridgesForBlackPlayer.setText("Black Bridges: " + QString::number(m_game->getBlackPlayer().getNumberOfBridges()));
}

void BoardWidget::initializeUI() {
	setWindowTitle("Twixt Game");
	setFixedSize(750, 750);

	QWidget* mainWidget = createMainWidget();
	addBackButton(mainWidget);
	setCentralWidget(mainWidget);
	createSwitchButtons(mainWidget);
	createPlayerInfoLabels(mainWidget);
}

void BoardWidget::createSwitchButtons(QWidget* parent) {
	m_switchButtonRed = new QPushButton("SWITCH TURN", parent);
	m_switchButtonRed->setGeometry(460, 3, 90, 85);
	m_switchButtonRed->setStyleSheet(createSwitchButtonStyle());
	connect(m_switchButtonRed, &QPushButton::clicked, this, &BoardWidget::switchToBlackPlayer);
	m_switchButtonRed->setVisible(true);

	m_switchButtonBlack = new QPushButton("SWITCH TURN", parent);
	m_switchButtonBlack->setGeometry(460, 656, 90, 85);
	m_switchButtonBlack->setStyleSheet(createSwitchButtonStyle());
	connect(m_switchButtonBlack, &QPushButton::clicked, this, &BoardWidget::switchToRedPlayer);
	m_switchButtonBlack->setVisible(false);

	m_switchPlayerForFirstRound = new QPushButton("SWITCH TEAM", parent);
	m_switchPlayerForFirstRound->setGeometry(160, 656, 90, 85);
	m_switchPlayerForFirstRound->setStyleSheet(createSwitchButtonStyle());
	connect(m_switchPlayerForFirstRound, &QPushButton::clicked, this, &BoardWidget::switchTeam);
	m_switchPlayerForFirstRound->setVisible(false);
}

void BoardWidget::createPlayerInfoLabels(QWidget* parent) {
	QFont font;
	font.setWeight(QFont::Bold);
	m_numberOfPillarsForRedPlayer.setText("Red Pillars: " + QString::number(m_game->getRedPlayer().getNumberOfPillars()));
	m_numberOfPillarsForRedPlayer.setGeometry(355, 30, 120, 30);
	m_numberOfPillarsForRedPlayer.setFont(font);
	m_numberOfPillarsForRedPlayer.setParent(parent);

	m_numberOfBridgesForRedPlayer.setText("Red Bridges: " + QString::number(m_game->getRedPlayer().getNumberOfBridges()));
	m_numberOfBridgesForRedPlayer.setGeometry(355, 50, 120, 30);
	m_numberOfBridgesForRedPlayer.setFont(font);
	m_numberOfBridgesForRedPlayer.setParent(parent);

	m_numberOfPillarsForBlackPlayer.setText("Black Pillars:" + QString::number(m_game->getBlackPlayer().getNumberOfPillars()));
	m_numberOfPillarsForBlackPlayer.setGeometry(354, 685, 120, 30);
	m_numberOfPillarsForBlackPlayer.setFont(font);
	m_numberOfPillarsForBlackPlayer.setParent(parent);

	m_numberOfBridgesForBlackPlayer.setText("Black Bridges:" + QString::number(m_game->getBlackPlayer().getNumberOfBridges()));
	m_numberOfBridgesForBlackPlayer.setGeometry(354, 705, 120, 30);
	m_numberOfBridgesForBlackPlayer.setFont(font);
	m_numberOfBridgesForBlackPlayer.setParent(parent);
}

void BoardWidget::switchTeam()
{
	if (m_firstPlace == 1) {
		std::string temp{ m_game.get()->getBlackPlayer().getName() };
		m_game.get()->getBlackPlayer().setName(m_game.get()->getRedPlayer().getName());
		m_game.get()->getRedPlayer().setName(temp);
		m_switchPlayerForFirstRound->setVisible(false);
		update();
	}

}
