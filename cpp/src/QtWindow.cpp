//
// QtWindow.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 22:20:14 2013 Alexandre Baron
// Last update Sun Jan 20 04:17:35 2013 Alexandre Baron
//

#include <sstream>
#include <iostream>

#include <QVBoxLayout>

#include "QtWindow.hh"

using namespace std;

QtWindow::QtWindow()
  : QMainWindow()
{
  this->initialize();
}

void	QtWindow::toggleOnOff()
{
  this->setBackgroundImage(this->OnOff_ ? POKEDEX_OFF_IMG : POKEDEX_ON_IMG);
  this->OnOff_ = !this->OnOff_;
}

void	QtWindow::makeButtonTransparent(QPushButton *button) {
  button->setFocusPolicy(Qt::NoFocus);
  button->setFlat(true);
}

// Pokemon font is a free software made by Jackster Productions
// http://www.fontspace.com/jackster-productions/pokemon-gb
void	QtWindow::createHomeMenu()
{
  QPushButton	*searchPokemonButton;
  QPushButton	*pokemonBattleButton;
  QGridLayout	*verticalLayout = new QGridLayout();
  std::stringstream	styleStream;

  this->homeMenu_ = new QWidget(this);
  this->homeMenu_->setGeometry(55, 150, 260, 175);

  searchPokemonButton = new QPushButton("Search a Pokemon", this->homeMenu_);
  makeButtonTransparent(searchPokemonButton);
  styleStream << "text-align: left;color:blue;";
  searchPokemonButton->setStyleSheet(styleStream.str().c_str());
  searchPokemonButton->setGeometry(2, 2, 250, 30);

  pokemonBattleButton = new QPushButton("Pokemon Battle Simulation", this->homeMenu_);
  pokemonBattleButton->setGeometry(2, 50, 250, 30);
  pokemonBattleButton->setStyleSheet(styleStream.str().c_str());
  makeButtonTransparent(pokemonBattleButton);

  verticalLayout->addWidget(searchPokemonButton);
  verticalLayout->addWidget(pokemonBattleButton);
  this->homeMenu_->setLayout(verticalLayout);
}

void	QtWindow::initialize()
{
  std::stringstream	styleStream;
  QFontDatabase		fonts;
  QStringList		availableFonts = fonts.families();

  this->setWindowTitle("Light Pokedex");
  this->OnOff_ = false;

  for (int i = 0; i < availableFonts.size(); ++i)
    cout << availableFonts.at(i).toLocal8Bit().constData() << endl;

  this->onOffButton_ = new QPushButton("START", this);
  this->createHomeMenu();

  this->onOffButton_->setGeometry(448, 446, 120, 62);
  this->makeButtonTransparent(this->onOffButton_);
  styleStream << "background-image: url("<< ON_BUTTON_IMG << ");" << "font: bold 12px;";
  this->onOffButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->onOffButton_, SIGNAL(clicked()), this, SLOT(toggleOnOff()));
}

void	QtWindow::setBackgroundImage(const char *filename)
{
  QPalette	palette;
  QPixmap	pixmap(filename);
  QBrush	brush(pixmap);

  palette.setBrush(QPalette::Background, brush);
  setPalette(palette);
}

void	QtWindow::blockResize(size_t width, size_t height)
{
  setFixedSize(width, height);
}
