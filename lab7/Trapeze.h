#ifndef TRAP_H
#define TRAP_H
#include "Figure.h"

class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(const Trapeze &obj);
	Trapeze(size_t i, size_t j, size_t k);
	Trapeze(std::istream &is);
	void Print() override;
	size_t getSquare() override;
	void setParams(std::istream &is);
	bool operator==(const Trapeze&) const;
	Trapeze operator=(const Trapeze&);
	friend std::ostream& operator<<(std::ostream&, const Trapeze&);
	~Trapeze() {};
	int type(){
		return 2;
	}
private:
	size_t base_a;
	size_t base_b;
	size_t height;

};

#endif
#pragma once
