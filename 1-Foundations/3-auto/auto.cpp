#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  auto i = 5;
  auto v_6 = {1, 2, 3};
  cout << "Variables declared and initialized without explicitly stating type!"
       << "\n";

  auto v = {7, 8, 9, 10};
  for (auto i : v)
    cout << i << " ";
  cout << "\n";
}