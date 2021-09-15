/*
    Smart pointer exercises: Handling unique, shared and smart pointers

    // If all tasks are solved properly, the following text should appear in the
   terminal Learn Coding with Udacity! weak pointer is expired

    Note: Compile with C++17
    */

#include <iostream>
#include <memory>
#include <string>

void f1(std::unique_ptr<std::string> unique_ptr) {
  // TASK 3: Print the content of unique_ptr to the terminal
  // SOLUTION 3:
  std::cout << *unique_ptr;
}

void f2(std::shared_ptr<std::string> shared_ptr) {
  // TASK 4: Print the use count property of shared_ptr to the terminal to see
  // how many pointers refer to its resource
  //         If the use count is 2, print the content of shared_ptr to the
  //         terminal
  // SOLUTION 4:
  if (shared_ptr.use_count() == 2)
    std::cout << *shared_ptr;
}

void f3(std::weak_ptr<std::string> weak_ptr) {
  // TASK 5: Lock the weak pointer by assigning it to a shared pointer. Then,
  // print its content to the terminal.
  //        If the weak ptr can not be locked because the resource it refers to
  //        has expired, print the string "weak pointer is expired" to the
  //        terminal.
  // SOLUTION 5:
  if (auto shared_ptr = weak_ptr.lock()) // // Copy into a shared_ptr to use it
  {
    std::cout << *shared_ptr << "\n";
  } else {
    std::cout << "weak pointer is expired\n";
  }
}

int main() {
  // create resources to move around
  auto unique_str = std::make_unique<std::string>("Learn ");
  auto shared_str_1 = std::make_shared<std::string>("Coding ");
  auto shared_str_2 = std::make_shared<std::string>("with Udacity!");

  // Moving a unique pointer to transfer ownership
  // TASK 1 : pass the pointer 'unique_str' into the function f1
  // SOLUTION 1:
  f1(std::move(unique_str));

  // Pass a shared pointer by value
  // TASK 2 : pass the pointer 'shared_str_1' into the function f2
  // SOLUTION 2:
  f2(shared_str_1);

  // Pass a weak ptr by value and create a shared ptr from it to use it
  std::weak_ptr<std::string> weak_ptr_1;
  weak_ptr_1 = shared_str_2;
  f3(weak_ptr_1);

  // Pass a weak ptr by value after the shared ptr has expired
  std::weak_ptr<std::string> weak_ptr_2;
  {
    auto shared_str_3 = std::make_shared<std::string>("without Udacity");
    weak_ptr_2 = shared_str_3;
  }
  f3(weak_ptr_2);
}