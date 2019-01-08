#include "TStack.h"

TStack::TStack() : head(nullptr) {
}

TStack::TStack(const TStack& orig) {
	head = orig.head;
}

std::ostream& operator<<(std::ostream& os, const TStack& stack) {

	TStackItem *item = stack.head;

	while (item != nullptr)
	{
		os << *item;
		item = item->GetNext();
	}

	return os;
}

void TStack::push(Square &&square) {
	TStackItem *other = new TStackItem(square);
	other->SetNext(head);
	head = other;

}

bool TStack::empty() {
	return head == nullptr;
}

Square TStack::pop() {
	Square result;
	if (head != nullptr) {
		TStackItem *old_head = head;
		head = head->GetNext();
		result = old_head->GetSquare();
		old_head->SetNext(nullptr);
		delete old_head;
	}

	return result;
}

TStack::~TStack() {
	delete head;
}
