#pragma once
#include <QtWidgets/QMainWindow>
#include <QGridLayout>
#include <QPushButton>

class BoardWidget : public QMainWindow
{
	Q_OBJECT
public:
	BoardWidget(QWidget* parent = nullptr);
	~BoardWidget();
	void onCellClicked();
	void resetBoard();

private:
	QGridLayout* gridLayout;
	QList<QList<QPushButton*>>boardCells;
};
