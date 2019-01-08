#include "Square.h"
#include <iostream>
#include <cmath>

Square::Square() : Square(0) {
}

Square::Square(size_t i) : side_a(i){
	std::cout << "Square created: " << side_a << std::endl;
}

Square::Square(const Square& orig) {
	std::cout << "Square copy created" << std::endl;
	side_a = orig.side_a;
}

Square& Square::operator=(const Square& right) {

	if (this == &right)
		return *this;

	std::cout << "Square copied" << std::endl;
	side_a = right.side_a;
	return *this;
}

Square operator+(const Square& left, const Square& right) {

	return Square(left.side_a + right.side_a);
}

Square::~Square() {
	std::cout << "Square deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {

	os << "a=" << obj.side_a << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Square& obj) {
	std::cout << "Enter the side: " << std::endl;
	is >> obj.side_a;
	return is;
}
