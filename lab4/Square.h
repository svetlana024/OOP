#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include "Figure.h"

class Square : public Figure {
public:
	Square();
	Square(std::istream &is);
	Square(size_t side_a);
	Square(const Square& orig);

	double Area() const override;
	void   Print() const override;
	virtual ~Square();

private:
	size_t side_a;
};


#endif //SQUARE_H
#pragma once
#pragma once
