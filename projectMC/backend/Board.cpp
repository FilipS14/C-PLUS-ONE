#include"Board.h"

//RULE OF FIVE
Board::Board(uint8_t line, uint8_t column) : //Constructor
	m_line{ line },
	m_column{ column } {
	m_board.resize(line, std::vector<Cell>(column));
}

Board::Board(Board&& other) noexcept : //Move Constructor
	m_line{ std::exchange(other.m_line, 0) },
	m_column{ std::exchange(other.m_column, 0) },
	m_board{ std::move(other.m_board) }
{}

Board& Board::operator=(Board&& other) noexcept //Move Assignament Constructor
{
	if (this != &other) {
		m_line = std::exchange(other.m_line, 0);
		m_column = std::exchange(other.m_column, 0);
		m_board = std::move(other.m_board);
	}
	return *this;
}

Board::Board(const Board& other) : //Copy Constructor
	m_line{ other.m_line },
	m_column{ other.m_column },
	m_board{ other.m_board }
{}

Board& Board::operator=(const Board& other) //Copy Assignament Operator
{
	if (this != &other) {
		m_board.clear();
		m_line = other.m_line;
		m_column = other.m_column;
		m_board = other.m_board;
	}
	return *this;
}

//GETTERS
uint8_t Board::getLine() const {
	return m_line;
}

uint8_t Board::getColumn() const {
	return m_column;
}

std::vector<std::vector<Cell>>& Board::getMatrix()
{
	return m_board;
}

std::unordered_map<QPoint, Pillar, PillarHash>& Board::getPillars()
{
	return m_pillars;
}

std::unordered_map<TwoPoint, Bridge, TwoPointHash>& Board::getBridges() {
	return m_bridges;
}

std::vector<Cell> Board::getRedBase() const
{
	try
	{
		if (m_board.empty())
		{
			throw std::out_of_range("Board is empty");
		}

		const std::vector<Cell>& firstRow = m_board.at(0);

		if (firstRow.empty())
		{
			throw std::out_of_range("First row is empty");
		}

		return firstRow;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return std::vector<Cell>();
	}
}

std::vector<Cell> Board::getBlackBase() const
{
	std::vector<Cell> firstColumn;
	try
	{
		if (m_board.empty())
		{
			throw std::out_of_range("Board is empty");
		}

		for (const auto& row : m_board)
		{
			if (row.empty())
			{
				throw std::out_of_range("Row is empty");
			}

			firstColumn.push_back(row.at(0));
		}
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return std::vector<Cell>();
	}

	return firstColumn;
}

//SETTERS
void Board::setLine(uint8_t line) {
	m_line = line;
}

void Board::setColumn(uint8_t column) {
	m_column = column;
}

//MATRIX HANDLING
Cell Board::getCell(uint32_t x, uint32_t y) const {
	return m_board.at(x).at(y);
}

void Board::resizeBoard(size_t line, size_t column)
{
	m_line = static_cast<uint8_t>(line);
	m_column = static_cast<uint8_t>(column);
	m_board.resize(m_line, std::vector<Cell>(m_column));
}

void Board::addCell(size_t line, size_t column, QPoint coordinates)
{
	m_board.at(line).at(column) = { false, coordinates, static_cast<uint8_t>(line), static_cast<uint8_t>(column), false, false };
}

//CHECKS PILLARS
bool Board::isValidPillarMove(const Cell& cell, const Player& player)
{
	if (cell.getOcupier())
		return false;
	if (checkPillarsOverlap(cell))
		return false;
	if (checkOpponentBase(cell, player))
		return false;
	return true;
}

bool Board::checkPillarsOverlap(const Cell& Cell)
{
	auto pillarIt = m_pillars.find(Cell.getCoordinates());
	return pillarIt != m_pillars.end();
}

bool Board::checkOpponentBase(const Cell& cell, const Player& player)
{
	const auto& team = player.getTeam();
	const auto& column = cell.getColumn();
	const auto& line = cell.getLine();

	if (team == Team::red)
		return column == 0 || column == m_column - 1;
	else
		return line == 0 || line == m_line - 1;

	return false;
}

//BRIDGE CHECKS
bool Board::isValidBridgeMove(const Cell& startCell, const Cell& endCell, const Player& player)
{
	if (!areCellsOccupied(startCell, endCell))
		return false;

	if (!areCellsPillars(startCell, endCell))
		return false;

	if (!arePillarsSameColor(startCell, endCell))
		return false;

	if (!arePillarsPlayerColor(startCell, endCell, player))
		return false;

	if (!checkDistaceToBridge(startCell, endCell))
		return false;

	if (!checkBridgesIntersection(startCell, endCell))
		return false;

	return true;
}

bool Board::areCellsOccupied(const Cell& startCell, const Cell& endCell)
{
	if (!startCell.getOcupier() || !endCell.getOcupier())
		return false;

	return true;
}

