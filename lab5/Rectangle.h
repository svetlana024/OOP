#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(size_t base_a, size_t base_b);
	Rectangle(const Rectangle& orig);

	double Area() const override;
	void   Print() const override;
	virtual ~Rectangle();

private:
	size_t side_a;
	size_t side_b;
};


#endif //RECTANGLE_H
#pragma once
#pragma once
#pragma once
