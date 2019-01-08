#include "Square.h"
#include <iostream>
#include <cmath>

Square::Square() : Square(0) {
}

Square::Square(size_t i) : side_a(i) {
	std::cout << "Square created: " << side_a << ", " << side_a << ", " << side_a << ", " << side_a << std::endl;
}

Square::Square(std::istream &is) {
	is >> side_a;
}

Square::Square(const Square& orig) {
	std::cout << "Square copy created" << std::endl;
	side_a = orig.side_a;
}
double Square::Area() {
	double p = double(side_a * side_a);
	return p;
}

void Square::Print() {
	std::cout << "a=" << side_a << ", b=" << side_a << ", c=" << side_a << ", d=" << side_a << std::endl;

}

Square::~Square() {
	std::cout << "Square deleted" << std::endl;
}
