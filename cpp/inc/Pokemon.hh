//
// Pokemon.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 19:16:08 2013 Alexandre Baron
// Last update Mon Jan 21 22:06:51 2013 Alexandre Baron
//

#ifndef	POKEMON_HH_
# define POKEMON_HH_

# include <map>
# include <vector>

# include "Skill.hh"

typedef	enum PokemonType
{
  NONE = 0,
  FIRE,
  WATER,
  GRASS,
  BUG,
  ELECTRIC,
  FLYING,
  POISON,
  DRAGON,
  ICE,
  NORMAL,
  ROCK,
  GROUND,
  FIGHTING,
  PSYCHIC,
  GHOST,
  STEEL,
  DARK
}	Type;

typedef	struct s_evolution
{
  unsigned int	id;
  std::string	name;
  unsigned int	requiredLvl;
  std::string	condition;
}	t_evolution;

class	Pokemon
{
  unsigned int	id_;
  std::string	name_;
  unsigned int	exp_;
  std::string	ability_;
  std::string	species_;
  std::map<std::string, unsigned int>	stats_;
  Type	types_[2];
  float	ratios_[2];
  float	height_;
  float	weight_;
  std::string	eggGroups_[2];
  std::string	description_;
  std::vector<Move *>	moves_;
  std::vector<t_evolution *>	evolutions_;

public:
  Pokemon() {}
  ~Pokemon() {}

  void	setId(unsigned int id) { this->id_ = id; }
  void	setName(const std::string &name) { this->name_ = name; }
  void	setExp(unsigned int exp) { this->exp_ = exp; }
  void	setAbility(const std::string &ability) { this->ability_ = ability; }
  void	setSpecies(const std::string &spec) { this->species_ = spec; }
  void	setStats(const std::map<std::string, unsigned int> &stats) {this->stats_ = stats; }
  void	setTypes(Type type, Type optional = NONE);
  void	setRatios(float male, float female);
  void	setHeight(float height) { this->height_ = height; }
  void	setWeight(float weight) { this->weight_ = weight; }
  void	setEggGroups(const std::string &eggG, const std::string &opt = "");
  void	setDescription(const std::string &desc) { this->description_ = desc; }
  void	setMoves(const std::vector<Move*> &moves);
  void	setEvolutions(const std::vector<t_evolution *> &evols);

};

#endif
