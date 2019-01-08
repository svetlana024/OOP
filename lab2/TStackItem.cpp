#include "TStackItem.h"
#include <iostream>

TStackItem::TStackItem(const Square& square) {
	this->square = square;
	this->next = nullptr;
	std::cout << "Stack item: created" << std::endl;
}

TStackItem::TStackItem(const TStackItem& orig) {
	this->square = orig.square;
	this->next = orig.next;
	std::cout << "Stack item: copied" << std::endl;
}

TStackItem* TStackItem::SetNext(TStackItem* next) {
	TStackItem* old = this->next;
	this->next = next;
	return old;
}

Square TStackItem::GetSquare() const {
	return this->square;
}

TStackItem* TStackItem::GetNext() {
	return this->next;
}

TStackItem::~TStackItem() {
	std::cout << "Stack item: deleted" << std::endl;
	delete next;

}

std::ostream& operator<<(std::ostream& os, const TStackItem& obj) {
	os << "[" << obj.square << "]" << std::endl;
	return os;
}
