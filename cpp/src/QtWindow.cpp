//
// QtWindow.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 22:20:14 2013 Alexandre Baron
// Last update Sun Jan 20 01:11:52 2013 Alexandre Baron
//

#include <sstream>
#include <iostream>

#include "QtWindow.hh"

QtWindow::QtWindow()
  : QMainWindow()
{
  this->initialize();
}

void	QtWindow::toggleOnOff()
{
  std::cout << "coucou!" << std::endl;

  this->setBackgroundImage(this->OnOff_ ? POKEDEX_OFF_IMG : POKEDEX_ON_IMG);
  this->OnOff_ = !this->OnOff_;
}

void	QtWindow::makeButtonTransparent(QPushButton *button) {
  button->setFocusPolicy(Qt::NoFocus);
  button->setFlat(true);
}

void	QtWindow::initialize()
{
  std::stringstream	styleStream;

  this->OnOff_ = false;

  this->onOffButton_ = new QPushButton("ON", this);

  this->onOffButton_->setGeometry(84, 440, 129, 64);
  this->makeButtonTransparent(this->onOffButton_);
  styleStream << "background-image: url("<< ON_BUTTON_IMG << ");";
  this->onOffButton_->setStyleSheet(styleStream.str().c_str());
  connect(this->onOffButton_, SIGNAL(clicked()), this, SLOT(toggleOnOff()));
}

void	QtWindow::setBackgroundImage(const char *filename)
{
  QPalette	palette;
  QPixmap	pixmap(filename);
  QBrush	brush(pixmap);

  palette.setBrush(QPalette::Background, brush);
  setPalette(palette);

  // QWidget *centralWidget = new QWidget(this);
  // QGridLayout *layout = new QGridLayout();

  // centralWidget->setLayout(layout);

  // layout->addWidget(new QPushButton("Button  1"),0,0);
  // layout->addWidget(new QPushButton("Button  2"),0,1);
  // layout->addWidget(new QPushButton("Button  3"),0,2);

  // setCentralWidget(centralWidget);
}

void	QtWindow::blockResize(size_t width, size_t height)
{
  setFixedSize(width, height);
}
