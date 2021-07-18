#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 0, 0, 0, 1, 0}};

  for (auto line : board) {
    for (auto column : line) {
      cout << column << " ";
    }
    cout << "\n";
  }

  cout << "Hello!"
       << "\n";
}