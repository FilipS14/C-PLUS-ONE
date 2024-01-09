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