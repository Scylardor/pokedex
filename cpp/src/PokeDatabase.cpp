//
// PokeDatabase.cpp<2> for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 21:33:35 2013 Alexandre Baron
// Last update Sat Feb  2 01:06:36 2013 Alexandre Baron
//

#include <iostream>

#include "PokeDatabase.hh"

PokeDatabase::PokeDatabase()
{
  this->initialize();
}

PokeDatabase::~PokeDatabase()
{
  std::map<QString, Pokemon*>::iterator it;

  if (this->document_)
    {
      delete this->document_;
    }
  this->pokemons_.clear();
  this->skills_.clear();
}

void	PokeDatabase::initializeTypes()
{
  QString	TypesDir(IMAGES_DIR);

  this->typesMatch_["None"]     = NONE;
  this->typesMatch_["Fire"]     = FIRE;
  this->typesMatch_["Water"]    = WATER;
  this->typesMatch_["Grass"]    = GRASS;
  this->typesMatch_["Bug"]      = BUG;
  this->typesMatch_["Electric"] = ELECTRIC;
  this->typesMatch_["Flying"]   = FLYING;
  this->typesMatch_["Poison"]   = POISON;
  this->typesMatch_["Dragon"]   = DRAGON;
  this->typesMatch_["Ice"]      = ICE;
  this->typesMatch_["Normal"]   = NORMAL;
  this->typesMatch_["Rock"]     = ROCK;
  this->typesMatch_["Ground"]   = GROUND;
  this->typesMatch_["Fighting"] = FIGHTING;
  this->typesMatch_["Psychic"]  = PSYCHIC;
  this->typesMatch_["Ghost"]    = GHOST;
  this->typesMatch_["Steel"]    = STEEL;
  this->typesMatch_["Dark"]     = DARK;

  std::map<QString, Type>::iterator it;

  TypesDir += "Types/";
  for (it = this->typesMatch_.begin(); it != this->typesMatch_.end(); ++it)
    {
      QImage	*typeImage = new QImage(TypesDir + it->first + ".png");

      this->typeImages_[it->second] = typeImage;
    }
}

void	PokeDatabase::initialize()
{
  this->document_ = NULL;
  this->initializePokemonSetters();
  this->initializeTypes();
}

// This function fills the pkmnSetters_ map with pointers to member functions of a Pokemon object
// (all the setters that take only a 'const QString &' as parameter, actually).
// This will permit to easily call all these setters with a similar function signature, allowing
// easy initialization of a new Pokemon object and, maybe in the future, add some more...
void	PokeDatabase::initializePokemonSetters()
{
  this->pkmnSetters_["name"]	   = &Pokemon::setName;
  this->pkmnSetters_["exp"]	   = &Pokemon::setExp;
  this->pkmnSetters_["ability"]	   = &Pokemon::setAbility;
  this->pkmnSetters_["species"]	   = &Pokemon::setSpecies;
  this->pkmnSetters_["height"]	   = &Pokemon::setHeight;
  this->pkmnSetters_["weight"]	   = &Pokemon::setWeight;
  this->pkmnSetters_["description"] = &Pokemon::setDescription;
}

// Note that when an error occurs, the document is re-set to NULL
int	PokeDatabase::openXMLFile(const QString &file, const QString &expectedRootTag, QDomElement &root)
{
  QFile	XMLFile(file);
  int	ret = 0;

  this->document_ = new QDomDocument(file);
  if (!XMLFile.open(QIODevice::ReadOnly))
    {
      ret = -1;
    }
  else if (!this->document_->setContent(&XMLFile))
    {
      ret = -2;
    }
  XMLFile.close();
  if (ret == 0)
    {
      root = this->document_->documentElement();
      if (root.tagName() != expectedRootTag)
	{
	  ret = -3;
	}
    }
  if (ret != 0)
    {
      delete this->document_;
      this->document_ = NULL;
    }
  return ret;
}

void	PokeDatabase::callPkmnSetterWithData(QDomElement &XMLPkmn, const QString &tagName, Pokemon *pkmn, PkmnSetter setter)
{
  (pkmn->*setter)(XMLPkmn.firstChildElement(tagName).text());
}

// Creates a new Pokemon out of the XML data.
// Uses the Pokedatabase object's map of Pokemon::function pointers to shorten the process
// for all setters that have the exact same signature (and whose data is easy to obtain in the file).
// Does the more complicated parsing after (types, setting of the appropriate Pokemon icon / image).
void	PokeDatabase::addPokemonFromData(QDomElement &XMLPkmn)
{
  Pokemon	*newPkmn;
  std::map<QString, PkmnSetter>::iterator it;
  QString	picturePath = IMAGES_DIR;

  newPkmn = new Pokemon();
  for (it = this->pkmnSetters_.begin(); it != this->pkmnSetters_.end(); ++it)
    {
      this->callPkmnSetterWithData(XMLPkmn, it->first, newPkmn, it->second);
    }

  QString	origID = XMLPkmn.attribute("id");
  QString	trueID("");
  int	id = origID.toInt();

  newPkmn->setImage(picturePath + "Pokemons/" + origID + ".png");
  if (id < 10)
    {
      trueID = "00";
    }
  else if (id >= 10 && id < 100)
    {
      trueID = "0";
    }
  trueID += XMLPkmn.attribute("id");
  newPkmn->setId(trueID);

  picturePath = IMAGES_DIR;
  picturePath += "Miniatures/";
  picturePath += trueID + ".gif";
  newPkmn->setMiniature(picturePath);

  QString	typeName;
  QDomNode	type = XMLPkmn.firstChildElement("type");
  int i = 0;

  while (!type.isNull() && i < 2)
    {
      QDomElement	typeElem = type.toElement();

      typeName = typeElem.text();
      if (this->typesMatch_.find(typeName) != this->typesMatch_.end())
	{
	  newPkmn->setTypeByIndex(i, this->typesMatch_[typeName]);
	}
      type = type.nextSibling();
      i++;
    }
  this->pokemons_[newPkmn->getId()] = newPkmn;

}

int	PokeDatabase::parsePokemonsFile()
{
  QDomElement	root;

  if (openXMLFile(PKMN_XML_FILE, "pokedex", root) < 0)
    {
      return -1;
    }

  QDomNode	PkmnList = root.firstChild();

  while (!PkmnList.isNull())
    {
      QDomElement	pkmn = PkmnList.toElement();

      if (!pkmn.isNull() && pkmn.tagName() == "pokemon")
	{
	  this->addPokemonFromData(pkmn);
	}
      PkmnList = PkmnList.nextSibling();
    }
  delete this->document_; // sooper important
  this->document_ = NULL;
  return 0;
}

int	PokeDatabase::parseSkillsFile()
{
  QDomElement	root;
  int	ret;

  if ((ret = openXMLFile(SKILLS_XML_FILE, "list", root)) < 0)
    {
      return ret;
    }

  QDomNode	n = root.firstChild();

  while (!n.isNull())
    {
      QDomElement	e = n.toElement();

      if (!e.isNull())
	{

	}
      n = n.nextSibling();
    }
  delete this->document_; // sooper important
  this->document_ = NULL;
  return 0;
}
