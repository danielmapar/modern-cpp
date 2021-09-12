#include <iostream>

using namespace std;

// This class for managing a template-based heap ressource implements move
// semantics
template <class T> class MyClass {
  T *data = nullptr;

public:
  MyClass() {}

  // move constructor
  MyClass(MyClass &&other) {
    data = other.data;
    other.data = nullptr;
  }

  // move assignment operator
  MyClass &operator=(MyClass &&other) {
    if (this != &other) {
      if (data) {
        delete data;
      }
      data = other.data;
      other.data = nullptr;
    }

    return *this;
  }

  ~MyClass() {
    if (data) {
      delete data;
    }
  }

private:
  // copy constructor
  MyClass(const MyClass &);

  // copy assignment operator
  MyClass &operator=(const MyClass &);
};

int main() {
  /* EXERCISE 3-1: create an instance h1 of class MyClass with data of type
   * 'double' using the regular constructor */
  // SOLUTION 3-1
  MyClass<double> h1; // regular constructor

  // /* EXERCISE 3-2: create an instance h2 of class MyClass using the move
  // constructor (moving from h1) */
  // // SOLUTION 3-2
  MyClass<double> h3 = move(h1); // move constructor (rvalue as input)

  /* EXERCISE 3-3: disable copying for class MyClass */
  // SOLUTION 3-3
  // set visibility of MyClass(const MyClass &) and of MyClass &operator=(const
  // MyClass &) to private
}