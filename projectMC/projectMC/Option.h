#ifndef OPTION_H
#define OPTION_H

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>
#include "Game.h"
#include "DataBaseManager.h"

class Option : public QWidget
{
    Q_OBJECT
public:
    Option(QWidget* parent, std::shared_ptr<Game> game);
    ~Option() = default;

signals:
    void playerSaved(const QString& playerName);
    void goBackToMenuSignalOptions();
    void saveNameRedPlayerSignal(const QString& redPlayerName);
    void saveNameBlackPlayerSignal(const QString& blackPlayerName);
    

public slots:
    void goBackToMenuOptions();
    void saveNameRedPlayerSlot();
    void saveNameBlackPlayerSlot();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void setupUI();
    void applyStyles();
    void positionWidgets();
    void addBackButton(QWidget*);
private:
    DataBaseManager m_dataBase;
    std::shared_ptr<Game> m_game;
    QSlider* volumeSlider;
    QComboBox* comboBoxBoardSize;
    QLineEdit* lineEditPlayer1;
    QLineEdit* lineEditPlayer2;
    QPushButton* setNamePlayerRed;
    QPushButton* setNamePlayerBlack;
    QLabel* labelBoardSize;
    QLabel* labelNamePlayerRed;
    QLabel* labelNamePlayerBlack;
    QLabel* labelSetVolume;
    QPushButton* goBackButton;
    QPushButton* saveButtonNameRedPlayer;
    QPushButton* saveButtonNameBlackPlayer;
};
#endif