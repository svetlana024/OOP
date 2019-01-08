#include "TStackItem.h"

TStackItem::TStackItem(const std::shared_ptr<Figure> &trap) {
	figure = trap;
	prev = nullptr;
}

TStackItem::TStackItem(const TStackItem& orig) {
	figure = orig.figure;
	prev = orig.prev;
}

void TStackItem::SetPrev(std::shared_ptr<TStackItem> prev) {
	if (this != nullptr)
		this->prev = prev;
}

std::shared_ptr<TStackItem> TStackItem::GetPrev() {
	return this->prev;
}

std::shared_ptr<Figure> TStackItem::GetFigure() const {
	return this->figure;
}

TStackItem::~TStackItem() {
}

std::ostream& operator<<(std::ostream& os, const TStackItem& item) {
	std::cout << *item.figure;
	return os;
}