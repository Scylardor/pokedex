//
// QtWindow.cpp for pokemon in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 12 16:22:35 2013 Alexandre Baron
// Last update Sun Jan 13 14:51:28 2013 Alexandre Baron
//

#include <iostream>
#include <QApplication>
#include <QString>

#include "QtWindow.hh"

QtWindow::QtWindow()
  : window_(), onOffButton_(&window_)
{
}

void	QtWindow::initialize(unsigned int x, unsigned int y, std::string title, std::string backgroundImg)
{
  this->activated_ = false; // le Pokedex commence eteint
  this->window_.resize(x, y);
  if (title != "")
    this->setTitle(title);
  this->onOffButton_.setStyleSheet("QWidget {background-color: rgba(255, 0, 0, 0%); background-image: url(/home/baron_a/Projects/pokemon/resources/boutonON.png); }");
  this->onOffButton_.resize(40, 39); // resize to the correct size
  this->onOffButton_.move(57, 495); // move to the correct place
  this->onOffButton_.setFlat(true); // to have the little "push" animation
  this->onOffButton_.setFocusPolicy(Qt::NoFocus); // to remove border

  this->createRoundButton(this->onOffButton_, 0, 0, 34, 34);

  if (backgroundImg != "")
    this->setBackgroundImage(backgroundImg);

  QObject::connect(&(this->onOffButton_), SIGNAL(clicked()), this, SLOT(slotToggleOnOff()));
}

void	QtWindow::createRoundButton(QPushButton &button, int x, int y, int width, int height)
{
  QRect *rect = new QRect(x, y, width, height);
  QRegion* region = new QRegion(*rect, QRegion::Ellipse);

  button.setMask(*region);
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


void	QtWindow::slotToggleOnOff()
{
  this->activated_ = !this->activated_;
  if (this->activated_)
    {
      this->setBackgroundImage("/home/baron_a/Projects/pokemon/resources/Pokedex_allume.png");
    }
  else
    {
      this->setBackgroundImage("/home/baron_a/Projects/pokemon/resources/Pokedex_eteint.png");
    }
}
