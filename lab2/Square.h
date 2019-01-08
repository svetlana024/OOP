#ifndef SQUARE_H
#define	SQUARE_H
#include <cstdlib>
#include <iostream>

class Square {
public:
	Square();
	Square(size_t i);
	Square(const Square& orig);

	friend Square operator+(const Square& left, const Square& right);
	friend std::ostream& operator<<(std::ostream& os, const Square& obj);
	friend std::istream& operator>>(std::istream& is, Square& obj);

	Square& operator=(const Square& right);

	virtual ~Square();
private:
	size_t side_a;
};

#endif	/* SQUARE_H */
#pragma once
