//
// PokeDatabase.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 19:14:28 2013 Alexandre Baron
// Last update Tue Jan 22 00:07:15 2013 Alexandre Baron
//

#ifndef	POKEDATABASE_HH_
# define POKEDATABASE_HH_

# include <vector>

#include <QtXml>

# include "Pokemon.hh"
# include "Skill.hh"

# define	SKILLS_XML_FILE	"/home/baron_a/Projects/pokemon/resources/Mdata.xml"
# define	PKMN_XML_FILE	"/home/baron_a/Projects/pokemon/resources/pokedata.xml"

class	PokeDatabase
{
  //  Q_OBJECT

  std::vector<Pokemon *>	pokemons_;
  std::vector<Skill *>		skills_;
  QDomDocument	*document_;

public:
  PokeDatabase() { this->document_ = NULL; }
  ~PokeDatabase() {}

  int	openXMLFile(const QString &file, const QString &expectedRootTag, QDomElement &root);
  int	parsePokemonsFile();
  int	parseSkillsFile();
};

#endif
