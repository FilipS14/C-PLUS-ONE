#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include "DataBaseManager.h"

class LeaderBoard : public QWidget {
    Q_OBJECT
public:
    LeaderBoard(QWidget* parent = nullptr);
    ~LeaderBoard() = default;
private:
    void addBackButton(QWidget*);
signals:
    void goBackToMenuSignalLeaderBoard();

public slots:
    void goBackToMenuLeaderBoard();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QTableWidget* leaderboardTable;
    DataBaseManager databaseManager;
    QPushButton* goBackButton;

    void loadLeaderboard();
};

