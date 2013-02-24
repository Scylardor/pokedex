//
// PokemonView.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 26 22:42:37 2013 Alexandre Baron
// Last update Sun Jan 27 21:46:47 2013 Alexandre Baron
//

#ifndef	POKEMONVIEW_HH_
# define POKEMONVIEW_HH_

# include <QWidget>
# include <QLabel>
# include <QTextEdit>

# include "Pokemon.hh"

class	PokemonView : public QWidget
{
  Q_OBJECT

  QLabel	*id_;
  QLabel	*img_;
  QLabel	*name_;
  QLabel	*species_;
  QLabel	*firstType_;
  QLabel	*secondType_;
  QTextEdit	*desc_;

public:
  PokemonView(const QFont &pokeFont, QWidget *parent = 0);
  ~PokemonView();

  void	initialize(const QFont &pokeFont);
  void	clear();
  void	setViewOfPokemon(const Pokemon *);
  void	setPkmnImage(QPixmap image) { this->img_->setPixmap(image); }
  void	setPkmnName(const QString &name) { this->name_->setText(name); }
  void	setFirstTypeImage(QImage *image);
  void	setSecondTypeImage(QImage *image);
};

#endif
