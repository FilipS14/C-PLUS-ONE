#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include "DataBaseManager.h"

class LeaderBoard : public QWidget {
    Q_OBJECT
public:
    LeaderBoard(QWidget* parent = nullptr);

private:
    QTableWidget* leaderboardTable;
    DataBaseManager databaseManager;

    void loadLeaderboard();
};

