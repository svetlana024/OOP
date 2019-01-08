#ifndef TSTACK_H
#define TSTACK_H
#include "TStackItem.h"

class TStack {
public:
	TStack();
	TStack(const TStack& orig);

	void push(std::shared_ptr<Figure> &&trap);
	void push(std::shared_ptr<Figure> &trap);
	size_t getSize();
	bool empty();
	std::shared_ptr<Figure> pop();

	friend std::ostream& operator<<(std::ostream &os, const TStack& stack);

	~TStack();

private:
	std::shared_ptr<TStackItem> head;
	size_t size;
};


#endif //TSTACK_H

#pragma once
