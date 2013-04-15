//
// Pokedex.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 21:57:25 2013 Alexandre Baron
// Last update Mon Apr 15 14:05:14 2013 Alexandre Baron
//

#include "Pokedex.hh"

Pokedex::Pokedex()
{
}

void	Pokedex::initialize(size_t width, size_t height)
{
  this->view_.resize(width, height);
  this->view_.setBackgroundImage(POKEDEX_OFF_IMG);
  this->view_.blockResize(width, height);
  this->view_.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
					  this->view_.size(), qApp->desktop()->availableGeometry()
					  )
		      );

}
