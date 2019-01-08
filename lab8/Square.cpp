#include "Square.h"
#include <iostream>
#include <cmath>

Square::Square() : Square(0) {
}

Square::Square(size_t i) : side_a(i){
	std::cout << "Square created: " << side_a << std::endl;
}

Square::Square(std::istream &is) {
	std::cout << "Enter the side:" << std::endl;
	is >> side_a;
}

Square::Square(const Square& orig) {
	std::cout << "Triangle copy created" << std::endl;
	side_a = orig.side_a;
}

size_t Square::Area() const {
	return side_a * side_a;
}

void Square::Print() const {
	std::cout << "Square:" << std::endl;
	std::cout << "a = " << side_a << std::endl;
}

/*bool Square::operator==(const Square& other) {
	return (side_a == other.side_a);
}*/

/*Square& Square::operator=(const Square& right) {

	if (this == &right) return *this;

	std::cout << "Square copied" << std::endl;
	side_a = right.side_a;

	return *this;
}*/

/*bool Square::operator<(const Square& other) {
	return (double)(*this) < (double)(other);
}

bool Square::operator>(const Square& other) {
	return double(*this) > double(other);
}

bool Square::operator<=(const Square& other) {
	return double(*this) <= double(other);
}

bool Square::operator>=(const Square& other) {
	return double(*this) >= double(other);
}

Square::operator double() const {
	double p = side_a * side_a;
	return p;
}*/

Square::~Square() {
	//std::cout << "Triangle deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {

	os << "a=" << obj.side_a << " Square=" << obj.Area();
	return os;
}
