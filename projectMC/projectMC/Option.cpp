#include "Option.h"

void Option::addBackButton(QWidget* widget)
{
    QString buttonStyle = "QPushButton {"
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
    goBackButton = new QPushButton(widget);
    goBackButton->setStyleSheet(buttonStyle);
    goBackButton->setGeometry(10, 10, 30, 30);
    connect(goBackButton, SIGNAL(clicked()), this, SLOT(goBackToMenuOptions()));
}

void Option::goBackToMenuOptions() {
    emit goBackToMenuSignalOptions();
}

Option::Option(QWidget* parent) :
    QWidget{ parent }
{
    setupUI();
    applyStyles();
    positionWidgets();
    addBackButton(this);
    setFixedSize(750, 750);
}

void Option::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPixmap backgroundPixmap("../Textures/woodSign.png");
    painter.drawPixmap(20, 100, 700, 710, backgroundPixmap);
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

    saveButtonNameRedPlayer = new QPushButton("Save", this);
    saveButtonNameBlackPlayer = new QPushButton("Save", this);
    connect(saveButtonNameRedPlayer, &QPushButton::clicked, this, &Option::saveNameRedPlayerSlot);
    connect(saveButtonNameBlackPlayer, &QPushButton::clicked, this, &Option::saveNameBlackPlayerSlot);
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

    comboBoxBoardSize->setStyleSheet("QComboBox {"
        "  border: 4px solid #795548;"
        "  background-color: #FFF3E0;"
        "  padding: 5px;"
        "  border-radius: 5px;"
        "  min-width: 6em;"
        "}"
        "QComboBox:hover, QComboBox:focus {"
        "  border-color: #4CAF50;"
        "  background-color: #FFE0B2;"
        "}"
        "QComboBox::drop-down {"
        "  subcontrol-origin: padding;"
        "  subcontrol-position: right center;"
        "  width: 20px;"
        "  border-left: 1px solid #795548;"
        "}"
        "QComboBox::down-arrow {"
        "  image: url(:/images/downArrow.jpg);"
        "}");

    const QString style =
        "QLineEdit {"
        "  border: 4px solid #795548;"
        "  background-color: #FFF3E0;"
        "  padding: 5px;"
        "  border-radius: 5px;"
        "}"
        "QLineEdit:focus {"
        "  border-color: #4CAF50;"
        "  background-color: #FFE0B2;"
        "}";
    lineEditPlayer1->setStyleSheet(style);
    lineEditPlayer2->setStyleSheet(style);

    const QString labelStyle = "font-weight: bold; color: #00000; font-size: 18px;";
    labelBoardSize->setStyleSheet(labelStyle);
    labelNamePlayerRed->setStyleSheet(labelStyle);
    labelNamePlayerBlack->setStyleSheet(labelStyle);
    labelSetVolume->setStyleSheet(labelStyle);
}

void Option::positionWidgets()
{
    const int widgetWidth = 162;
    const int widgetHeight = 30;
    const int padding = 40;

    int yPos = 320;
    int xPos = 360;

    comboBoxBoardSize->setGeometry(xPos, yPos, widgetWidth, widgetHeight);
    labelBoardSize->setGeometry(xPos - 180, yPos, widgetWidth, widgetHeight);//123
    yPos += widgetHeight + padding;

    labelNamePlayerRed->setGeometry(xPos - 180, yPos, widgetWidth, widgetHeight);//123
    lineEditPlayer1->setGeometry(xPos, yPos, widgetWidth, widgetHeight);
    saveButtonNameRedPlayer->setGeometry(xPos + widgetWidth + 10, yPos, 50, widgetHeight);
    yPos += widgetHeight + padding;

    labelNamePlayerBlack->setGeometry(xPos - 180, yPos, widgetWidth, widgetHeight);//123
    lineEditPlayer2->setGeometry(xPos, yPos, widgetWidth, widgetHeight);
    saveButtonNameBlackPlayer->setGeometry(xPos + widgetWidth + 10, yPos, 50, widgetHeight);
    yPos += widgetHeight + padding;

    labelSetVolume->setGeometry(xPos - 180, yPos, widgetWidth, widgetHeight);//123
    volumeSlider->setGeometry(xPos, yPos, widgetWidth, widgetHeight);
}

void Option::saveNameRedPlayerSlot()
{
    std::string redPlayerName = lineEditPlayer1->text().toStdString(); 
    
    //o functie care verifica numele cu regex
    if (!m_dataBase.playerExists(lineEditPlayer1->text())) {
        m_dataBase.addPlayer(lineEditPlayer1->text());
        emit playerSaved(lineEditPlayer1->text());
    }
    else
        QMessageBox::information(nullptr,"Error","Player already exists");
}

void Option::saveNameBlackPlayerSlot()
{
    std::string blackPlayerName = lineEditPlayer2->text().toStdString();
    
     //o functie care verifica numele cu regex
    if (!m_dataBase.playerExists(lineEditPlayer2->text())) {
        m_dataBase.addPlayer(lineEditPlayer2->text());
        emit playerSaved(lineEditPlayer2->text());
    }
    else
        QMessageBox::information(nullptr, "Error", "Player already exists");
}