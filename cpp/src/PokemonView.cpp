//
// PokemonView.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 26 22:48:51 2013 Alexandre Baron
// Last update Sun Jan 27 02:06:47 2013 Alexandre Baron
//

#include "PokemonView.hh"

PokemonView::PokemonView(const QFont &pokeFont, QWidget *parent)
  : QWidget(parent)
{
  this->initialize(pokeFont);
}

PokemonView::~PokemonView()
{
  delete this->img_;
  delete this->name_;
}

void	PokemonView::clear()
{
  this->img_->clear();
  this->name_->clear();
}

void	PokemonView::initialize(const QFont &pokeFont)
{
  this->img_ = new QLabel(this);
  this->name_ = new QLabel(this);
  this->id_ = new QLabel(this);
  this->species_ = new QLabel(this);
  this->firstType_ = new QLabel(this);
  this->secondType_ = new QLabel(this);
  this->desc_ = new QTextEdit(this);
  this->img_->setGeometry(20, 15, 82, 82);
  this->id_->setGeometry(25, 100, 70, 20);
  this->name_->setGeometry(110, 35, 130, 20);
  this->firstType_->setGeometry(40, 115, 34, 16);
  this->secondType_->setGeometry(40, 135, 34, 16);
  this->desc_->setGeometry(110, 60, 130, 90);
  this->desc_->setStyleSheet("border: none;");
  this->desc_->setCurrentFont(pokeFont);
  this->desc_->setReadOnly(true);
}

void	PokemonView::setViewOfPokemon(const Pokemon *pkmn)
{
  this->clear();
  this->id_->setText("No." + pkmn->getId());
  //  this->species_->setText(pkmn->getSpecies());
  this->img_->setPixmap(QPixmap::fromImage(pkmn->getPicture()));
  this->name_->setText(pkmn->getName());
  this->desc_->setText(pkmn->getDescription());
}

void	PokemonView::setFirstTypeImage(QImage *image)
{
  this->firstType_->setPixmap(QPixmap::fromImage(*image));

}

void	PokemonView::setSecondTypeImage(QImage *image)
{
  this->secondType_->setPixmap(QPixmap::fromImage(*image));

}
