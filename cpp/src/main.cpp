//
// main.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Fri Jan 11 21:55:34 2013 Alexandre Baron
// Last update Sat Jan 12 19:47:15 2013 Alexandre Baron
//

#include <iostream>
#include <QApplication>
#include <QMainWindow>

#include "Pokemon.hh"
#include "PokeView.hh"

int	main(int argc, char **argv)
{
  QApplication	app_(argc, argv);
  Pokemon ramoloss;
  PokeView view;

  view.initialize(800, 600, "Light Pokedex", "/home/baron_a/Projects/pokemon/resources/Pokedex_eteint.png");
  view.show();
  return app_.exec();
}
