#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <iostream>
#include <cstdlib>
#include "NTree.h"

typedef unsigned char Byte;

class TAllocationBlock
{
public:
	TAllocationBlock(size_t size, size_t count);
	void *Allocate();
	void Deallocate(void *ptr);
	bool Empty();

	virtual ~TAllocationBlock();

private:
	Byte *_used_blocks;
	TNTree _free_blocks;
};

#endif /* TALLOCATIONBLOCK_H */

