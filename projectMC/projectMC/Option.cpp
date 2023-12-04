#include "Option.h"

Option::Option(QWidget* parent) :
	QWidget { parent }
{
	setupUI();
	applyStyles();
	positionWidgets();
	setFixedSize(750, 750);
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

}

void Option::applyStyles()
{
}

void Option::positionWidgets()
{
}

