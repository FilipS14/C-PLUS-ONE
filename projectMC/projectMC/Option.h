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

class Option : public QWidget
{
    Q_OBJECT

public:
    Option(QWidget* parent = nullptr);
    ~Option() = default;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void setupUI();
    void applyStyles();
    void positionWidgets();
private:
    QSlider* volumeSlider;
    QComboBox* comboBoxBoardSize;
    QLineEdit* lineEditPlayer1;
    QLineEdit* lineEditPlayer2;
    QPushButton* setNamePlayerRed;
    QPushButton* setNamePlayerBlack;
   
};
#endif
