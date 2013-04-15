//
// QtWindow.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 22:20:14 2013 Alexandre Baron
// Last update Mon Apr 15 14:47:29 2013 Alexandre Baron
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

// Function used to display informations about a certain Pokemon.
// It will interrogate the database about its infos and then fill it in the right places.
// On main and second screens
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
  this->currentPkmnId_ = pkmn->getId().toInt();
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

void	QtWindow::showPrevPokemon()
{
  QString	newId("");

  if (this->currentPkmnId_ > 0)
    {
      this->currentPkmnId_--;
      newId = QString::number(this->currentPkmnId_);
      if (this->currentPkmnId_ < 10)
	{
	  newId.prepend("00");
	}
      else if (this->currentPkmnId_ >= 10 && this->currentPkmnId_ < 100)
	{
	  newId.prepend("0");
	}

      Pokemon	*matching = this->database_->getPokemon(newId);

      if (matching != NULL)
	{
	  showPokemonInfos(matching);
	}
    }
}

void	QtWindow::showNextPokemon()
{
  QString	newId("");

  if (this->currentPkmnId_ < 493)
    {
      this->currentPkmnId_++;
      newId = QString::number(this->currentPkmnId_);
      if (this->currentPkmnId_ < 10)
	{
	  newId.prepend("00");
	}
      else if (this->currentPkmnId_ >= 10 && this->currentPkmnId_ < 100)
	{
	  newId.prepend("0");
	}

      Pokemon	*matching = this->database_->getPokemon(newId);

      if (matching != NULL)
	{
	  showPokemonInfos(matching);
	}
    }
}

// The "Database" is, for the moment, only composed of two XML files : one for the pokemons data and one for the attacks data.
// If one of these two files cannot be opened or read, this is considered as a critical error (the program cannot work well without it).
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


// Main initialization function.
// Proceeds by steps the multiple components of the window:
// - the buttons : on/off, blue "LIST" button, prev/next arrows buttons
// - and then the other "big" components (the database, the main and second screen)
// Then hide all the widgets to give a "shut down" appearance
void	QtWindow::initialize()
{
  std::stringstream	styleStream;

  this->criticalError_ = false;
  this->setWindowTitle("Light Pokedex");
  this->OnOff_ = false;
  this->currentPkmnId_ = 0;
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
  styleStream.str("");
  styleStream << "font: bold italic 10px;";
  this->listButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->listButton_, SIGNAL(clicked()), this, SLOT(showTheList()));

  this->prevButton_ = new QPushButton(this);
  this->prevButton_->setGeometry(468, 392, 37, 37);
  makeButtonTransparent(this->prevButton_);
  // styleStream.str("");
  // styleStream << "background-image: url("<< LARROW_BUTTON_IMG << ");";
  // this->prevButton_->setStyleSheet(styleStream.str().c_str());
  // this->prevButton_->resize(42, 42);
  connect(this->prevButton_, SIGNAL(clicked()), this, SLOT(showPrevPokemon()));

  this->nextButton_ = new QPushButton(this);
  this->nextButton_->setGeometry(507, 390, 37, 37);
  makeButtonTransparent(this->nextButton_);
  // styleStream.str("");
  // styleStream << "background-image: url("<< RARROW_BUTTON_IMG << ");";
  // this->nextButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->nextButton_, SIGNAL(clicked()), this, SLOT(showNextPokemon()));

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
