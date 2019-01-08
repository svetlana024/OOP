#include "Trapeze.h"

Trapeze::Trapeze() : Trapeze(0, 0, 0) {}
Trapeze::Trapeze(const Trapeze &obj) {
	std::cout << "Trapeze copy created" << std::endl;
	base_a = obj.base_a;
	base_b = obj.base_b;
	height = obj.height;
}

Trapeze::Trapeze(size_t i, size_t j, size_t k) {
	this->base_a = i;
	this->base_b = j;
	this->height = k;
	std::cout << "Trapeze created: " << base_a << ", " << base_b << ", " << height << std::endl;
}

Trapeze::Trapeze(std::istream &is) {
	std::cout << "Enter first base, second base and height:" << std::endl;
	is >> this->base_a;
	is >> this->base_b;
	is >> this->height;
}

void Trapeze::setParams(std::istream &is) {
	is >> this->base_a;
	is >> this->base_b;
	is >> this->height;
}

void Trapeze::Print() {
	std::cout << "Trapeze: " << std::endl;
	std::cout << "first base = " << base_a << std::endl;
	std::cout << "second base = " << base_b << std::endl;
	std::cout << "height = " << height << std::endl;
}

bool Trapeze::operator==(const Trapeze& obj) const {
	return ((this->base_a == obj.base_a) && (this->base_b == obj.base_b)
		&& (this->height == obj.height));
}

Trapeze Trapeze::operator=(const Trapeze& obj) {
	if (this == &obj) return *this;

	base_a = obj.base_a;
	base_b = obj.base_b;
	height = obj.height;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {
	if (obj == Trapeze())
		return os;

	os << "Trapeze:  "
		<< obj.base_a << " " << obj.base_b
		<< " " << obj.height << std::endl;

	return os;
}

size_t Trapeze::getSquare() {
	return (this->base_a + this->base_b) / 2 * height;
}