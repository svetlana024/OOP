#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "Figure.h"

class Square : public Figure {
public:
	Square();
	Square(const Square &obj);
	Square(size_t i);
	Square(std::istream &is);

	Square operator++();
	Square operator+(const Square& obj) const;
	friend std::ostream& operator<<(std::ostream& os, const Square& obj);
	friend std::istream& operator>>(std::istream& is, Square& obj);
	bool operator==(const Square& obj) const;
	Square operator=(const Square& obj);

	size_t getSquare() override;
	void Print() override;
	void setParams(std::istream &is);
	~Square() {};
	int type() { return 1; }
private:
	size_t side_a;
};

#endif#pragma once
