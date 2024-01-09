#include "LeaderBoard.h"
#include <QTableWidgetItem>

LeaderBoard::LeaderBoard(QWidget* parent) : QWidget(parent) {
    // Assuming leaderboardTable is a member variable of LeaderBoard class
    leaderboardTable = new QTableWidget(this);
    leaderboardTable->setColumnCount(4); // Assuming you have 4 columns

    QStringList headers;
    headers << "ID" << "Username" << "Wins" << "Losses";
    leaderboardTable->setHorizontalHeaderLabels(headers);

    loadLeaderboard(); // Load data when the object is created

    // You might want to adjust the size and position based on your layout
    leaderboardTable->setGeometry(10, 10, 400, 200);
}

void LeaderBoard::loadLeaderboard() {
    QSqlQuery query("SELECT * FROM player_stats ORDER BY wins DESC, losses ASC");
    int row = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString username = query.value(1).toString();
        QString wins = query.value(2).toString();
        QString losses = query.value(3).toString();

        leaderboardTable->insertRow(row);
        leaderboardTable->setItem(row, 0, new QTableWidgetItem(id));
        leaderboardTable->setItem(row, 1, new QTableWidgetItem(username));
        leaderboardTable->setItem(row, 2, new QTableWidgetItem(wins));
        leaderboardTable->setItem(row, 3, new QTableWidgetItem(losses));

        ++row;
    }
}