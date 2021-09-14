#include <iostream>
#include <memory>
#include <string>

class MyClass {
private:
  std::string _text;
  std::int32_t _num = 0;

public:
  MyClass() {}
  MyClass(std::string text) { _text = text; }
  ~MyClass() {
    std::cout << this << " --> " << _text << " " << _num << " destroyed"
              << std::endl;
  }
  MyClass &operator=(const MyClass &source) // 3 : copy assignment operator
  {
    std::cout << "ASSIGNING content of instance " << &source << " to instance "
              << this << std::endl;
    if (this == &source)
      return *this;

    _text = source.getText();
    _num = source.getNumber() + 20;
    return *this;
  }
  MyClass &operator=(MyClass &&source) // 5 : move assignment operator
  {
    std::cout << "MOVING (assign) instance " << &source << " to instance "
              << this << std::endl;
    if (this == &source)
      return *this;

    _text = source.getText();
    _num = source.getNumber();

    source.setNumber(0);
    source.setText("None");

    return *this;
  }
  std::string getText() const { return _text; }
  std::int32_t getNumber() const { return _num; }
  void setText(std::string text) { _text = text; }
  void setNumber(std::int32_t num) { _num = num; }
};

int main() {
  // create unique pointer to proprietary class
  std::unique_ptr<MyClass> myClass1(new MyClass());
  std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));

  // call member function using ->
  myClass1->setText("String 1");
  myClass2->setNumber(60);

  // use the dereference operator *
  *myClass1 = *myClass2;

  // use the .get() function to retrieve a raw pointer to the object
  std::cout << "Objects have stack addresses " << myClass1.get() << " and "
            << myClass2.get() << std::endl;

  *myClass1 = std::move(*myClass2);

  // use the .get() function to retrieve a raw pointer to the object
  // std::cout << "Objects have stack addresses " << myClass1.get() << " and "
  // << myClass2.get() << std::endl;

  return 0;
}