#include "map.hpp"
#include "map_exceptions.hpp"

#include <iostream>

int main() {
  std::string opcao;
  int key, val;
  std::string filename;

  Map map;

  while(std::cin >> opcao) {
    int valor_opcao;

    if(opcao == "i") valor_opcao = 0;
    else if(opcao == "f") valor_opcao = 1;
    else if(opcao == "r") valor_opcao = 2;
    else if(opcao == "p") valor_opcao = 3;
    else if(opcao == "r_f") valor_opcao = 4;

    switch (valor_opcao ) {
      case 0: {
        std::cin >> key >> val;
        try {
          map.insert(key, val);
        }
        catch (map_exc::key_in_use &e) {
          std::cout << e.what() << " key = " << e.get_key() << std::endl;
        }
      } break;

      case 1: {
        std::cin >> key;
        int val;

        int *val_ptr = &val;
      
        bool busca = map.find(key, *val_ptr);
        if (busca == true) std::cout << "found " << val << " in key " << key << std::endl;
        else std::cout << "key " << key << " not found" << std::endl;
      } break;

      case 2: {
        std::cin >> key;
        try {
          map.remove(key);
        }
        catch(map_exc::key_not_found& e) {
          std::cout << e.what() << " key = " << e.get_key() << std::endl;
        }
      } break;

      case 3: {
        map.print();
      } break;
      
      case 4: {
        std::cin >> filename;
        try {
          map.read_from_file(filename);
        }
        catch(map_exc::invalid_map_in_file& e) {
          std::cout << e.what() << e.get_file_name() << " Key " 
          << e.get_key() << " in line " << e.get_line() << std::endl;
        }
        catch(map_exc::file_not_found& e) {
          std::cout << e.what() << e.get_file_name() << std::endl;
        }
      } break;
    }
  }
}