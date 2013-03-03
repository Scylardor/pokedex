//
// PkdexMainScreen.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Fri Mar  1 22:09:51 2013 Alexandre Baron
// Last update Sun Mar  3 16:36:36 2013 Alexandre Baron
//

#ifndef	PkdexMainScreen_HH_
# define PkdexMainScreen_HH_

# include <map>

# include <QWidget>
# include <QtGui>

# include "Pokemon.hh"
# include "PokemonInfos.hh"

typedef	enum MainScreenObjs
{
  HOME_MENU,
  POKEMON_LIST,
  POKEMON_DESC
}	MainScreenObjs;

class	PkdexMainScreen : public QWidget
{
  QWidget	*homeMenu_;
  QWidget	*pokemonSearchForm_;
  QWidget	*pokemonArena_;
  QListWidget	*pokemonList_;
  PokemonMainInfos	*pokemonInfos_;
  std::map<MainScreenObjs, QWidget *>	matchObjs_;
  QFont		pokeFont_;

public:
  PkdexMainScreen(const QFont &font, QWidget *parent = 0);
  ~PkdexMainScreen();

  void	initialize(const QFont &font, QWidget *parent);
  void	initializeHomeMenu(QWidget *parent);
  void	initializePokemonList(QWidget *parent);
  void	initializePokemonInfos();

  void	toggleVisibility(MainScreenObjs obj, bool visible) { matchObjs_[obj]->setVisible(visible); }
  void	showPokemon(const Pokemon *pkmn, QImage *firstType, QImage *secondType);
  void	addToPokemonList(int id, QListWidgetItem *pkmnItem);
  void	resetPokemonList() { this->pokemonList_->setCurrentRow(0); }
};

#endif
