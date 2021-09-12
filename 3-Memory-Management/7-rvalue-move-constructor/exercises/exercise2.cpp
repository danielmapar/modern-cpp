/*
Memory Management exercises part 2: Use move semantics implicitly as part of the
STL
*/

#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

const int array_size = 1e6;
vector<int> RandomNumbers3() {
  vector<int> random_numbers;
  random_numbers.resize(array_size);
  for (int i = 0; i < array_size; i++) {
    random_numbers[i] = rand();
  }
  return random_numbers; // return-by-value of the STL vector
}

int main() {
  /* EXERCISE 2-1: Return large objects using move semantics in the STL */
  // store the data in a suitable variable named 'random_numbers_3'

  // SOLUTION to exercise 2-1
  vector<int> random_numbers_3 =
      RandomNumbers3(); // will not copy the vector but use move semantics
                        // "under the hood" Note that all of the STL classes
                        // (including vector) have been extended to support move
                        // semantics
}