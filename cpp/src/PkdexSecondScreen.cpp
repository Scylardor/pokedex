//
// PkdexMainScreen.hh<2> for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Fri Mar  1 22:16:28 2013 Alexandre Baron
// Last update Sun Mar  3 16:03:42 2013 Alexandre Baron
//

#include <iostream>
#include <sstream>

#include "PkdexSecondScreen.hh"
#include "makeButtonTransparent.hh"

PkdexSecondScreen::PkdexSecondScreen(const QFont &font, QWidget *parent)
  : QWidget(parent)
{
  this->initialize(font, parent);
}

PkdexSecondScreen::~PkdexSecondScreen()
{
  //  delete this->description_;
}

void	PkdexSecondScreen::initialize(const QFont &font, QWidget *parent)
{
  this->misc_ = new PokemonMiscInfos(font, this);
  this->matchObjs_[PKMN_DESC] = this->misc_;

}

void	PkdexSecondScreen::showPokemonDesc(const Pokemon *pkmn)
{
  this->misc_->fill(pkmn);
  this->misc_->setVisible(true);
}

void	PkdexSecondScreen::clear()
{
  this->misc_->setVisible(false);
}
