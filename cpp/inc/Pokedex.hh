//
// Pokedex.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 21:51:47 2013 Alexandre Baron
// Last update Sat Jan 19 22:24:34 2013 Alexandre Baron
//

#ifndef	POKEDEX_HH_
# define POKEDEX_HH_

# include "QtWindow.hh"

class	Pokedex
{
  QtWindow	view_;

public:
  Pokedex();

  void	initialize(size_t width, size_t height);
  void	run() { this->view_.show(); }
};

#endif
