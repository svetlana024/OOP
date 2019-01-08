#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
	std::cout << "Rectangle created: " << side_a << side_b << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
	std::cout << "Enter the side first and second sides:" << std::endl;
	is >> side_a;
	is >> side_b;
}

Rectangle::Rectangle(const Rectangle& orig) {
	std::cout << "Rectangle copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
}

size_t Rectangle::Area() const {
	return side_a * side_b;
}

void Rectangle::Print() const {
	std::cout << "Rectangle:" << std::endl;
	std::cout << "a = " << side_a << std::endl;
	std::cout << "b = " << side_b << std::endl;
}

bool Rectangle::operator==(const Rectangle& other) {
	return (side_a == other.side_a && side_b == other.side_b);
}

Rectangle& Rectangle::operator=(const Rectangle& right) {

	if (this == &right) return *this;

	std::cout << "Rectangle copied" << std::endl;
	side_a = right.side_a;
	side_b = right.side_b;

	return *this;
}

/*bool Rectangle::operator<(const Rectangle& other) {
	return (double)(*this) < (double)(other);
}

bool Rectangle::operator>(const Rectangle& other) {
	return double(*this) > double(other);
}

bool Rectangle::operator<=(const Rectangle& other) {
	return double(*this) <= double(other);
}

bool Rectangle::operator>=(const Rectangle& other) {
	return double(*this) >= double(other);
}

Rectangle::operator double() const {
	double p = side_a * side_b;
	return p;
}*/

Rectangle::~Rectangle() {
	//std::cout << "Triangle deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {

	os << "a=" << obj.side_a << "b= " << obj.side_b << " Square=" << obj.Area();
	return os;
}
