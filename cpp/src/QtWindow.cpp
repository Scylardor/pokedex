//
// QtWindow.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 22:20:14 2013 Alexandre Baron
// Last update Sun Jan 20 20:30:36 2013 Alexandre Baron
//

#include <sstream>
#include <iostream>

#include <QButtonGroup>

#include "QtWindow.hh"

using namespace std;

QtWindow::QtWindow()
  : QMainWindow()
{
  this->initialize();
}

void	QtWindow::manageButtonClicks(int buttonID)
{
  this->homeMenu_->setVisible(false);
  if (buttonID == 0)
    {
      //      this->pokemonList_->setVisible(true);
    }
  else if (buttonID == 1)
    {
      //      this->pokemonArena_->setVisible(true);
    }
  else
    {
      this->pokemonList_->setVisible(true);
    }
  std::cout << "Button " << buttonID << " has been clicked" << std::endl;

}

// When pressing the Start button when the Pokedex is On makes everything stop
void	QtWindow::hideEverything()
{
  this->homeMenu_->setVisible(false);
  this->pokemonList_->setVisible(false);
  this->pokemonArena_->setVisible(false);
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
  QButtonGroup	*group;
  QPushButton	*searchPokemonButton;
  QPushButton	*pokemonListButton;
  QPushButton	*pokemonBattleButton;
  std::stringstream	styleStream;

  this->homeMenu_ = new QWidget(this);
  searchPokemonButton = new QPushButton("SEARCH A POKEMON", this->homeMenu_);
  pokemonListButton = new QPushButton("POKEMON DATABASE", this->homeMenu_);
  pokemonBattleButton = new QPushButton("BATTLE SIMULATION", this->homeMenu_);
  group = new QButtonGroup(this->homeMenu_);

  this->homeMenu_->setGeometry(55, 150, 260, 175);
  searchPokemonButton->setGeometry(20, 30, 220, 30);
  pokemonListButton->setGeometry(20, 75, 220, 30);
  pokemonBattleButton->setGeometry(20, 120, 220, 30);

  makeButtonTransparent(searchPokemonButton);
  makeButtonTransparent(pokemonListButton);
  makeButtonTransparent(pokemonBattleButton);

  styleStream << "text-align: left;font-size: 11px";
  searchPokemonButton->setStyleSheet(styleStream.str().c_str());
  pokemonListButton->setStyleSheet(styleStream.str().c_str());
  pokemonBattleButton->setStyleSheet(styleStream.str().c_str());

  searchPokemonButton->setFont(this->pokeFont_);
  pokemonListButton->setFont(this->pokeFont_);
  pokemonBattleButton->setFont(this->pokeFont_);

  group->addButton(searchPokemonButton, 0);
  group->addButton(pokemonListButton, 1);
  group->addButton(pokemonBattleButton, 2);

  connect(group, SIGNAL(buttonClicked(int)), this, SLOT(manageButtonClicks(int)));
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

  this->pokemonList_ = new QWidget(this);
  this->pokemonArena_ = new QWidget(this);
  this->hideEverything();
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
