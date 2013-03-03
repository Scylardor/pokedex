//
// PokemonView.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 26 22:42:37 2013 Alexandre Baron
// Last update Sun Mar  3 13:08:36 2013 Alexandre Baron
//

#ifndef	POKEMONVIEW_HH_
# define POKEMONVIEW_HH_

# include <QWidget>
# include <QLabel>
# include <QTextEdit>

# include "Pokemon.hh"

class	PokemonMainInfos : public QWidget
{
  QLabel	*id_;
  QLabel	*img_;
  QLabel	*name_;
  QLabel	*firstType_;
  QLabel	*secondType_;
  QLabel	*ability_;
  QLabel	*height_;
  QLabel	*weight_;

public:
  PokemonMainInfos(const QFont &pokeFont, QWidget *parent = 0);
  ~PokemonMainInfos();

  void	initialize(const QFont &pokeFont);
  void	clear();
  void	fill(const Pokemon *pkmn, const QImage *firstType, const QImage *secondType);
  void	setPkmnImage(const QPixmap image) { this->img_->setPixmap(image); }
  void	setPkmnName(const QString &name) { this->name_->setText(name); }

};


class	PokemonMiscInfos : public QWidget
{
  QTextEdit	*desc_;

public:
  PokemonMiscInfos(const QFont &pokeFont, QWidget *parent = 0);
  ~PokemonMiscInfos();

  void	initialize(const QFont &pokeFont);
  void	clear();
  void	fill(const Pokemon *pkmn);

};

// class	PokemonView : public QWidget
// {
//   Q_OBJECT

//   PkmnMainScreen	*mainScreen_;
//   PkmnSecondScreen	*secondScreen_;

// public:
//   PokemonView(const QFont &pokeFont, QWidget *parent = 0);
//   ~PokemonView();

//   void	initialize(const QFont &pokeFont);
//   void	setViewOfPokemon(const Pokemon *);
//   void	setFirstTypeImage(const QImage *image) { this->mainScreen_->setFirstTypeImage(image); }
//   void	setSecondTypeImage(const QImage *image) { this->mainScreen_->setSecondTypeImage(image); }
// };

#endif
