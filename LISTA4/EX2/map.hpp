#ifndef MAP_H
#define MAP_H

#include "map_exceptions.hpp"

#include <list>
#include <fstream>
#include <iostream>

using namespace map_exc;

class Map {
public:
  void read_from_file(std::string filename);

  bool find(int key, int &found_val);

  void insert(int key, int val);
  void remove(int key);
  void print();
  
private:
  std::list<std::pair<int, int>> lista_pares;
};

#endif