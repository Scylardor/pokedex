//
// QtWindow.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 22:20:14 2013 Alexandre Baron
// Last update Thu Feb 28 23:13:59 2013 Alexandre Baron
//

#include <sstream>
#include <iostream>

#include <QMessageBox>
#include <QButtonGroup>

#include "QtWindow.hh"

//using namespace std;

QtWindow::QtWindow()
  : QMainWindow()
{
  this->initialize();
}

// Atm, buttonID is attributed by the QButtonGroup of the home menu widget.
// see QtWindow::initializeHomeMenu().
void	QtWindow::manageButtonClicks(int buttonID)
{
  this->homeMenu_->setVisible(false);
  if (buttonID == 0)
    {
      //      this->searchPokemonForm_->setVisible(true);
    }
  else if (buttonID == 1)
    {
      this->pokemonList_->setVisible(true);
      this->displayPokemonsList();
    }
  else
    {
      //      this->pokemonArena_->setVisible(true);
    }
  std::cout << "Button " << buttonID << " has been clicked" << std::endl;

}

// When pressing the Start button when the Pokedex is On makes everything stop
void	QtWindow::hideEverything()
{
  this->homeMenu_->setVisible(false);
  this->pokemonList_->setVisible(false);
  this->pokemonArena_->setVisible(false);
  this->pokemonSearchForm_->setVisible(false);
  this->pokemonInfos_->setVisible(false);
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

// Function called when a pokemon is selected in the pokemon database.
// It will ask the database about this Pokemon informations, and correctly put them
// on the screen.
void	QtWindow::showPkmnInfos(QListWidgetItem *pkmn)
{
  Pokemon	*matching;

  matching = this->database_->getPokemon((pkmn->text().split(" "))[0]);
  qDebug() << "kikou";
  this->pokemonInfos_->setViewOfPokemon(matching);
  qDebug() << "lol";
  this->pokemonInfos_->setFirstTypeImage(this->database_->getTypeImage(matching->getTypeByIndex(0)));
  qDebug() << "lol1";
  if (matching->getTypeByIndex(1) != NONE)
    {
      qDebug() << matching->getTypeByIndex(1);
      this->pokemonInfos_->setSecondTypeImage(this->database_->getTypeImage(matching->getTypeByIndex(1)));
    }
  qDebug() << "lol3";
  this->pokemonList_->setVisible(false);
  this->pokemonInfos_->setVisible(true);
}

void	QtWindow::displayPokemonsList()
{
  std::map<QString, Pokemon*>	pkmnList = this->database_->getPokemonsList();
  std::map<QString, Pokemon*>::iterator it;

  for (it = pkmnList.begin(); it != pkmnList.end(); ++it)
    {
      QListWidgetItem	*pkmnItem = new QListWidgetItem((it->second)->getMiniature(), (it->second)->getId() + " " + (it->second)->getName());

      this->pokemonList_->insertItem(((it->second)->getId().toInt()) - 1, pkmnItem);
    }
  this->pokemonList_->setCurrentRow(0);
}

void	QtWindow::initializePkmnList()
{
  this->pokemonList_ = new QListWidget(this);
  this->pokemonList_->setFont(this->pokeFont_);
  this->pokemonList_->setGeometry(72, 170, 225, 138);
  this->pokemonList_->setStyleSheet("border: none;");
  connect(this->pokemonList_, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showPkmnInfos(QListWidgetItem*)));
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


void	QtWindow::initializePkmnInfos()
{
  this->pokemonInfos_ = new PokemonView(this->pokeFont_, this);
  this->pokemonInfos_->setGeometry(55, 150, 260, 175);
  this->pokemonInfos_->setFont(this->pokeFont_);
}

void	QtWindow::initializeHomeMenu()
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
  this->makeButtonTransparent(this->onOffButton_);
  styleStream << "background-image: url("<< ON_BUTTON_IMG << ");" << "font: bold 12px;";
  this->onOffButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->onOffButton_, SIGNAL(clicked()), this, SLOT(toggleOnOff()));

  this->initializeHomeMenu();
  this->initializeDatabase();
  this->initializePkmnList();
  this->initializePkmnInfos();

  this->pokemonArena_ = new QWidget(this);
  this->pokemonSearchForm_ = new QWidget(this);


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
