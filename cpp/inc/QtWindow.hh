//
// QtWindow.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 21:54:06 2013 Alexandre Baron
// Last update Mon Apr 15 14:18:43 2013 Alexandre Baron
//

#ifndef	QTWINDOW_HH_
# define QTWINDOW_HH_

# include <QtGui>

# include "PkdexMainScreen.hh"
# include "PkdexSecondScreen.hh"
# include "PokeDatabase.hh"

# define	POKEDEX_OFF_IMG	":/PokedexOff.png"
# define	POKEDEX_ON_IMG	":/PokedexOn.png"
# define	ON_BUTTON_IMG	":/boutonON.png"
# define	LARROW_BUTTON_IMG	":/leftarrow.png"
# define	RARROW_BUTTON_IMG	":/rightarrow.png"
//# define	DUMMY_IMG	"/Pokemons/3.png"

class	QtWindow : public QMainWindow
{
  Q_OBJECT

  // Widgets and objects of all kinds
  PkdexMainScreen	*mainScreen_;
  PkdexSecondScreen	*secondScreen_;
  QPushButton	*onOffButton_;
  QPushButton	*listButton_;
  QPushButton	*prevButton_;
  QPushButton	*nextButton_;

  PokeDatabase	*database_;
  int		currentPkmnId_;

  // Window class properties
  QFont		pokeFont_;
  bool		OnOff_;
  bool		criticalError_;

public:
  QtWindow();
  ~QtWindow();

  void	setBackgroundImage(const char *filename);
  void	blockResize(size_t width, size_t height);
  bool	getCriticalError() const { return this->criticalError_; }

private:
  void	initialize();
  void	initializeDatabase();
  void	initializePokeFont();
  void	initializeMainScreen();
  void	initializeSecondScreen();

  void	showPokemonInfos(const Pokemon *pkmn);

  void	hideEverything();

private slots:
  void	toggleOnOff();
  void	manageButtonClicks(int);
  void	retrievePokemon(QListWidgetItem *pkmn);
  void	showTheList();
  void	showPrevPokemon();
  void	showNextPokemon();
};

void	makeButtonTransparent(QPushButton *);

#endif
