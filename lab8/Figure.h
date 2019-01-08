#ifndef FIGURE_H
#define	FIGURE_H

#include <cstdlib>
#include <iostream>
#include <memory>

class Figure {
public:
	virtual size_t Area() const = 0;
	virtual void Print() const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
		figure.Print();
		std::cout << std::endl;
		return os;
	};

	bool operator==(const Figure& other) {
		return this->Area() == other.Area();
	};

	bool operator<(const Figure& other) {
		return this->Area() < other.Area();
	};
	bool operator>(const Figure& other) {
		return this->Area() > other.Area();
	};
	bool operator<=(const Figure& other) {
		return this->Area() <= other.Area();
	};
	bool operator>=(const Figure& other) {
		return this->Area() >= other.Area();
	};
	virtual ~Figure() {};
};

#endif	/* FIGURE_H */
#pragma once
#pragma once
#pragma once
#pragma once
