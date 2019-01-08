#include "TAllocationBlock.h"
#include <iostream>


TAllocationBlock::TAllocationBlock(size_t size, size_t count)
{
	_used_blocks = (Byte *)malloc(size * count);

	for (size_t i = 0; i < count; ++i) {
		void *ptr = (void *)malloc(sizeof(void *));
		ptr = _used_blocks + i * size;
		_free_blocks.Insert(_free_blocks.root, ptr);
	}
}

void *TAllocationBlock::Allocate()
{
	if (_free_blocks.Empty() > 1) {
		void *res = _free_blocks.Minimum();
		_free_blocks.Pop();
		return res;
	}
	else {
		throw std::bad_alloc();
	}
}

void TAllocationBlock::Deallocate(void *ptr)
{
	_free_blocks.Insert(_free_blocks.root, ptr);
}

bool TAllocationBlock::Empty()
{
	return (_free_blocks.Empty() == 1);
}

TAllocationBlock::~TAllocationBlock()
{
	while (_free_blocks.Empty() != 1) {
		_free_blocks.Pop();
    }
	free(_used_blocks);
}