#include <iostream>
#include <memory>

void f(std::shared_ptr<int> ptr) {
  std::cout << "f --> shared pointer = " << ptr.get() << " " << ptr.use_count()
            << std::endl;
}

int main() {
  std::shared_ptr<int> mySharedPtr = std::make_shared<int>(0);
  std::cout << "shared pointer = " << mySharedPtr.get() << " "
            << mySharedPtr.use_count() << std::endl;

  f(mySharedPtr);

  return 0;
}