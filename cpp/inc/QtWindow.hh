//
// QtWindow.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 21:54:06 2013 Alexandre Baron
// Last update Sat Jan 26 02:34:18 2013 Alexandre Baron
//

#ifndef	QTWINDOW_HH_
# define QTWINDOW_HH_

# include <QtGui>

#include "PokeDatabase.hh"

# define	POKEDEX_OFF_IMG	"/home/baron_a/Projects/pokemon/resources/Images/PokedexOff.png"
# define	POKEDEX_ON_IMG	"/home/baron_a/Projects/pokemon/resources/Images/PokedexOn.png"
# define	ON_BUTTON_IMG	"/home/baron_a/Projects/pokemon/resources/Images/boutonON.png"

class	QtWindow : public QMainWindow
{
  Q_OBJECT

  // Widgets and objects of all kinds
  QPushButton	*onOffButton_;
  QWidget	*homeMenu_;
  QWidget	*pokemonSearchForm_;
  QWidget	*pokemonArena_;
  QListWidget	*pokemonList_;

  PokeDatabase	*database_;

  // Window class properties
  QFont		pokeFont_;
  bool		OnOff_;
  bool		criticalError_;

public:
  QtWindow();
  ~QtWindow() {}

  void	setBackgroundImage(const char *filename);
  void	blockResize(size_t width, size_t height);
  bool	getCriticalError() const { return this->criticalError_; }

private:
  void	makeButtonTransparent(QPushButton *);

  void	initialize();
  void	initializePokeFont();
  void	initializeHomeMenu();
  void	initializeDatabase();
  void	initializePkmnList();

  void	hideEverything();
  void	displayPokemonsList();

private slots:
  void	toggleOnOff();
  void	manageButtonClicks(int);
};

#endif
