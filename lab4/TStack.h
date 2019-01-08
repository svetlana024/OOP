#ifndef TSTACK_H
#define	TSTACK_H

#include "Figure.h"
#include "TStackItem.h"
#include <memory>

template <class T> class TStack {
public:
	TStack();

	void push(std::shared_ptr<T> &item);
	bool empty();
	size_t getSize();
	std::shared_ptr<T> pop();
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TStack<A>& stack);
	virtual ~TStack();
private:

	std::shared_ptr<TStackItem<T>> head;
	size_t size;
};

#endif	/* TSTACK_H */
#pragma once
