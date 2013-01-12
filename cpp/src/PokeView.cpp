//
// PokeView.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 16:14:55 2013 Alexandre Baron
// Last update Sat Jan 12 18:10:40 2013 Alexandre Baron
//

#include "QtWindow.hh"
#include "PokeView.hh"

PokeView::PokeView()
{
  this->window_ = new QtWindow();
  if (!this->window_)
    {
      // Throw exception
    }
  else
    {

    }
}

PokeView::~PokeView()
{
  if (this->window_)
    delete this->window_;
}
