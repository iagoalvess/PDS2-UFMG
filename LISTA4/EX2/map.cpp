#include "map.hpp"

void Map::read_from_file(std::string filename) {
  int key, val;
  int line = 1;

  bool conflito = false;

  std::pair<int, int> par;
  std::list<std::pair<int, int>> lista_arquivo;

  std::ifstream arquivo(filename.c_str());

  if (arquivo.is_open()) {
    while (!arquivo.eof()) {
      arquivo >> key;
      arquivo >> val;

      for (auto it : lista_pares) {
        if (key == it.first) {
          conflito = true;

          map_exc::invalid_map_in_file erro_map(filename.c_str(), line, key);
          throw(erro_map);
        }
      }

      for (auto it : lista_arquivo) {
        if (key == it.first) {
          conflito = true;

          map_exc::invalid_map_in_file erro_map(filename.c_str(), line, key);
          throw(erro_map);
        }
      }
      line++;

      par = std::make_pair(key, val);
      lista_arquivo.push_back(par);
    }
  } 
  else {
    map_exc::file_not_found erro_arquivo(filename.c_str());
    throw(erro_arquivo);
  }

  if (conflito == false) {
    for (auto it : lista_arquivo) {
      lista_pares.push_back(it);
    }
  }

  arquivo.close();
}

bool Map::find(int key, int &found_val) {
  std::list<std::pair<int, int>>::iterator it;

  for (it = lista_pares.begin(); it!= lista_pares.end(); it++) {
    if (it->first == key) {
      found_val = it->second;
      return(true);
    }
  }

  return(false);
}

void Map::insert(int key, int val) {
  std::pair<int, int> par;
  par = std::make_pair(key, val);

  std::list<std::pair<int, int>>::iterator it;
  for (it = lista_pares.begin(); it!= lista_pares.end(); it++) {
    if (it->first == key) {
      map_exc::key_in_use erro_key(it->first);
      throw(erro_key);
    }
  } 

  lista_pares.push_back(par);
}

void Map::remove(int key) {
  bool existe = false;

  std::list<std::pair<int, int>>::iterator it;
  for (it = lista_pares.begin(); it!= lista_pares.end(); it++) {
    if (it->first == key) {
      existe = true;

      lista_pares.erase(it);
      return;
    }
  }

  if (existe == false) {
    map_exc::key_not_found erro_remove(key);
    throw(erro_remove);
  }
}

void Map::print() {
  std::cout << "========================" << std::endl;

  std::list<std::pair<int, int>>::iterator it;
  for (it = lista_pares.begin(); it!= lista_pares.end(); it++) {
    std::cout << "<" << it->first << "," << it->second << ">" << std::endl;
  }

  std::cout << "========================" << std::endl;
}