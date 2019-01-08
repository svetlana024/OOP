#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(const Rectangle &obj);
	Rectangle(size_t i, size_t j);
	Rectangle(std::istream &is);
	void setParams(std::istream &is);
	size_t getSquare() override;
	void Print() override;
	bool operator==(const Rectangle&) const;
	Rectangle operator=(const Rectangle&);
	Rectangle operator++();
	friend std::ostream& operator<<(std::ostream&, const Rectangle&);

	~Rectangle() {};
	int type() { return 3; }
private:
	size_t side_a;
	size_t side_b;
};

#endif
#pragma once
