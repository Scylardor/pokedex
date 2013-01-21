//
// PokeDatabase.cpp<2> for pokedex in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Mon Jan 21 21:33:35 2013 Alexandre Baron
// Last update Tue Jan 22 00:22:51 2013 Alexandre Baron
//

#include <iostream>

#include <QMessageBox>

#include "PokeDatabase.hh"

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
      QMessageBox::critical(NULL, "Pokedex", "Error ! Unable to load XML file, or invalid XML file. Exiting.", QMessageBox::Ok);
      delete this->document_;
      this->document_ = NULL;
    }
  return ret;
}

int	PokeDatabase::parsePokemonsFile()
{
  QDomElement	root;

  if (openXMLFile(PKMN_XML_FILE, "pokedex", root) < 0)
    {
      return -1;
    }

  QDomNode	n = root.firstChild();

  while (!n.isNull())
    {
      QDomElement	e = n.toElement();

      if (!e.isNull())
	{
	  std::cout << e.tagName().toStdString() << std::endl;
	}
      n = n.nextSibling();
    }

  delete this->document_;
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
	  std::cout << e.tagName().toStdString() << std::endl;
	}
      n = n.nextSibling();
    }
  return 0;
}
