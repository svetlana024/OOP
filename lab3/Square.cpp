#include "Square.h"
#include <iostream>

Square::Square() : Square(0) {
}

Square::Square(std::istream &is) {
	std::cout << "Enter the side:" << std::endl;
	is >> side_a;
}

Square::Square(const Square &orig) {
	std::cout << "Square copy created" << std::endl;
	this->side_a = orig.side_a;
}

Square::Square(size_t side_a) : side_a(side_a){
	std::cout << "Square created: " << side_a << std::endl;
}

void Square::Print() const {
	std::cout << "Square:" << std::endl;
	std::cout << "a = " << side_a << std::endl;
}

double Square::Area() const {
	return side_a * side_a;
}

Square::~Square() {
	std::cout << "Square delete" << std::endl;
}