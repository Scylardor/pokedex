//
// makeButtonTransparent.cpp for qthelper in /home/baron_a/Projects/pokemon/cpp/build
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Mar  2 00:27:03 2013 Alexandre Baron
// Last update Sat Mar  2 00:27:34 2013 Alexandre Baron
//

#include "makeButtonTransparent.hh"

// Helper function out of any class
void	makeButtonTransparent(QPushButton *button) {
  button->setFocusPolicy(Qt::NoFocus);
  button->setFlat(true);
}
