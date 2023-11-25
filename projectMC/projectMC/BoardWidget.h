#pragma once
#include <QtWidgets/QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include "Board.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <qpainter.h>

class BoardWidget : public QMainWindow
{
	Q_OBJECT
public:
	BoardWidget(QWidget* parent = nullptr);
	~BoardWidget() = default;
	bool getIsBlack() const;
	void setIsBlack(bool isBlack);
	void onCellClicked();
	void resetBoard();
	void displayGameOverMessage();
	void removePiece(int row, int col);
protected:
	void paintEvent(QPaintEvent* event) override;\

private:
	QGridLayout* m_gridLayout;
	QList<QList<QPushButton*>>m_boardCells;
	bool m_isBlack = false;//pentru a incepe sa coloreze cu rosu
	Board board;
};
