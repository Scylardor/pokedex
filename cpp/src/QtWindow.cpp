//
// QtWindow.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 22:20:14 2013 Alexandre Baron
// Last update Sun Mar  3 16:36:10 2013 Alexandre Baron
//

#include <sstream>
#include <iostream>

#include <QMessageBox>
#include <QButtonGroup>

#include "QtWindow.hh"
#include "makeButtonTransparent.hh"

QtWindow::QtWindow()
  : QMainWindow()
{
  this->initialize();
}

QtWindow::~QtWindow()
{
  delete this->mainScreen_;
  delete this->secondScreen_;
  delete this->onOffButton_;
  delete this->database_;
}

// Atm, buttonID is attributed by the QButtonGroup of the home menu widget.
// see QtWindow::initializeHomeMenu().
void	QtWindow::manageButtonClicks(int buttonID)
{
  this->mainScreen_->toggleVisibility(HOME_MENU, false);
  if (buttonID == 0)
    {
      //      this->searchPokemonForm_->setVisible(true);
    }
  else if (buttonID == 1)
    {
      this->mainScreen_->resetPokemonList();
      this->mainScreen_->toggleVisibility(POKEMON_LIST, true);
    }
  else
    {
      //      this->pokemonArena_->setVisible(true);
    }
}

// When pressing the Start button when the Pokedex is On makes everything stop
void	QtWindow::hideEverything()
{
  this->mainScreen_->setVisible(false);
  this->mainScreen_->toggleVisibility(POKEMON_LIST, false);
  this->mainScreen_->toggleVisibility(POKEMON_DESC, false);
  this->secondScreen_->setVisible(false);
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
      this->mainScreen_->setVisible(true);
      this->mainScreen_->toggleVisibility(HOME_MENU, true);
    }
  this->OnOff_ = !this->OnOff_;
}

void	QtWindow::showTheList()
{
  if (this->OnOff_ == true)
    {
      this->mainScreen_->toggleVisibility(HOME_MENU, false);
      this->mainScreen_->toggleVisibility(POKEMON_DESC, false);
      this->mainScreen_->toggleVisibility(POKEMON_LIST, true);
      this->secondScreen_->clear();
    }
}

void	QtWindow::showPokemonInfos(const Pokemon *pkmn)
{
  QImage	*firstTypeImg;
  QImage	*secTypeImg = NULL;

  firstTypeImg = this->database_->getTypeImage(pkmn->getTypeByIndex(0));
  if (pkmn->getTypeByIndex(1) != NONE)
    {
      secTypeImg = this->database_->getTypeImage(pkmn->getTypeByIndex(1));
    }
  this->mainScreen_->showPokemon(pkmn, firstTypeImg, secTypeImg);
  this->secondScreen_->setVisible(true);
  this->secondScreen_->showPokemonDesc(pkmn);
}

// Function called when a pokemon is selected in the pokemon database.
// It will ask the database about this Pokemon informations, and correctly put
// them on the screen via the showPokemonInfos function.
void	QtWindow::retrievePokemon(QListWidgetItem *pkmn)
{
  Pokemon	*matching;

  matching = this->database_->getPokemon((pkmn->text().split(" "))[0]);
  if (matching != NULL)
    {
      showPokemonInfos(matching);
    }
}

void	QtWindow::initializeDatabase()
{
  this->database_ = new PokeDatabase();
  if (this->database_->parseSkillsFile() < 0 || this->database_->parsePokemonsFile() < 0)
    {
      QMessageBox::critical(NULL, "Pokedex", "Error ! Unable to load XML file, or invalid XML file. Exiting.", QMessageBox::Ok);
      this->criticalError_ = true;
    }
}

// Initializing the main screen widget and all of its components.
// That's why we, for now, initialize the Pokemon list once and for all here
// instead of re-filling it each time we access to it.
// It may change in an indetermined future.
void	QtWindow::initializeMainScreen()
{
  std::map<QString, Pokemon*>	pkmnList = this->database_->getPokemonsList();
  std::map<QString, Pokemon*>::iterator it;

  this->mainScreen_ = new PkdexMainScreen(this->pokeFont_, this);
  this->mainScreen_->setGeometry(55, 150, 260, 175);

  for (it = pkmnList.begin(); it != pkmnList.end(); ++it)
    {
      QListWidgetItem	*pkmnItem = new QListWidgetItem((it->second)->getMiniature(), (it->second)->getId() + " " + (it->second)->getName());

      this->mainScreen_->addToPokemonList(((it->second)->getId().toInt()) - 1, pkmnItem);
    }
}

void	QtWindow::initializeSecondScreen()
{
  this->secondScreen_ = new PkdexSecondScreen(this->pokeFont_, this);
  this->secondScreen_->setGeometry(448, 160, 240, 115);
}


// Pokemon GB.ttf font is a free software for any purpose, made by Jackster Productions
// http://www.fontspace.com/jackster-productions/pokemon-gb
void	QtWindow::initializePokeFont()
{
  this->pokeFont_.setFamily("Pokemon GB");
  this->pokeFont_.setPixelSize(12);
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

  this->criticalError_ = false;
  this->setWindowTitle("Light Pokedex");
  this->OnOff_ = false;
  this->initializePokeFont();

  this->onOffButton_ = new QPushButton("START", this);
  this->onOffButton_->setGeometry(448, 446, 120, 62);
  makeButtonTransparent(this->onOffButton_);
  styleStream << "background-image: url("<< ON_BUTTON_IMG << ");" << "font: bold 12px;";
  this->onOffButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->onOffButton_, SIGNAL(clicked()), this, SLOT(toggleOnOff()));

  this->listButton_ = new QPushButton("LIST", this);
  this->listButton_->setGeometry(470, 287, 35, 25);
  makeButtonTransparent(this->listButton_);
  QPalette newPalette = palette();
  newPalette.setBrush(QPalette::Window, QBrush(Qt::transparent));
  this->listButton_->setPalette(newPalette);
  this->listButton_->setBackgroundRole(QPalette::Window);
  styleStream.str("");
  styleStream << "font: bold italic 10px;";
  this->listButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->listButton_, SIGNAL(clicked()), this, SLOT(showTheList()));

  this->initializeDatabase();
  this->initializeMainScreen();
  this->initializeSecondScreen();

  // this->pokemonArena_ = new QWidget(this);
  // this->pokemonSearchForm_ = new QWidget(this);

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
