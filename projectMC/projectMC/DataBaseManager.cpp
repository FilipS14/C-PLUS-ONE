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

void DataBaseManager::resetDatabase() {
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS player_stats");

    if (query.lastError().isValid()) {
        qDebug() << "Eroare la ștergerea tabelului din baza de date:" << query.lastError().text();
    }

    createTable();
}

bool DataBaseManager::playerExists(const QString& playerName)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM player_stats WHERE username = ?");
    query.bindValue(0, playerName);
    query.exec();

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}

void DataBaseManager::addPlayer(const QString& playerName)
{
    if (!playerExists(playerName)) {
        QSqlQuery query;
        query.prepare("INSERT INTO player_stats (username, wins, losses) VALUES (?, ?, ?)");
        query.bindValue(0, playerName);
        query.bindValue(1, 0);
        query.bindValue(2, 0);
        query.exec();
    }
    else {
        qDebug() << "Player already exists in the database.";
    }
}

