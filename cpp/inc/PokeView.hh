//
// PokeView.hh for pokemon in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 16:10:39 2013 Alexandre Baron
// Last update Sat Jan 12 23:11:20 2013 Alexandre Baron
//

#ifndef	POKEVIEW_HH_
# define POKEVIEW_HH_

# include "IWindow.hh"

class	PokeView
{
  IWindow	*window_;

public:
  PokeView();
  ~PokeView();

  void	initialize(unsigned int x = 0, unsigned int y = 0, std::string title = "", std::string backgroundFileName = "") { this->window_->initialize(x, y, title, backgroundFileName); }
  void	show() { this->window_->show(); }
};

#endif
