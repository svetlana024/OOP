#ifndef SQUARE_H
#define	SQUARE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Square : public Figure {
public:
	Square();
	Square(std::istream &is);
	Square(size_t i);
	Square(const Square& orig);
	void Print() const override;
	size_t Area() const override;

	friend std::ostream& operator<<(std::ostream& os, const Square& obj);
	virtual ~Square();
private:
	size_t side_a;
};

#endif	
