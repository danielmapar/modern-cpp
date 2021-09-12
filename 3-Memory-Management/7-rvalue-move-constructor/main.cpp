#include <iostream>
#include <stdlib.h>

class MyMovableClass {
private:
  int _size;
  int *_data;

public:
  MyMovableClass(size_t size) // constructor
  {
    _size = size;
    _data = new int[_size];
    std::cout << "CREATING instance of MyMovableClass at " << this
              << " allocated with size = " << _size * sizeof(int) << " bytes"
              << std::endl;
  }

  ~MyMovableClass() // 1 : destructor
  {
    std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
    delete[] _data;
  }

  MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
  {
    _size = source._size;
    _data = new int[_size];
    *_data = *source._data;
    std::cout << "COPYING content of instance " << &source << " to instance "
              << this << std::endl;
  }

  MyMovableClass &
  operator=(const MyMovableClass &source) // 3 : copy assignment operator
  {
    std::cout << "ASSIGNING content of instance " << &source << " to instance "
              << this << std::endl;
    if (this == &source)
      return *this;
    delete[] _data;
    _data = new int[source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;
  }

  MyMovableClass(MyMovableClass &&source) // 4 : move constructor
  {
    std::cout << "MOVING (c’tor) instance " << &source << " to instance "
              << this << std::endl;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
  }

  MyMovableClass &
  operator=(MyMovableClass &&source) // 5 : move assignment operator
  {
    std::cout << "MOVING (assign) instance " << &source << " to instance "
              << this << std::endl;
    if (this == &source)
      return *this;

    delete[] _data;

    _data = source._data;
    _size = source._size;

    source._data = nullptr;
    source._size = 0;

    return *this;
  }
};

MyMovableClass createObject(int size) {
  MyMovableClass obj(size); // regular constructor
  return obj;               // return MyMovableClass object by value
}

void useObject(MyMovableClass obj) {
  std::cout << "using object " << &obj << std::endl;
}

int main() {
  MyMovableClass obj1(100); // constructor

  useObject(obj1);

  useObject(MyMovableClass(100));
  return 0;
}

// MyMovableClass obj1(10);

// call to copy constructor, (alternate syntax)
// MyMovableClass obj3 = obj1;
// Here, we are instantiating obj3 in the same statement; hence the copy
// assignment operator would not be called.

// MyMovableClass obj4 = createObject(10);
// createObject(10) returns a temporary copy of the object as an rvalue, which
// is passed to the copy constructor. However, the copy constructor does not
// work with rvalues

// MyMovableClass obj4 = createObject(10); // Don't write this statement if
// you have already written it before
// obj4 = createObject(11); // call to copy assignment operator

/*
 * You can try executing the statement below as well */
// MyMovableClass obj4(createObject(10));

// MyMovableClass obj1(100); // constructor

// obj1 = MyMovableClass(200); // move assignment operator

// MyMovableClass obj2 = std::move(MyMovableClass(300)); // move constructor

// std::cout << &obj2 << std::endl;

// return 0;
//}