#include "BoardWidget.h";

bool BoardWidget::getIsBlack() const {
	return m_isBlack;
}

void BoardWidget::setIsBlack(bool isBlack) {
	m_isBlack = isBlack;
}

void BoardWidget::onCellClicked()
{
	QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
	if (clickedButton)
	{
		if (getIsBlack())
		{
			clickedButton->setStyleSheet("background-color: black; border: 1px solid black; border-radius: 5px;");
		}
		else
		{
			clickedButton->setStyleSheet("background-color: red; border: 1px solid black; border-radius: 5px;");
		}
		setIsBlack(!getIsBlack());
	}
}

void BoardWidget::resetBoard()
{
	board.reset();
}

void BoardWidget::removePiece(int row, int col)
{
	board.setValue(row, col, 0);
}

void BoardWidget::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 2));
	painter.drawRect(100, 100, 550, 550);
	painter.fillRect(100, 100, 550, 550, Qt::gray);
	painter.setPen(QPen(Qt::red, 2));
	painter.drawLine(140, 134, 610, 134);//prima linie rosie
	painter.drawLine(140, 617, 610, 617);//a doua line rosie
	painter.setPen(QPen(Qt::black, 2));
	painter.drawLine(133, 142, 133, 608);//prima linie negra
	painter.drawLine(617, 142, 617, 608);// a doua linie neagra
}

BoardWidget::BoardWidget(QWidget* parent) :
	QMainWindow{ parent }
{
	setWindowTitle("Twixt Game");
	setFixedSize(750, 750);

	QWidget* mainWidget = new QWidget(this);//creez un widget principal

	QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);//creez un layout vertical pentru widgetul principal

	mainLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));//adaug un spatiu in partea de sus a layout ului

	QFrame* boardFrame = new QFrame(mainWidget);//aici pun grid-ul cu celule

	QGridLayout* boardLayout = new QGridLayout(boardFrame);//creez un gridlayout pentru boardFrame
}