#include <chrono>
#include <iostream>

int main() {
  // create array
  const int size = 1000;
  static bool x[size][size];

  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      x[i][j] = i + j;
      std::cout << &x[i][j] << ": i=" << i << ", j=" << j << std::endl;
    }
  }

  // print execution time to console
  auto t2 = std::chrono::high_resolution_clock::now(); // stop time measurement
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
  std::cout << "Execution time: " << duration << " nanoseconds" << std::endl;

  return 0;
}