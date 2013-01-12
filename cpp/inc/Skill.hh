//
// Skill.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 13:31:57 2013 Alexandre Baron
// Last update Sat Jan 12 13:46:06 2013 Alexandre Baron
//

#ifndef	SKILL_HH_
# define SKILL_HH_

# include <string>

# include "Types.hh"

class	Skill
{
  std::string	machineType_;
  std::string	desc_;
  std::string	kind_;
  std::string	location_;
  std::string	suggestion_;
  unsigned short power_;
  unsigned short accuracy_;
  eType	type_;

public:
  Skill() {}
  ~Skill() {}

};

#endif
