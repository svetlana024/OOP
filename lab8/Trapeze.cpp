#include "Trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze() : Trapeze(0, 0, 0) {
}

Trapeze::Trapeze(size_t i, size_t j, size_t k) : base_a(i), base_b(j), height(k)  {
	std::cout << "Trapeze created: " << base_a << base_b << height << std::endl;
}

Trapeze::Trapeze(std::istream &is) {
	std::cout << "Enter the sides and height:" << std::endl;
	is >> base_a;
	is >> base_b;
	is >> height;
}

Trapeze::Trapeze(const Trapeze& orig) {
	std::cout << "Trapeze copy created" << std::endl;
	base_a = orig.base_a;
	base_b = orig.base_b;
	height = orig.height;
}

size_t Trapeze::Area() const {
	return (base_a + base_b)/2 * height;
}

void Trapeze::Print() const {
	std::cout << "Trapeze:" << std::endl;
	std::cout << "a = " << base_a << std::endl;
	std::cout << "b = " << base_b << std::endl;
	std::cout << "height = " << height << std::endl;
}

Trapeze::~Trapeze() {
	//std::cout << "Triangle deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {

	os << "a=" << obj.base_a << "b = " << obj.base_b << "height= " << obj.height << " Square=" << obj.Area();
	return os;
}
