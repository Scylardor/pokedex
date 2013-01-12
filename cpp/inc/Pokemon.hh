//
// Pokemon.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 13:02:01 2013 Alexandre Baron
// Last update Sat Jan 12 13:45:55 2013 Alexandre Baron
//

#ifndef	POKEMON_HH_
# define POKEMON_HH_

# include <vector>
# include <string>

# include "Skill.hh"
# include "Evolution.hh"

typedef	struct s_stats
{
  unsigned short HP;
  unsigned short ATK;
  unsigned short DEF;
  unsigned short SPATK;
  unsigned short SPDEF;
  unsigned short SPD;
}	t_stats;

class	Pokemon
{
  unsigned short id_;
  float	height_;
  float	weight_;
  unsigned int	maxExp_;
  std::string	name_;
  std::string	types_[2];
  std::string	eggGroups_[2];
  std::string	description_;
  std::string	ability_;
  std::string	species_;
  t_stats	stats_;
  std::vector<Skill> moves_;
  std::vector<Evolution> evolves_;

public:
  Pokemon() {}
  ~Pokemon() {}

};

#endif
