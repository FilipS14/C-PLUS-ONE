#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{ parent } ,
	m_mainMenu{ std::make_unique<MainMenu>(this) },
	m_boardWidget{ std::make_unique<BoardWidget>(this) },
	m_pageInstructions{ std::make_unique<Instruction>(this) },
	m_pageOptions{ std::make_unique<Option>(this) },
	m_pageLeaderBoard{ std::make_unique<LeaderBoard>(this) }
{
	setWindowTitle("Twixt Game");
	mainLayout = new QVBoxLayout;
	QString backgroundStyle = "MainWindow {"
		"background-image: url(../Textures/backgroundWood.jpg);"
		"background-repeat: no-repeat;"
		"background-position: center;"
		" margin: 0;"
		"}";

	this->setStyleSheet(backgroundStyle);

	mainLayout->addWidget(m_mainMenu.get());
	mainLayout->addWidget(m_boardWidget.get());
	mainLayout->addWidget(m_pageInstructions.get());
	mainLayout->addWidget(m_pageOptions.get());
	mainLayout->addWidget(m_pageLeaderBoard.get());

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);

	connect(m_mainMenu.get(), SIGNAL(startGameSignal()), this, SLOT(startGame()));
	connect(m_mainMenu.get(), SIGNAL(showInstructionsSignal()), this, SLOT(showInstructions()));
	connect(m_mainMenu.get(), SIGNAL(showOptionSignal()), this, SLOT(showOptions()));
	connect(m_mainMenu.get(), SIGNAL(showLeaderboardSignal()), this, SLOT(showLeaderBoard()));


	connect(m_boardWidget.get(), SIGNAL(backToMenuSignal()), this, SLOT(backToMenu()));
	connect(m_pageInstructions.get(), SIGNAL(goBackToMenuSignalInstruction()), this, SLOT(backToMenuIntruction()));
	connect(m_pageOptions.get(), SIGNAL(goBackToMenuSignalOptions()), this, SLOT(backToMenuOption()));
	connect(m_pageLeaderBoard.get(), SIGNAL(goBackToMenuSignalLeaderBoard()), this, SLOT(backToMenuLeaderBoard()));
	connect(m_pageOptions.get(), SIGNAL(playerSaved(const QString&)), m_pageLeaderBoard.get(), SLOT(isPlayerSaved(const QString&)));
	connect(m_pageOptions.get(), &Option::saveNameRedPlayerSignal, m_boardWidget.get(), &BoardWidget::saveNameRedPlayer);
	connect(m_pageOptions.get(), &Option::saveNameBlackPlayerSignal, m_boardWidget.get(), &BoardWidget::saveNameBlackPlayer);

	m_mainMenu->show();
	m_boardWidget->close();
	m_pageInstructions->close();
	m_pageOptions->close();
	m_pageLeaderBoard->close();
	setFixedSize(750, 760);
}

void MainWindow::startGame() {
	m_mainMenu->close();
	m_boardWidget->show();
}

void MainWindow::backToMenu() {
	m_boardWidget->close();
	m_mainMenu->show();
}

void MainWindow::backToMenuIntruction() {
	m_pageInstructions->close();
	m_mainMenu->show();
}

void MainWindow::backToMenuOption()
{
	m_pageOptions->close();
	m_mainMenu->show();
}

void MainWindow::backToMenuLeaderBoard()
{
	m_pageLeaderBoard->close();
	m_mainMenu.get()->show();
}

void MainWindow::showInstructions() {
	m_mainMenu->close();
	m_pageInstructions->show();
}

void MainWindow::showLeaderBoard() {
	m_mainMenu->close();
	m_pageLeaderBoard->show();
}

void MainWindow::showOptions() {
	m_mainMenu->close();
	m_pageOptions->show();
}