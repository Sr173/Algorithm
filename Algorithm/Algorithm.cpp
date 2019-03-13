#include<iostream>

#include<stdlib.h>
#include "algorithm"
#include<time.h>

#define MAX_VALUE 10000
#define random() rand()%MAX_VALUE
#define N 100

int a[N];

using namespace std;

class RBTreeNode {
	enum Color {
		red,
		black
	};
public:
	RBTreeNode(int val) : val(val) {

	}
	RBTreeNode* right;
	RBTreeNode* left;
	RBTreeNode* parent;
	Color color;
	int val;
};

class RBTree {
public:
	RBTree() {

	}
	auto insert(RBTreeNode* node,bool isLeft,int val) {
		auto newNode =new RBTreeNode(val);
		if (root == nullptr) {
			root = newNode;
			return newNode;
		}
		if (isLeft) {
			node->left = newNode;
		}
		else {
			node->right = newNode;
		}
		return newNode;
	}
	void lRotate(RBTreeNode* node) {
		auto target = node->right;
		node->right = target->left;
		if (target->left != nullptr) {
			target->left->parent = node;
		}
		target->parent = node->parent;
		if (node->parent == nullptr) {
			root = target;
		}
		else if (node == node->parent->left) {
			node->parent->left = target;
		}
		else {
			node->parent->right = target;
		}
		target->left = node;
		node->parent = target;
	}
	void rRotate(RBTreeNode* node) {
		auto target = node->left;
		node->left = target->right;
		if (target->right != nullptr) {
			target->right->parent = node;
		}
		target->parent = node->parent;
		if (node->parent == nullptr) {
			root = target;
		}
		else if (node == node->parent->left) {
			node->parent->left = target;
		}
		else {
			node->parent->right = target;
		}
		target->right = node;
		node->parent = target;
	}

	void print() {
		printTree(root);
		cout << endl;
	}

private:
	void printTree(RBTreeNode* node) {
		if (node == nullptr)
			return;
		cout << node->val << " " ;
		printTree(node->left);
		printTree(node->right);
	}
	RBTreeNode* root = nullptr;
};

void main()
{
	RBTree* rbTree = new RBTree();
	auto node = rbTree->insert(0, true, 1);
	auto node_2 = rbTree->insert(node, true, 2);
	auto node_3 = rbTree->insert(node, false, 3);
	rbTree->insert(node_2, true, 4);
	rbTree->insert(node_2, false, 5);
	rbTree->insert(node_3, true, 6);
	rbTree->insert(node_3, false, 7);
	rbTree->print();
	rbTree->rRotate(node);
	//rbTree->lRotate(node);

	rbTree->print();

}