#pragma once
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DataBaseManager {
public:
    DataBaseManager();
    void createTable();
    void updatePlayerStats(const QString& playerName, int wins, int losses);
    void resetDatabase();
private:
    QSqlDatabase db;
};

