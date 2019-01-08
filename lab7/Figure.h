#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <cmath>

class Figure {
public:
	virtual size_t getSquare() = 0;
	virtual void Print() = 0;
	virtual ~Figure() {};
	virtual int type() = 0;
};

#endif#pragma once
