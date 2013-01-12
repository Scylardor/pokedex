//
// QtWindow.hh for pokemon in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 16:13:04 2013 Alexandre Baron
// Last update Sat Jan 12 18:10:22 2013 Alexandre Baron
//

#ifndef	QTWINDOW_HH_
# define QTWINDOW_HH_

// Standard Includes
# include <string>
// Libraries Includes
# include <QApplication>
# include <QMainWindow>

// Project Includes
# include "IWindow.hh"

class	QtWindow : public IWindow
{
  QMainWindow	window_;

public:
  QtWindow();
  ~QtWindow() {}

  virtual void	initialize(unsigned int x = 0, unsigned int y = 0, std::string title = "", std::string backgroundImg = "");
  virtual void	resize(unsigned int x, unsigned int y) {  }
  virtual void	setTitle(std::string);
  virtual void	setBackgroundImage(std::string name);
  virtual void	show();
};

#endif
