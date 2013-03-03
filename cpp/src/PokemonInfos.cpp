//
// PokemonView.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 26 22:48:51 2013 Alexandre Baron
// Last update Sun Mar  3 13:19:03 2013 Alexandre Baron
//

#include "PokemonInfos.hh"

///////////////////// PkmnMainInfos Methods ///////////////////////////
//////////////// All that will be on the main screen //////////////////
PokemonMainInfos::PokemonMainInfos(const QFont &pokeFont, QWidget *parent)
  : QWidget(parent)
{
  this->initialize(pokeFont);
}

PokemonMainInfos::~PokemonMainInfos()
{
  delete this->img_;
  delete this->name_;
  delete this->id_;
  delete this->firstType_;
  delete this->secondType_;
}

void	PokemonMainInfos::clear()
{
  this->img_->clear();
  this->name_->clear();
  this->secondType_->clear();
}

void	PokemonMainInfos::initialize(const QFont &pokeFont)
{
  this->img_ = new QLabel(this);
  this->name_ = new QLabel(this);
  this->id_ = new QLabel(this);
  this->firstType_ = new QLabel(this);
  this->secondType_ = new QLabel(this);
  this->ability_ = new QLabel(this);
  this->height_ = new QLabel(this);
  this->weight_ = new QLabel(this);

  this->img_->setGeometry(20, 15, 82, 82);
  this->id_->setGeometry(25, 100, 70, 20);
  this->firstType_->setGeometry(40, 115, 34, 16);
  this->secondType_->setGeometry(40, 135, 34, 16);

  this->name_->setGeometry(110, 35, 130, 20);
  this->ability_->setGeometry(110, 110, 160, 40);
  this->height_->setGeometry(110, 60, 130, 20);
  this->weight_->setGeometry(110, 85, 130, 20);
}

void	PokemonMainInfos::fill(const Pokemon *pkmn, const QImage *firstType, const QImage *secondType)
{
  this->clear();
  this->id_->setText("No." + pkmn->getId());
  this->img_->setPixmap(QPixmap::fromImage(pkmn->getPicture()));
  this->name_->setText(pkmn->getName());
  this->firstType_->setPixmap(QPixmap::fromImage(*firstType));
  if (secondType != NULL)
    {
      this->secondType_->setPixmap(QPixmap::fromImage(*secondType));
    }
  this->ability_->setText("Ability:\n\n" + pkmn->getAbility());
  this->height_->setText(pkmn->getHeight() + " meters");
  this->weight_->setText(pkmn->getWeight() + " kg");
}


///////////////////// PokemonMiscInfos Methods ////////////////////////////////
PokemonMiscInfos::PokemonMiscInfos(const QFont &pokeFont, QWidget *parent)
  : QWidget(parent)
{
  this->initialize(pokeFont);
}

PokemonMiscInfos::~PokemonMiscInfos()
{
  delete this->desc_;
}

void	PokemonMiscInfos::clear()
{
}

void	PokemonMiscInfos::initialize(const QFont &pokeFont)
{
  this->desc_ = new QTextEdit(this);
  this->desc_->setGeometry(15, 20, 220, 105);
  this->desc_->setStyleSheet("border: none;");
  this->desc_->setCurrentFont(pokeFont);
  this->desc_->setReadOnly(true);
  this->desc_->viewport()->setAutoFillBackground(false);
  this->desc_->setTextColor(QColor(72, 255, 0));
}

void	PokemonMiscInfos::fill(const Pokemon *pkmn)
{
  this->desc_->setText(pkmn->getDescription());
}
