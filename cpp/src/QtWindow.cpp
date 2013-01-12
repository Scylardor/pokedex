//
// QtWindow.cpp for pokemon in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 16:22:35 2013 Alexandre Baron
// Last update Sat Jan 12 18:12:10 2013 Alexandre Baron
//

#include <iostream>
#include <QString>

#include "QtWindow.hh"

QtWindow::QtWindow()
{
}

void	QtWindow::initialize(unsigned int x, unsigned int y, std::string title, std::string backgroundImg)
{
  this->window_.resize(x, y);
  if (title != "")
    this->setTitle(title);
  if (backgroundImg != "")
    this->setBackgroundImage(backgroundImg);
}

void	QtWindow::setBackgroundImage(std::string name)
{
  std::string backgroundImg("QWidget {background-image: url(");

  backgroundImg += name + ") }";
  this->window_.setStyleSheet(QString(backgroundImg.c_str()));
}

void	QtWindow::setTitle(std::string title)
{
  this->window_.setWindowTitle(QObject::tr(title.c_str()));

}

void	QtWindow::show()
{
  this->window_.show();
}
