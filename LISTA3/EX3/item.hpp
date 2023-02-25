#ifndef ITEM_H
#define ITEM_H

#include "iostream"

class Item {
private:
  int _key;
  int _val;

public:
  Item();
  Item(int key, int val);

  friend bool operator >(const Item &i1, const Item &i2) {
    if (i1._val > i2._val) {
      return(true);
    } else return(false);
  }

  friend std::ostream & operator << (std::ostream &out, const Item &i) {
    return out << "(" << i._key << "," << i._val << ")";
  }
};

Item::Item() {}

Item::Item(int key, int val) : _key(key), _val(val) {}

#endif