// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
  // Add public constructor to Square, initialize side
public:
  Square(int s) : side(s) {}

private:
  // Add friend class Rectangle
  friend class Rectangle;
  // Add private attribute side to Square
  int side;
};

// Define class Rectangle
class Rectangle {
  // Add public functions to Rectangle: area() and convert()
public:
  Rectangle(const Square &a);
  int Area() const;

private:
  // Add private attributes width, height
  int width{0};
  int height{0};
};

// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(const Square &a) : width(a.side), height(a.side) {}

// Define Area() to compute area of Rectangle
int Rectangle::Area() const { return width * height; }

// Update main() to pass the tests
int main() {
  Square square(4);
  Rectangle rectangle(square);
  assert(rectangle.Area() == 16);
}