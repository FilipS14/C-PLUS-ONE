#include "Option.h"

Option::Option(QWidget* parent) :
	QWidget { parent }
{
	setupUI();
	applyStyles();
	positionWidgets();
	setFixedSize(750, 750);
}

void Option::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPixmap backgroundPixmap("/Users/Filip/Desktop/facultate/anul2/woodSign.png");
    painter.drawPixmap(100, 100, 600, 700, backgroundPixmap);
}

void Option::setupUI()
{
    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);

    comboBoxBoardSize = new QComboBox(this);
    comboBoxBoardSize->addItems({ "24 x 24", "22 x 22" , "20 x 20", "18 x 18", "16 x 16", "14 x 14" });

    lineEditPlayer1 = new QLineEdit(this);
    lineEditPlayer2 = new QLineEdit(this);

    labelBoardSize = new QLabel("Board Size:", this);
    labelNamePlayerRed = new QLabel("Name red player:", this);
    labelNamePlayerBlack = new QLabel("Name black player:", this);
    labelSetVolume = new QLabel("Volume:", this);

}

void Option::applyStyles()
{
    volumeSlider->setStyleSheet("QSlider {"
        "  border: 4px solid #FFF3E0;"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                              stop:0 #FFF3E0, stop:1#FFF3E0);"
        "  height: 20px;"
        "  border-radius: 10px;"
        "}"
        "QSlider::handle:horizontal {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                              stop:0 #795548, stop:1 #3e2723);"
        "  width: 30px;"
        "  margin: -5px 0;"
        "  border-radius: 15px;"
        "}");
}

void Option::positionWidgets()
{
    const int widgetWidth = 150;
    const int widgetHeight = 30;
    const int padding = 40;

    int yPos = 320;
    int xPos = 380;

    comboBoxBoardSize->setGeometry(xPos, yPos, widgetWidth, widgetHeight);
    labelBoardSize->setGeometry(xPos - 215, yPos - 10, 100, widgetHeight);
    yPos += widgetHeight + padding;

    labelNamePlayerRed->setGeometry(xPos - 168, yPos - 10, 100, widgetHeight);
    lineEditPlayer1->setGeometry(xPos, yPos, widgetWidth, widgetHeight);
    yPos += widgetHeight + padding;

    labelNamePlayerBlack->setGeometry(xPos - 155, yPos - 10, 100, widgetHeight);
    lineEditPlayer2->setGeometry(xPos, yPos, widgetWidth, widgetHeight);
    yPos += widgetHeight + padding;

    labelSetVolume->setGeometry(xPos - 237, yPos - 10, 100, widgetHeight);
    volumeSlider->setGeometry(xPos, yPos, widgetWidth, widgetHeight);

}

