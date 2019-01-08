#include "TStack.h"


TStack::TStack() : head(nullptr), size(0) {
}

TStack::TStack(const TStack& orig) {
	std::shared_ptr<TStackItem> item = orig.head;
	size = orig.size;
	while (item != nullptr) {
		item = item->GetPrev();
		this->push(item->GetFigure());
	}

}

size_t TStack::getSize() {
	return this->size;
}

void TStack::push(std::shared_ptr<Figure> &&trap) {
	std::shared_ptr<TStackItem> newItem(new TStackItem(trap));
	newItem->SetPrev(head);
	head = newItem;
	size++;
}

void TStack::push(std::shared_ptr<Figure> &trap) {
	std::shared_ptr<TStackItem> newItem(new TStackItem(trap));
	newItem->SetPrev(head);
	head = newItem;
	size++;
}

bool TStack::empty() {
	return head==nullptr;
}

std::shared_ptr<Figure> TStack::pop() {
	std::shared_ptr<Figure> result;
	if (head != nullptr) {
		std::shared_ptr<TStackItem> old_head = head;
		head = head ->GetPrev();
		result = old_head->GetFigure();
		old_head->SetPrev(nullptr);
		size--;
	}
	else {
		std::cout << "Stack does not have elements" << std::endl;
	}

	return result;
}

TStack::~TStack() {
	while (!this->empty()) {
		this->pop();
	}
}

std::ostream& operator<<(std::ostream &os, const TStack& stack) {
	std::shared_ptr<TStackItem>item = stack.head;
	os << "Stack: " << std::endl << std::endl;

	while (item != nullptr) {
		os << *item;
		item = item->GetPrev();

	}
	return os;
}