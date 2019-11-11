//
// Created by zj on 11/10/19.
//

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template<typename Type>
class Vector {
 private:
  int length;
  int size;
  Type *data;
 public:
  Vector(int new_size) {
    size = new_size;
    length = 0;
    data = new Type[size];
    // for (int i = 0; i < size; i++) {
    //    data[i] = 0;
    //}
  }
  ~Vector() {
    delete[]data;
  }
  bool insert(int loc, int value) {
    if (loc < 0 || loc > length) {
      return false;
    }
    if (length >= size) {
      expand();
    }
    for (int i = length; i > loc; i--) {
      data[i] = data[i - 1];
    }
    data[loc] = value;
    length++;
    return true;
  }
  void expand() {
    Type *old_data = data;
    size = size * 2;
    data = new Type[size];
    for (int i = 0; i < length; i++) {
      data[i] = old_data[i];
    }
    delete[]old_data;
  }
  bool search(int value) {
    for (int i = 0; i < length; i++) {
      if (data[i] == value) {
        return true;
      }
    }
    return false;
  }
  bool remove(int index) {
    if (index < 0 || index > length - 1) {
      return false;
    }
    for (int i = index + 1; i < length; i++) {
      data[i - 1] = data[i];
    }
    length--;
    return true;
  }
  void print() {
    for (int i = 0; i < length; i++) {
      if (i != 0) {
        cout << " ";
      }
      cout << data[i];
    }
    cout << endl;
  }
};
int main() {
  Vector<int> v(20);
  v.print();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int operation;
    cin >> operation;
    switch (operation) {
      case 1: {
        int loc, value;
        cin >> loc >> value;
        bool result = v.insert(loc, value);
        if (!result) {
          cout << "failed" << endl;
        } else {
          cout << "success" << endl;
        }
        v.print();
        break;
      }
      case 2: {
        int index;
        cin >> index;
        if (v.remove(index)) {
          cout << "success" << endl;
        } else {
          cout << "failed" << endl;
        }
        v.print();
        break;
      }
      case 3: {
        int value;
        cin >> value;
        if (v.search(value)) {
          cout << "success" << endl;
        } else {
          cout << "failed" << endl;
        }
        v.print();
        break;
      }
      case 4: {
        v.print();
        break;
      }
    }

  }
  return 0;
}
