#pragma once
#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QFrame>
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

private:
	void initializeUI();
	QWidget* createMainWidget();
	void addBackButton(QWidget* widget);
	QVBoxLayout* createMainLayout(QWidget* mainWidget);
	QFrame* createBoardFrame(QWidget* mainWidget);
	void setupBoardCells();
	void setupBoardCell(size_t row, size_t col);
	void addWidgetsToLayout(QVBoxLayout* mainLayout, QFrame* boardFrame);
	bool isCornerCell(size_t row, size_t col) const;
	void setCellStyle(QPushButton* cellButton) const;

	QPushButton* m_backButton;
	QGridLayout* m_boardLayout;
	QVector<QVector<QPushButton*>>m_boardCells;
	bool m_isBlack;

protected:
	void paintEvent(QPaintEvent* event) override;

signals:
	void backToMenuSignal();

public slots:
	void backToMenu();
};

#endif