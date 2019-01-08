#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(0, 0) {}
Rectangle::Rectangle(const Rectangle &obj) {
  side_a = obj.side_a;
  side_b = obj.side_b;
}

Rectangle::Rectangle(size_t i, size_t j) {
  std::cout << "Rectangle created: " << side_a << side_b << std::endl;
  this->side_a = i;
  this->side_b = j;
}

size_t Rectangle::getSquare() {
  return this->side_a * this->side_b;
}

void Rectangle::Print() {
  std::cout << "Rectangle: " << std::endl
            << "a = " << this->side_a << std::endl
            << "b = " << this->side_b << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
  std::cout << "Enter the first and the second sides:" << std::endl;
  is >> this->side_a;
  is >> this->side_b;
}

bool Rectangle::operator==(const Rectangle& obj) const {
  return ((this->side_a == obj.side_a) && (this->side_b == obj.side_b));
}

Rectangle Rectangle::operator=(const Rectangle& obj) {
  side_a = obj.side_a;
  side_b = obj.side_b;

  return *this;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
  if (obj == Rectangle())
    return os;

  os << "Rectangle: " << obj.side_a
     << " " << obj.side_b << std::endl;

  return os;
}
