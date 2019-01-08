#ifndef RECTANGLE_H
#define	RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(size_t i, size_t j);
	Rectangle(const Rectangle& orig);
	void  Print() const override;
	size_t Area() const override;

	friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);

	bool operator==(const Rectangle& other);
	Rectangle& operator=(const Rectangle& right);

	virtual ~Rectangle();
private:
	size_t side_a;
	size_t side_b;
};

#endif	
#pragma once
