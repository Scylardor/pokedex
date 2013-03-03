//
// PkdexMainScreen.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Fri Mar  1 22:09:51 2013 Alexandre Baron
// Last update Sun Mar  3 16:01:02 2013 Alexandre Baron
//

#ifndef	PKDEXSECONDSCREEN_HH_
# define PKDEXSECONDSCREEN_HH_

# include <QWidget>
# include <QFont>

# include "PokemonInfos.hh"

typedef	enum SecondScreenObjs
{
  PKMN_DESC
}	SecondScreenObjs;


class	PkdexSecondScreen : public QWidget
{
  PokemonMiscInfos	*misc_;
  std::map<SecondScreenObjs, QWidget *>	matchObjs_;

public:
  PkdexSecondScreen(const QFont &font, QWidget *parent = 0);
  ~PkdexSecondScreen();

  void	initialize(const QFont &font, QWidget *parent);
  void	showPokemonDesc(const Pokemon *pkmn);
  void	clear();
};

#endif