bool Board::areCellsPillars(const Cell& startCell, const Cell& endCell)
{
	auto startPillar = m_pillars.find(startCell.getCoordinates());
	auto endPillar = m_pillars.find(endCell.getCoordinates());

	if (startPillar == m_pillars.end() || endPillar == m_pillars.end())
		return false;

	return true;
}

bool Board::arePillarsSameColor(const Cell& startCell, const Cell& endCell)
{
	auto startPillar = m_pillars.find(startCell.getCoordinates());
	auto endPillar = m_pillars.find(endCell.getCoordinates());

	if (startPillar->second.getColor() != endPillar->second.getColor())
		return false;

	return true;
}

bool Board::arePillarsPlayerColor(const Cell& startCell, const Cell& endCell, const Player& player)
{
	auto startPillar = m_pillars.find(startCell.getCoordinates());
	auto endPillar = m_pillars.find(endCell.getCoordinates());

	QColor color = (player.getTeam() == Team::red) ? Qt::red : Qt::black;
	if (startPillar->second.getColor() != color || endPillar->second.getColor() != color)
		return false;

	return true;
}

bool Board::checkDistaceToBridge(const Cell& startCell, const Cell& endCell)
{
	constexpr std::array<int, 8> dX{ -2, -2, -1, -1, 1, 1, 2, 2 };
	constexpr std::array<int, 8> dY{ -1, 1, -2, 2, -2, 2, -1, 1 };

	for (size_t i = 0; i < 8; i++) {
		if (endCell.getLine() + dX[i] == startCell.getLine() &&
			endCell.getColumn() + dY[i] == startCell.getColumn())
			return true;
	}
	return false;
}

bool Board::doSegmentsIntersect(const QPoint& start1, const QPoint& end1, const QPoint& start2, const QPoint& end2) {
	int orientation1 = orientation(start1, end1, start2);
	int orientation2 = orientation(start1, end1, end2);
	int orientation3 = orientation(start2, end2, start1);
	int orientation4 = orientation(start2, end2, end1);

	return ((orientation1 != orientation2) && (orientation3 != orientation4));
}

int Board::orientation(const QPoint& p, const QPoint& q, const QPoint& r) {
	int val = (q.x() - p.x()) * (r.y() - q.y()) - (q.y() - p.y()) * (r.x() - q.x());

	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

bool Board::checkBridgesIntersection(const Cell& startCell, const Cell& endCell)
{
	constexpr int shrinkAmount{ 1 };

	auto shrunkStart = startCell.getCoordinates();
	auto shrunkEnd = endCell.getCoordinates();

	shrunkStart.setX(shrunkStart.x() + shrinkAmount);
	shrunkStart.setY(shrunkStart.y() + shrinkAmount);

	shrunkEnd.setX(shrunkEnd.x() - shrinkAmount);
	shrunkEnd.setY(shrunkEnd.y() - shrinkAmount);

	for (const auto& bridge : m_bridges)
	{
		const Bridge& existingBridge = bridge.second;
		const auto& existingStart = existingBridge.getCoordinatesStart();
		const auto& existingEnd = existingBridge.getCoordinatesEnd();

		if (doSegmentsIntersect(existingStart, existingEnd, shrunkStart, shrunkEnd))
		{
			return false;//se intersecteaza cu un pod
		}
	}

	return true;
}

//PILLARS AND BRIDGES HANDLING
void Board::addPillar(const Pillar& pillar)
{
	m_pillars[pillar.getCoordinates()] = pillar;
}

void Board::addBridge(const Bridge& bridge) {
	TwoPoint key{ bridge.getCoordinatesStart(), bridge.getCoordinatesEnd() };
	m_bridges[key] = bridge;
}

void Board::removeBridge(const Cell& startCell, const Cell& endCell)
{
	TwoPoint key{ startCell.getCoordinates(), endCell.getCoordinates() };
	auto bridgeIt = m_bridges.find(key);

	if (bridgeIt != m_bridges.end())
	{
		m_bridges.erase(bridgeIt);
	}
}

int Board::generateRandomNumber(uint8_t minValue, uint8_t maxValue) const {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<unsigned int> dis(minValue, maxValue);

	return dis(gen);
}

void Board::generateMines() {
	for (size_t i = 0; i < 8; i++) {
		uint8_t randomLine = generateRandomNumber(1, m_line - 2);
		uint8_t randomColumn = generateRandomNumber(1, m_column - 2);
		m_board[randomLine][randomColumn].setMined(true);
	}
}

Pillar Board::getRandomPillar(const std::unordered_map<QPoint, Pillar, PillarHash>& pillarsMap) {
	std::vector<std::pair<QPoint, Pillar>> pillarsVector(pillarsMap.begin(), pillarsMap.end());
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, pillarsVector.size() - 1);
	int randomIndex = dis(gen);
	return pillarsVector[randomIndex].second;
}