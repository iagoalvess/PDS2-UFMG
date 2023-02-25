#ifndef MAP_EXECEPTIONS_H
#define MAP_EXECEPTIONS_H

#include "exception"

namespace map_exc {
  class key_in_use : public std::exception {
  private:
    int _key;
  public:
    key_in_use(int key) : _key(key) {}

    const char * what () const throw () {
      return("Key in use");
    }

    int get_key() { return(_key); }
  };

  class key_not_found : public std::exception {
  private:
    int _key;
  public:
    key_not_found(int key) : _key(key) {}

    const char * what () const throw () {
      return("Key not found");
    }

    int get_key() { return(_key); }
  };

  class file_not_found : public std::exception {
  private:
    const char* _file_name;
  public:
    file_not_found(const char* file_name) : _file_name(file_name) {}

    const char * what () const throw () {
      return("File not found ");
    }

    const char * get_file_name() { return(_file_name); }
  };

  class invalid_map_in_file : public std::exception {
  private:
    const char* _file_name;
    int _line;
    int _key;
  public:
    invalid_map_in_file(const char* file_name, int line, int key) :
      _file_name(file_name), _line(line), _key(key) {}

    const char * what () const throw () {
      return("Invalid Map in File ");
    }
    
    const char * get_file_name() {
      return(_file_name);
    }

    int get_line() { return(_line);}
    int get_key() { return(_key); }
  };
};

#endif