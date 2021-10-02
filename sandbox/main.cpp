#include <iostream>

void pointer(int *pointer) {
  std::cout << &pointer << std::endl;
  std::cout << pointer << std::endl;
}

int main() {
  int test = 10;
  int *ptr = &test;

  std::cout << &ptr << std::endl;
  std::cout << ptr << std::endl;
  pointer(ptr);

  std::cout << "Hello\n" << std::endl;
}