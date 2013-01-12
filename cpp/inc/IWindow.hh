//
// IWindow.hh for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 16:09:27 2013 Alexandre Baron
// Last update Sat Jan 12 18:04:16 2013 Alexandre Baron
//

#ifndef	IWINDOW_HH_
# define IWINDOW_HH_

# include <string>

class	IWindow
{

public:
  virtual ~IWindow() {}

  virtual void	initialize(unsigned int x = 0, unsigned int y = 0, std::string title = "", std::string backgroundImg = "") = 0;
  virtual void	resize(unsigned int, unsigned int) = 0;
  virtual void	setTitle(std::string) = 0;
  virtual void	setBackgroundImage(std::string name) = 0;
  virtual void	show() = 0;
};

#endif
