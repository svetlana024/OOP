#ifndef TRAPEZE_H
#define	TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(size_t i, size_t j, size_t k);
	Trapeze(const Trapeze& orig);
	void Print() const override;
	size_t Area() const override;

	friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
	virtual ~Trapeze();
private:
	size_t base_a;
	size_t base_b;
	size_t height;

};

#endif	
#pragma once
