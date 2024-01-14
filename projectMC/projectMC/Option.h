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
#include <regex>

class Option : public QWidget
{
    Q_OBJECT
public:
    Option(QWidget* parent);
    ~Option() = default;

signals:
    void playerSaved(const QString& );
    void goBackToMenuSignalOptions();
    void saveNameRedPlayerSignal(const QString&);
    void saveNameBlackPlayerSignal(const QString&);

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
    bool isValidPlayerName(const std::string&);
private:
    DataBaseManager m_dataBase;
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