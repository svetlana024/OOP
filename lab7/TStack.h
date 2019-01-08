#ifndef TSTACK_H
#define TSTACK_H
#include <memory>
#include <iostream>
#include "TAllocationBlock.h"

#include <future>
#include <thread>
#include <functional>

template <typename T> class TStack {
private:
	class TNode {
	public:
		TNode();
		TNode(const std::shared_ptr<T>&);
		auto GetNext() const;
		auto GetItem() const;
		std::shared_ptr<T> item;
		std::shared_ptr<TNode> next;

		void* operator new(size_t);
		void operator delete(void*);
		static TAllocationBlock allocator;
	};

	template <typename N, typename M>
	class TIterator {
	private:
		N nodePtr;
	public:
		TIterator(const N&);
		std::shared_ptr<M> operator* ();
		std::shared_ptr<M> operator-> ();
		void operator ++ ();
		bool operator == (const TIterator&);
		bool operator != (const TIterator&);
	};

	int size;
	std::shared_ptr<TNode> head;

public:
	TStack();
	bool PushFront(const std::shared_ptr<T>&);
	bool Pop(int k);
	bool Push(const std::shared_ptr<T>&, int k);
	bool PopFront();
	bool IsEmpty() const;
	int GetSize() const;
	auto& getHead();
	auto&& getLast();

	TIterator<std::shared_ptr<TNode>, T> begin() { return TIterator<std::shared_ptr<TNode>, T>(head->next); };
	TIterator<std::shared_ptr<TNode>, T> end() { return TIterator<std::shared_ptr<TNode>, T>(nullptr); };

	template <typename A> friend std::ostream& operator<< (std::ostream&, TStack<A>&);
};

#include "TStack.hpp"
#include "TIterator.hpp"
#endif