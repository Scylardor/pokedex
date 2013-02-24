//
// PokeDatabase.hh for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 19:14:28 2013 Alexandre Baron
// Last update Sat Feb  2 01:34:46 2013 Alexandre Baron
//

#ifndef	POKEDATABASE_HH_
# define POKEDATABASE_HH_

# include <vector>

#include <QtXml>

# include "Pokemon.hh"
# include "Skill.hh"

# define	SKILLS_XML_FILE	":/Mdata.xml"
# define	PKMN_XML_FILE	":/pokedata.xml"
# define	IMAGES_DIR	"/home/baron_a/Projects/pokemon/resources/Images/"

class	PokeDatabase
{
  //  Q_OBJECT

  std::map<QString, Pokemon *>	pokemons_;
  std::vector<Skill *>		skills_;
  QDomDocument	*document_;
  std::map<QString, PkmnSetter>	pkmnSetters_;
  std::map<Type, QImage *>	typeImages_;
  std::map<QString, Type>	typesMatch_;

public:
  PokeDatabase();
  ~PokeDatabase();

  void	initialize();
  void	initializePokemonSetters();
  void	initializeTypes();

  int	openXMLFile(const QString &file, const QString &expectedRootTag, QDomElement &root);
  int	parsePokemonsFile();
  int	parseSkillsFile();

  void	addPokemonFromData(QDomElement &XMLPkmn);
  void	callPkmnSetterWithData(QDomElement &XMLPkmn, const QString &tagName, Pokemon *pkmn, PkmnSetter setter);

  std::map<QString, Pokemon*>	getPokemonsList() const { return this->pokemons_; }
  Pokemon	*getPokemon(QString id) { return this->pokemons_[id]; }
  QImage	*getTypeImage(Type type) { return this->typeImages_[type]; }
};

#endif
