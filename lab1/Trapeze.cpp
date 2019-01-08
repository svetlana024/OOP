#include "Trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze() :Trapeze(0, 0, 0) {
}

Trapeze::Trapeze(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k) {
	std::cout << "Trapeze created: " << side_a << ", " << side_b << ", " << side_c << ", " << side_c << std::endl;
}

Trapeze:: Trapeze(std::istream &is) {
	is >> side_a;
	is >> side_b;
	is >> side_c;
}

Trapeze::Trapeze(const Trapeze& orig) {
	std::cout << "Trapeze copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}
double Trapeze::Area() {
	double p = double ( pow(side_c, 2) - pow( double (abs (int (side_a - side_b) ) ) / 2.0 , 2 ));
	return sqrt(p) * double ( abs( int ( side_a + side_b) ) / 2.0 );
}

void Trapeze::Print() {
	std::cout << "a=" << side_a << ", b=" << side_b << ", c=" << side_c << ", d=" << side_c << std::endl;

}

Trapeze::~Trapeze() {
	std::cout << "Trapeze deleted" << std::endl;
}
