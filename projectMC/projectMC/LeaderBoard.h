#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include "DataBaseManager.h"
#include "Option.h"

class LeaderBoard : public QWidget {
    Q_OBJECT
public:
    LeaderBoard(QWidget* parent);
    ~LeaderBoard() = default;
    void loadLeaderboard();
private:
    void addBackButton(QWidget*);

signals:
    void goBackToMenuSignalLeaderBoard();

public slots:
    void goBackToMenuLeaderBoard();
    void isPlayerSaved(const QString& playerName);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QTableWidget* leaderboardTable;
    DataBaseManager databaseManager;
    QPushButton* goBackButton;
};

