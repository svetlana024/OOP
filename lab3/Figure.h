#pragma once

#ifndef FIGURE_H
#define	FIGURE_H

#include <cstdlib>
#include <iostream>
#include <memory>

class Figure {
public:
	virtual double Area() const = 0;
	virtual void   Print() const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
		figure.Print();
		std::cout << std::endl;
		return os;
	};
	virtual ~Figure() {};
};

#endif	/* FIGURE_H */
