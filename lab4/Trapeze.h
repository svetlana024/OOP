#ifndef TRAPEZE_H
#define TRAPEZE_H
#include "Figure.h"

class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(size_t base_a, size_t base_b, size_t height);
	Trapeze(const Trapeze& orig);

	double Area() const override;
	void   Print() const override;
	virtual ~Trapeze();

private:
	size_t base_a;
	size_t base_b;
	size_t height;
};


#endif //TRAPEZE_H
#pragma once
#pragma once
