#ifndef TSTACK_H
#define	TSTACK_H

#include "Square.h"
#include "TStackItem.h"

class TStack {
public:
	TStack();
	TStack(const TStack& orig);
	void push(Square &&square);
	bool empty();
	Square pop();
	friend std::ostream& operator<<(std::ostream& os, const TStack& stack);
	virtual ~TStack();
private:

	TStackItem *head;
};

#endif	/* TSTACK_H */
#pragma once
