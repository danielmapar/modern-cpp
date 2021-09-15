#include <iostream>
#include <memory>

class MyClass {
private:
  int _member;

public:
  MyClass(int val) : _member{val} {}
  ~MyClass() { std::cout << "Called destructor" << std::endl; }
  void printVal() {
    std::cout << ", managed object " << this << " with val = " << _member
              << std::endl;
  }
};

void f(std::unique_ptr<MyClass> &ptr) {
  std::cout << "unique_ptr " << &ptr;
  ptr->printVal();
}

void f2(std::unique_ptr<MyClass> ptr) {
  std::cout << "unique_ptr " << &ptr;
  ptr->printVal();
}

int main() {
  std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(23);
  std::cout << "unique_ptr " << &uniquePtr;
  uniquePtr->printVal();

  // f(std::move(uniquePtr));
  f(uniquePtr);

  std::cout << "Out of the function!" << std::endl;

  if (uniquePtr)
    uniquePtr->printVal();

  return 0;
}