//
// QtWindow.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 22:20:14 2013 Alexandre Baron
// Last update Sun Jan 20 06:08:24 2013 Alexandre Baron
//

#include <sstream>
#include <iostream>

#include "QtWindow.hh"

using namespace std;

QtWindow::QtWindow()
  : QMainWindow()
{
  this->initialize();
}

void	QtWindow::hideEverything()
{
  this->homeMenu_->setVisible(false);
}

void	QtWindow::toggleOnOff()
{
  if (this->OnOff_)
    {
      this->setBackgroundImage(POKEDEX_OFF_IMG);
      this->hideEverything();
    }
  else
    {
      this->setBackgroundImage(POKEDEX_ON_IMG);
      this->homeMenu_->setVisible(true);
    }
  this->OnOff_ = !this->OnOff_;
}

void	QtWindow::makeButtonTransparent(QPushButton *button) {
  button->setFocusPolicy(Qt::NoFocus);
  button->setFlat(true);
}

void	QtWindow::createHomeMenu()
{
  QPushButton	*searchPokemonButton;
  QPushButton	*pokemonBattleButton;
  std::stringstream	styleStream;

  this->homeMenu_ = new QWidget(this);
  searchPokemonButton = new QPushButton("Search a Pokemon", this->homeMenu_);
  pokemonBattleButton = new QPushButton("Battle Simulation", this->homeMenu_);

  this->homeMenu_->setGeometry(55, 150, 260, 175);
  searchPokemonButton->setGeometry(20, 30, 220, 30);
  pokemonBattleButton->setGeometry(20, 80, 220, 30);

  makeButtonTransparent(searchPokemonButton);
  makeButtonTransparent(pokemonBattleButton);

  styleStream << "text-align: left;font-size: 11px";
  searchPokemonButton->setStyleSheet(styleStream.str().c_str());
  pokemonBattleButton->setStyleSheet(styleStream.str().c_str());

  searchPokemonButton->setFont(this->pokeFont_);
  pokemonBattleButton->setFont(this->pokeFont_);

  this->homeMenu_->setVisible(false);
}

// Pokemon GB.ttf font is a free software for any purpose, made by Jackster Productions
// http://www.fontspace.com/jackster-productions/pokemon-gb
void	QtWindow::initializePokeFont()
{
  this->pokeFont_.setFamily("Pokemon GB");
  if (this->pokeFont_.family() != "Pokemon GB")
    {
      int	fontID;

      fontID = QFontDatabase::addApplicationFont("../resources/PokemonFont.ttf");
      if (fontID != -1)
	{
	  this->pokeFont_.setFamily("Pokemon GB");
	}
      if (this->pokeFont_.family() != "Pokemon GB")
	{
	  this->pokeFont_.setFamily(this->pokeFont_.defaultFamily());
	}
    }

}

void	QtWindow::initialize()
{
  std::stringstream	styleStream;

  this->setWindowTitle("Light Pokedex");
  this->OnOff_ = false;
  this->initializePokeFont();

  this->onOffButton_ = new QPushButton("START", this);
  this->onOffButton_->setGeometry(448, 446, 120, 62);
  this->makeButtonTransparent(this->onOffButton_);
  styleStream << "background-image: url("<< ON_BUTTON_IMG << ");" << "font: bold 12px;";
  this->onOffButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->onOffButton_, SIGNAL(clicked()), this, SLOT(toggleOnOff()));

  this->createHomeMenu();
}

void	QtWindow::setBackgroundImage(const char *filename)
{
  QPalette	palette;
  QPixmap	pixmap(filename);
  QBrush	brush(pixmap);

  palette.setBrush(QPalette::Background, brush);
  this->setPalette(palette);
}

void	QtWindow::blockResize(size_t width, size_t height)
{
  this->setFixedSize(width, height);
}
