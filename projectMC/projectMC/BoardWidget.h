#pragma once
#include <QMainWindow>
#include <QMouseEvent>
#include <QWidget>
#include <QPushButton>
#include <qpainter.h>
#include <QPoint>
#include <QMessageBox>
#include "../backend/Bridge.h"
#include "../backend/Pillar.h"
#include "Game.h"
#include <unordered_map>
#include <cmath>
#include <ranges>
#include <QLabel>
#include "Option.h"

class BoardWidget : public QMainWindow
{
	Q_OBJECT
public:
	BoardWidget(QWidget* parent = nullptr);
	~BoardWidget() = default;

private:
	void initializeUI();
	void updatePlayerStats();
	QWidget* createMainWidget();
	void addBackButton(QWidget* widget);
	void addRestartGameButton(QWidget* widget);
	void checkEnd();
	void setupBoardCells();
	void setupBoardCell(size_t row, size_t col);
	void drawBoard();
	void drawLettersFromBoard();
	void drawMines();
	void drawPillars();
	void drawBirdges();
	void drawCells();
	void drawBuldozerist();
	void drawBoxForPlayer();
	void drawHighlight();
	void drawNamePlayer();
	bool isCorner(size_t row, size_t col, uint8_t line, uint8_t column);
	void switchTeam();
	void createSwitchButtons(QWidget* parent);
	void createPlayerInfoLabels(QWidget* parent);
	QString createBackButtonStyle();
	QString createSwitchButtonStyle();
private:
	short m_firstPlace{ 0 };
	Game m_game;
	Cell m_selectedCell;
	Cell m_selectCellForDelete;

	QPushButton* m_backButton;
	QPushButton* m_switchButtonRed;
	QPushButton* m_switchButtonBlack;
	QPushButton* m_switchPlayerForFirstRound;
	QPushButton* m_restartGame;

	QLabel m_numberOfPillarsForRedPlayer;
	QLabel m_numberOfBridgesForRedPlayer;
	QLabel m_numberOfPillarsForBlackPlayer;
	QLabel m_numberOfBridgesForBlackPlayer;
	QLabel* m_nameRedPlayerLabel;
	QLabel* m_nameBlackPlayerLabel;
protected:
	void paintEvent(QPaintEvent* event) override;
	void mousePressEvent(QMouseEvent* event)override;

private:
	void handleLeftButtonClick(Cell& clickedCell);
	void handleRightButtonClick(const Cell& clickedCell);
	void handleMiddleButtonClick(const Cell& clickedCell);
	int64_t calculateDistance(const QPoint& point1, const QPoint& point2);
	void processClickEvent(Cell& clickedCell, Qt::MouseButton button);

signals:
	void backToMenuSignal();
	void finishGame();

public slots:
	void backToMenu();
	void saveNameRedPlayer(const QString& playerName);
	void saveNameBlackPlayer(const QString& playerName);
	void restartGame();

private slots:
	void switchToRedPlayer();
	void switchToBlackPlayer();

};