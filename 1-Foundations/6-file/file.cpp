#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream my_file;
  my_file.open("example.txt");
  if (my_file) {
    std::cout << "The file stream has been created!"
              << "\n";
    std::string line;
    while (getline(my_file, line)) {
      std::cout << line << "\n";
    }
  }
}
