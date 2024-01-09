#include "DataBaseManager.h"
#include <QSqlError> 

DataBaseManager::DataBaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("leaderboard.db");

    if (!db.open()) {
        qDebug() << "Eroare la deschiderea bazei de date!";
    }
    else {
        qDebug() << "Conectat la baza de date!";
        createTable();
    }
}

void DataBaseManager::createTable() {
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS player_stats (id INTEGER PRIMARY KEY, username TEXT UNIQUE, wins INTEGER, losses INTEGER)")) {
        qDebug() << "Eroare la crearea tablei:" << query.lastError().text();
    }
}

void DataBaseManager::updatePlayerStats(const QString& playerName, int wins, int losses)
{
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO player_stats (username, wins, losses) VALUES (?, ?, ?)");
    query.bindValue(0, playerName);
    query.bindValue(1, wins);
    query.bindValue(2, losses);
    query.exec();
}