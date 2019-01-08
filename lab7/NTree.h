#pragma once
#ifndef TNTREE_H
#define TNTREE_H
#include <memory>
#include <iostream>
class TNode {
public:
	TNode();
	TNode(void * link);
	~TNode();
	void * link;
	TNode* left;
	TNode* right;
};
class TNTree {
public:
	TNTree();
	TNTree(const TNTree& orig);

	void Insert(TNode*& node, void * link);
	void Pop();
	TNode* Root();
	size_t Empty() const;
	TNode* Minimum() const;
	void DistructTree(TNode* node);
	int size;
	TNode* root;
	virtual ~TNTree();
private:



};

#endif /* TNTREE_H */
#pragma once
