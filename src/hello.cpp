#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> texts{"Hello", "World", "Hello"};
  for (std::string const &text : texts) {
    std::cout << "Hellow World!\n" << text << "!\n";
  }
}