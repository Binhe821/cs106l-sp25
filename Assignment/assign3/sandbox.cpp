/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <string>
void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  std::string name = "The Titanic";
  int id = 1;
  int score = 9;
  Movies Tit{"The Titanic", id, score};
  score = Tit.get_data();
  Tit.set_data();
}