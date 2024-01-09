#pragma once
#include <cstdint>
#include <vector>
#include <QPoint>
#include <random>

class Cell
{
public:
	//rules of 5
	__declspec(dllexport) Cell(bool ocupied, QPoint coordinates, uint8_t line, uint8_t column, bool isMined, bool isBulldozered);//Constructor
	__declspec(dllexport) Cell();//Constructor
	__declspec(dllexport) Cell(Cell&& other) noexcept; //Move Constructor
	__declspec(dllexport) Cell& operator=(Cell&& other)noexcept; // Move Assignament Constructor
	__declspec(dllexport) Cell(const Cell& other); //Copy Constructor
	__declspec(dllexport) Cell& operator=(const Cell& other); //Copy Assignament Operator
	__declspec(dllexport) ~Cell() = default;

	//getteri
	__declspec(dllexport) bool getOcupier() const;
	__declspec(dllexport) bool getIsMined() const;
	__declspec(dllexport) bool getIsBulldozered() const;
	__declspec(dllexport) bool isEmpty() const;
	__declspec(dllexport) QPoint getCoordinates() const;
	__declspec(dllexport) uint8_t getLine() const;
	__declspec(dllexport) uint8_t getColumn() const;

	//setteri
	__declspec(dllexport) void setOcupied(bool status);
	__declspec(dllexport) void setMined(bool status);
	__declspec(dllexport) void setBulldozered(bool status);
	__declspec(dllexport) void setCoordinates(const QPoint& coordinates);
	__declspec(dllexport) void setLine(const uint8_t& line);
	__declspec(dllexport) void setColumn(const uint8_t& column);

	//Game methods
	__declspec(dllexport) void clearCell();
	__declspec(dllexport) std::vector<QPoint> getNeighborCoordinates() const noexcept;
	__declspec(dllexport) void bulldozerTurn(std::vector<Cell>& board);
	__declspec(dllexport) bool isBulldozeristHere() const;
	__declspec(dllexport) void placeBulldozerist(std::vector<Cell>& cells);
	__declspec(dllexport) void destroyPillar(std::vector<Cell>& board);

private:
	uint8_t m_line;
	uint8_t m_column;
	QPoint m_coordinates;
	bool m_ocupied;
	bool m_isMined;
	bool m_isBulldozered;
};