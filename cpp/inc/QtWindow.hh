//
// QtWindow.hh for pokemon in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 16:13:04 2013 Alexandre Baron
// Last update Sun Jan 13 00:58:05 2013 Alexandre Baron
//

#ifndef	QTWINDOW_HH_
# define QTWINDOW_HH_

// Standard Includes
# include <string>
// Libraries Includes
//# include <QtGui>
# include <QMainWindow>
# include <QPushButton>

// Project Includes
# include "IWindow.hh"

class	onOffButton : public QPushButton
{
  Q_OBJECT

  bool on_;

public:
  onOffButton(QWidget *parent = 0);

};


class	QtWindow : public QWidget, public IWindow
{
  Q_OBJECT

  QMainWindow	window_;
  QPushButton	onOffButton_;
  bool		activated_;

public:
  QtWindow();
  ~QtWindow() {}

  virtual void	initialize(unsigned int x = 0, unsigned int y = 0, std::string title = "", std::string backgroundImg = "");
  virtual void	resize(unsigned int x, unsigned int y) {  }
  virtual void	setTitle(std::string);
  virtual void	setBackgroundImage(std::string name);
  virtual void	show();

  void	createRoundButton(QPushButton &, int, int, int, int);

public slots:
  void	slotToggleOnOff();

};

#endif
