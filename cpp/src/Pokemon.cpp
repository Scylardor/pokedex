//
// Pokemon.cpp for pokemon in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 21:26:09 2013 Alexandre Baron
// Last update Mon Jan 21 22:04:18 2013 Alexandre Baron
//

#include "Pokemon.hh"

void	Pokemon::setRatios(float male, float female)
{
  this->ratios_[0] = male;
  this->ratios_[1] = female;
}

void	Pokemon::setTypes(Type type, Type optional)
{
  this->types_[0] = type;
  this->types_[1] = optional;
}

void	Pokemon::setEggGroups(const std::string &eggG, const std::string &opt)
{
  this->eggGroups_[0] = eggG;
  this->eggGroups_[1] = opt;
}

void	Pokemon::setMoves(const std::vector<Move*> &moves)
{
  std::vector<Move*>::const_iterator	it;

  for (it = moves.begin(); it != moves.end(); ++it) {


  }

}

void	Pokemon::setEvolutions(const std::vector<t_evolution *> &evols)
{
  std::vector<t_evolution *>::const_iterator	it;

  for (it = evols.begin(); it != evols.end(); ++it) {


  }

}

