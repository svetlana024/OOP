#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(std::istream &is) {
	std::cout << "Enter the first and the second sides:" << std::endl;
	is >> side_a >> side_b;
}

Rectangle::Rectangle(const Rectangle &orig) {
	std::cout << "Rectangle copy created" << std::endl;
	this->side_a = orig.side_a;
	this->side_b = orig.side_b;
}

Rectangle::Rectangle(size_t side_a, size_t side_b) : side_a(side_a), side_b(side_b) {
	std::cout << "Rectangle created: " << side_a << side_b << std::endl;
}

void Rectangle::Print() const {
	std::cout << "Rectangle:" << std::endl;
	std::cout << "a = " << side_a << ", b= " << side_b << std::endl;
}

double Rectangle::Area() const {
	return side_a * side_b;
}

Rectangle::~Rectangle() {
	std::cout << "Rectangle delete" << std::endl;
}