//
// main.cpp for pokedex in /home/baron_a/Projects/pokemon/cpp
//
// Made by Alexandre Baron
// Login   <baron_a@epitech.net>
//
// Started on  Sat Jan 19 21:47:04 2013 Alexandre Baron
// Last update Sat Jan 19 23:34:24 2013 Alexandre Baron
//

#include "Pokedex.hh"

int	main(int ac, char **av)
{
  QApplication	app(ac, av);
  Pokedex	pokedex;

  pokedex.initialize(745, 540);
  pokedex.run();

  return app.exec();
}
