//
// Skill.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 19:50:49 2013 Alexandre Baron
// Last update Mon Jan 21 22:06:42 2013 Alexandre Baron
//

#ifndef	SKILL_HH_
# define SKILL_HH_

# include <string>

typedef	enum MachineType
{
  TM,
  HM
}	MachineType;

class	Skill
{
  unsigned int	id_;
  std::string	name_;
  std::string	kind_;
  std::string	type_;
  unsigned int	PP_;
  unsigned int	power_;
  unsigned int	accuracy_;
  std::string	information_;
  std::string	location_;
  std::string	suggestion_;
  MachineType	from_;

public:
  Skill() {}
  ~Skill() {}

  void	setId(unsigned int id) { this->id_ = id; }
  void	setName(std::string name) { this->name_ = name; }
  void	setKind(std::string kind) { this->kind_ = kind; }
  void	setType(std::string type) { this->type_ = type; }
  void	setPP(unsigned int PP) { this->PP_ = PP; }
  void	setPower(unsigned int power) { this->power_ = power; }
  void	setAccuracy(unsigned int acc) { this->accuracy_ = acc; }
  void	setInformation(std::string info) { this->information_ = info; }
  void	setLocation(std::string loc) { this->location_ = loc; }
  void	setSuggestion(std::string sugg) { this->suggestion_ = sugg; }
  void	setMachineType(MachineType machinetype) { this->from_ = machinetype; }
};

class	Move
{
  Skill	*skill_;
  std::string	type_;
  std::string	name_;
  unsigned int	requiredLvl_;

public:
  Move(Skill *skill = NULL);
  ~Move() {}

  void	setType(std::string type) { this->type_ = type; }
  void	setName(std::string name) { this->name_ = name; }
  void	setRequiredLvl(unsigned int rqLvl) { this->requiredLvl_ = rqLvl; }
};


#endif
