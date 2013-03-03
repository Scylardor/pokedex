//
// PkdexMainScreen.hh<2> for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Fri Mar  1 22:16:28 2013 Alexandre Baron
// Last update Sun Mar  3 16:36:26 2013 Alexandre Baron
//

#include <iostream>
#include <sstream>

#include "PkdexMainScreen.hh"
#include "makeButtonTransparent.hh"

PkdexMainScreen::PkdexMainScreen(const QFont &font, QWidget *parent)
  : QWidget(parent)
{
  this->initialize(font, parent);
}

PkdexMainScreen::~PkdexMainScreen()
{
  delete this->homeMenu_;
}

void	PkdexMainScreen::initializeHomeMenu(QWidget *parent)
{
  QButtonGroup	*group;
  QPushButton	*searchPokemonButton;
  QPushButton	*pokemonListButton;
  QPushButton	*pokemonBattleButton;
  std::stringstream	styleStream;

  this->homeMenu_ = new QWidget(this);
  this->homeMenu_->setGeometry(0, 0, 260, 175);
  searchPokemonButton = new QPushButton("SEARCH A POKEMON", this->homeMenu_);
  pokemonListButton = new QPushButton("POKEMON DATABASE", this->homeMenu_);
  pokemonBattleButton = new QPushButton("BATTLE SIMULATION", this->homeMenu_);
  group = new QButtonGroup(this->homeMenu_);

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
  connect(group, SIGNAL(buttonClicked(int)), parent, SLOT(manageButtonClicks(int)));
}

// We're connecting the list to the parent (the window itself) in order to
// being able to update the whole interface (and not just the main screen)
void	PkdexMainScreen::initializePokemonList(QWidget *parent)
{
  this->pokemonList_ = new QListWidget(this);
  this->pokemonList_->setFont(this->pokeFont_);
  this->pokemonList_->setGeometry(20, 20, 225, 135);
  this->pokemonList_->setStyleSheet("border: none;");
  connect(this->pokemonList_, SIGNAL(itemDoubleClicked(QListWidgetItem*)), parent, SLOT(showPkmnInfos(QListWidgetItem*)));
}

void	PkdexMainScreen::initializePokemonInfos()
{
  this->pokemonInfos_ = new PokemonMainInfos(this->pokeFont_, this);
  //  this->pokemonInfos_->setGeometry(55, 150, 260, 175);
  this->pokemonInfos_->setFont(this->pokeFont_);
}

// Initialization function of the Pokedex main screen.
// Will initialize everything that can be displayed by the main screen:
// * the home menu
// * the pokemons list
// * the detailed description of a pokemon
// * and some other things coming soon...
void	PkdexMainScreen::initialize(const QFont &font, QWidget *parent)
{
  this->pokeFont_ = font;
  this->initializeHomeMenu(parent);
  this->initializePokemonList(parent);
  this->initializePokemonInfos();
  this->matchObjs_[HOME_MENU] = this->homeMenu_;
  this->matchObjs_[POKEMON_LIST] = this->pokemonList_;
  this->matchObjs_[POKEMON_DESC] = this->pokemonInfos_;
}

void	PkdexMainScreen::showPokemon(const Pokemon *pkmn, QImage *firstType, QImage *secondType)
{
  this->pokemonInfos_->fill(pkmn, firstType, secondType);
  this->pokemonList_->setVisible(false);
  this->pokemonInfos_->setVisible(true);
}

void	PkdexMainScreen::addToPokemonList(int id, QListWidgetItem *pkmnItem)
{
  this->pokemonList_->insertItem(id, pkmnItem);
}
