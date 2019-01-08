#include "NTree.h"


TNode::TNode() :link(nullptr), left(nullptr), right(nullptr) {
}

TNode::TNode(void * link) : link(link), left(nullptr), right(nullptr) {
}


TNTree::TNTree() : root(nullptr), size(0) {
}

TNTree::TNTree(const TNTree& orig) {
	root = orig.root;
	size = orig.size;
}

void TNTree::Insert(TNode*& node, void * link) {
	if (node == nullptr) {
		node = new TNode(link);
		size++;
	}
	else {
		if (link < node->link) {
			Insert(node->left, link);
		}
		else if (link > node->link)
			Insert(node->right, link);
		if (link == node->link)
		{
			printf("Such adress exists\n");
		}
	}
}

void TNTree::Pop() {
	TNode* temp = root;
	if (temp == nullptr) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	if (temp->left == nullptr) {
		size--;
		root = temp->right;
		return;
	}
	while (temp->left->left != nullptr) {
		temp = temp->left;
	}
	temp->left = nullptr;
	size--;
}


TNode* TNTree::Root() {
	return root;
}

size_t TNTree::Empty() const {
	return size;
}

void TNTree::DistructTree(TNode *node) {
	if (node->right != nullptr) {
		DistructTree(node->right);
	}
	if (node->left != nullptr) {
		DistructTree(node->left);
	}
	delete node;
}
TNode::~TNode() {
	left = nullptr;
	right = nullptr;
	link = nullptr;
}
TNTree::~TNTree() {
	if (root != nullptr)
		DistructTree(root);
	std::cout << "Tree: Deleted" << std::endl;
}

TNode* TNTree::Minimum() const {
	TNode* temp = root;
	while (temp->left != nullptr) {
		temp = temp->left;
	}
	return temp;
}
