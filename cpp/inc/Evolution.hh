//
// Evolution.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 13:22:57 2013 Alexandre Baron
// Last update Sat Jan 12 13:46:11 2013 Alexandre Baron
//

#ifndef	EVOLUTION_HH_
# define EVOLUTION_HH_

# include <string>

class	Evolution
{
  unsigned short id_;
  std::string	name_;
  std::string	condition_;
  unsigned short requiredLvl_;

public:
  Evolution() {}
  ~Evolution() {}

};

#endif
