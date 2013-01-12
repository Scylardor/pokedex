//
// Move.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 13:38:14 2013 Alexandre Baron
// Last update Sat Jan 12 13:43:16 2013 Alexandre Baron
//

#ifndef	MOVE_HH_
# define MOVE_HH_

# include <string>

# include "Skill.hh"

class	Move
{
  Skill	skill_;
  std::string	machineType_;
  unsigned short requiredLvl_;

public:
  Move();
  ~Move();

};

#endif
