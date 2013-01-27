//
// Pokemon.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 19:16:08 2013 Alexandre Baron
// Last update Sun Jan 27 01:53:34 2013 Alexandre Baron
//

#ifndef	POKEMON_HH_
# define POKEMON_HH_

# include <map>
# include <vector>

# include <QApplication>
# include <QIcon>

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
  QString	id;
  QString	name;
  QString	requiredLvl;
  QString	condition;
  }	t_evolution;

class	Pokemon
{
  QString	id_;
  QString	name_;
  QString	exp_;
  QString	ability_;
  QString	species_;
  std::map<QString, unsigned int>	stats_;
  Type	types_[2];
  QString	ratios_[2];
  QString	height_;
  QString	weight_;
  QString	eggGroups_[2];
  QString	description_;
  std::vector<Move *>	moves_;
  std::vector<t_evolution *>	evolutions_;
  QImage	picture_;
  QIcon		miniature_;

public:
  Pokemon() {}
  ~Pokemon() {}

  void	setId(const QString &id) { this->id_ = id; }
  void	setName(const QString &name) { this->name_ = name; }
  void	setExp(const QString &exp) { this->exp_ = exp; }
  void	setAbility(const QString &ability) { this->ability_ = ability; }
  void	setSpecies(const QString &spec) { this->species_ = spec; }
  void	setStats(const std::map<QString, unsigned int> &stats) {this->stats_ = stats; }
  void	setStat(const QString &stat, unsigned int value) { this->stats_[stat] = value; }
  void	setTypes(Type type, Type optional = NONE);
  void	setTypeByIndex(int index, Type type) { this->types_[index] = type; }
  void	setRatios(const QString &male, const QString &female);
  void	setHeight(const QString &height) { this->height_ = height; }
  void	setWeight(const QString &weight) { this->weight_ = weight; }
  void	setEggGroups(const QString &eggG, const QString &opt = "");
  void	setDescription(const QString &desc) { this->description_ = desc; }
  void	setMoves(const std::vector<Move*> &moves);
  void	setEvolutions(const std::vector<t_evolution *> &evols);
  void	setImage(const QString &filename) { this->picture_.load(filename); }
  void	setMiniature(const QString &filename) { this->miniature_.addFile(filename); }

  QString	getId() const { return this->id_; }
  QString	getName() const { return this->name_; }
  QString	getExp() const { return this->exp_; }
  QString	getAbility() const { return this->ability_; }
  QString	getSpecies() const { return this->species_; }
  unsigned int	getStat(QString statName) { return (this->stats_[statName]); }
  Type		getTypeByIndex(int index) const { return this->types_[index]; }
  QString	getRatioByIndex(int index) const { return this->ratios_[index]; }
  QString	getHeight() const { return this->height_; }
  QString	getWeight() const { return this->weight_; }
  QString	getEggGroupByIndex(int index) const { return this->eggGroups_[index]; }
  QString	getDescription() const { return this->description_; }
  QString	getMoves() const;
  QString	getEvolutions() const;
  QImage	getPicture() const { return this->picture_; }
  QIcon		getMiniature() const { return this->miniature_; }
};

	typedef	void	(Pokemon::*PkmnSetter)(const QString &);

#endif
