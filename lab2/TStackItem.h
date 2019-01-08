#ifndef TSTACKITEM_H
#define	TSTACKITEM_H

#include "Square.h"

class TStackItem {
public:
	TStackItem(const Square& square);
	TStackItem(const TStackItem& orig);
	friend std::ostream& operator<<(std::ostream& os, const TStackItem& obj);

	TStackItem* SetNext(TStackItem* next);
	TStackItem* GetNext();
	Square GetSquare() const;

	virtual ~TStackItem();
private:
	Square square;
	TStackItem *next;
};

#endif	/* TSTACKITEM_H */
#pragma once
