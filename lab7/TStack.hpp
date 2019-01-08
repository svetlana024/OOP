#include "TStack.h"
#ifdef TSTACK_H

template <typename T> TStack<T>::TNode::TNode() {
	item = std::shared_ptr<T>();
	next = nullptr;
}

template <typename T> TStack<T>::TNode::TNode(const std::shared_ptr<T>& obj) {
	item = obj;
	next = nullptr;
}

template <typename T> TAllocationBlock TStack<T>::TNode::allocator(sizeof(TStack<T>::TNode), 100);

template <typename T> void* TStack<T>::TNode::operator new(size_t size) {
	return allocator.Allocate();
}

template <typename T> void TStack<T>::TNode::operator delete(void* ptr) {
	allocator.Deallocate(ptr);
}

template <typename T> TStack<T>::TStack() {
	head = std::make_shared<TNode>();
	size = 0;
}

template <typename T> bool TStack<T>::IsEmpty() const {
	return this->size == 0;
}

template <typename T> auto& TStack<T>::getHead() {
	return this->head->next;
}

template <typename T> auto&& TStack<T>::getLast() {
	auto last = head->next;
	while (last->next != nullptr) {
		last = last->next;
	}
	return last;
}

template <typename T> int TStack<T>::GetSize() const {
	return this->size;
}

template <typename T> bool TStack<T>::Push(const std::shared_ptr<T>& obj, int pos) {
	if (pos == 1 || size == 0)
		return PushFront(obj);
	if (pos < 0 || pos > size + 1)
		return false;

	auto iter = head->next;
	int i = 0;

	while (i < pos - 2) {
		iter = iter->next;
		i++;
	}
	auto Nitem = std::make_shared<TNode>(obj);
	std::swap(Nitem->next, iter->next);
	std::swap(iter->next, Nitem);
	size++;

	return true;
}

template <typename T> bool TStack<T>::PushFront(const std::shared_ptr<T>& obj) {
	auto Nitem = std::make_shared<TNode>(obj);
	std::swap(Nitem->next, head->next);
	std::swap(head->next, Nitem);
	size++;
	return true;
}

template <typename T> bool TStack<T>::Pop(int pos) {
	if (pos < 1 || pos > size || IsEmpty())
		return false;
	if (pos == 1)
		return PopFront();

	auto iter = head->next;
	int i = 0;

	while (i < pos - 2) {
		iter = iter->next;
		i++;
	}

	iter->next = std::move(iter->next->next);
	size--;

	return true;
}


template <typename T> bool TStack<T>::PopFront() {
	if (IsEmpty())
		return false;

	head->next = std::move(head->next->next);
	size--;
	return true;
}


template <typename T> auto TStack<T>::TNode::GetNext() const {
	return this->next;
}

template <typename T> auto TStack<T>::TNode::GetItem() const {
	return this->item;
}

template <typename A> std::ostream& operator<< (std::ostream& os, const TStack<A>& stack) {
	if (stack.IsEmpty()) {
		os << "The stack is empty!" << std::endl;
		return os;
	}

	auto tmp = stack.head->GetNext();
	while (tmp != nullptr) {
		tmp->GetItem()->Print();
		tmp = tmp->GetNext();
	}

	return os;
}

#endif
