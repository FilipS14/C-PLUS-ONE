#include "LeaderBoard.h"

LeaderBoard::LeaderBoard(QWidget* parent) : 
    QWidget{parent}
{
    leaderboardTable = new QTableWidget(this);
    leaderboardTable->setColumnCount(4);
    addBackButton(this);
    QStringList headers;
    headers << "ID" << "Username" << "Wins" << "Losses";
    leaderboardTable->setHorizontalHeaderLabels(headers);
    loadLeaderboard();
    
    leaderboardTable->setGeometry(165, 320, 410, 240);
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
    update();
}

void LeaderBoard::addBackButton(QWidget* widget)
{
    goBackButton = new QPushButton(widget);
    goBackButton->setGeometry(10, 10, 30, 30);
    goBackButton->setStyleSheet(createBackButtonStyle());
    connect(goBackButton, SIGNAL(clicked()), this, SLOT(goBackToMenuLeaderBoard()));
}

QString LeaderBoard::createBackButtonStyle()
{
    return "QPushButton {"
        "background-color: #D2691E;"
        "background-image: url(../Textures/backToMenu.jpg);"
        "border: 2px solid #000000;"
        "color: #ffffff;"
        "font: Bold;"
        "font-size: 40px;"
        "padding: 10px 20px;"
        "}"
        "QPushButton:hover {"
        "background-color: #DEB887;"
        "}";
}

void LeaderBoard::isPlayerSaved(const QString& playerName) {
    int row = leaderboardTable->rowCount();
    leaderboardTable->insertRow(row);
    leaderboardTable->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
    leaderboardTable->setItem(row, 1, new QTableWidgetItem(playerName));
    leaderboardTable->setItem(row, 2, new QTableWidgetItem("0"));
    leaderboardTable->setItem(row, 3, new QTableWidgetItem("0"));
    update();
}

void LeaderBoard::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPixmap backgroundPixmap("../Textures/woodSign.png");
    painter.drawPixmap(20, 100, 700, 700, backgroundPixmap);
}

void LeaderBoard::goBackToMenuLeaderBoard() {
    emit goBackToMenuSignalLeaderBoard();
}

void LeaderBoard::updatePlayerStats(const QString& playerName, int wins, int losses) {
    int rowCount = leaderboardTable->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        if (leaderboardTable->item(row, 1)->text() == playerName) {
           
            leaderboardTable->item(row, 2)->setText(QString::number(wins));
            leaderboardTable->item(row, 3)->setText(QString::number(losses));
            update();
            break; 
        }
    }
}