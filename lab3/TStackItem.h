#pragma once
#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include "Trapeze.h"
#include "Square.h"
#include "Rectangle.h"


class TStackItem {
public:
	TStackItem(const std::shared_ptr<Figure> &trap);
	TStackItem(const TStackItem& orig);

	friend std::ostream& operator<<(std::ostream& os, const TStackItem& item);

	void SetPrev(std::shared_ptr<TStackItem> prev);
	std::shared_ptr<TStackItem> GetPrev();
	std::shared_ptr<Figure> GetFigure() const;

	virtual ~TStackItem();
private:
	std::shared_ptr<Figure> figure;
	std::shared_ptr<TStackItem> prev;
};


#endif //TSTACKITEM_H