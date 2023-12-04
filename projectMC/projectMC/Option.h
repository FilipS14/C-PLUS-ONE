#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class Option : public QWidget
{
    Q_OBJECT

public:
    Option(QWidget* parent = nullptr);
    ~Option();
    void paintEvent(QPaintEvent* event);
private:
    QSlider* volumeSlider;
    QComboBox* comboBoxBoardSize;
    QLineEdit* lineEditPlayer1;
    QLineEdit* lineEditPlayer2;
    QPushButton* setNamePlayerRed;
    QPushButton* setNamePlayerBlack;
};
#endif // OPTION_H
