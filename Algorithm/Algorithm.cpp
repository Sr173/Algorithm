#include <iostream>
#include "deque"
#include <stdlib.h>
#include  "algorithm"
#include <time.h>

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
		newNode->parent = node;
		return newNode;
	}
	void lRotate(RBTreeNode* node) {
		auto target = node->right;
		node->right = target->left;//将target的左子树给右子树
		if (target->left != nullptr) {
			target->left->parent = node;
		}
		target->parent = node->parent;//将node的父节点给target
		if (node->parent == nullptr) {
			root = target;
		}
		else if (node == node->parent->left) {//如果node是左子树
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
		if (target->parent == nullptr) {
			root = target;
		}
		else if (target == target->parent->left) {
			target->parent->left = target;
		}
		else {
			target->parent->right = target;
		}
		target->right = node;
		node->parent = target;
	}
	void print() {
		printTree(root);
		cout << endl;
	}
	void levelPrint() {
		std::deque<RBTreeNode*> nodeQue;
		nodeQue.push_back(root);
		cout << root->val << endl;
		while (nodeQue.size()) {
			int size = nodeQue.size();
			for (auto i = 0; i < size;i++) {
				auto front = nodeQue.front();
				front->left ? cout << front->left->val : cout << "*";
				cout << " ";
				front->right ? cout << front->right->val : cout << "*";
				cout << " ";
				if (front->left) nodeQue.push_back(front->left);
				if (front->right) nodeQue.push_back(front->right);
				nodeQue.pop_front();
			}
			cout << endl;
		}
	}
	auto getRoot() { return root; }
private:
	void printTree(RBTreeNode* node) {
		if (node == nullptr)
			return;
		cout << node->val << "(" << (node->parent ? node->parent->val : 0) << ")" << " ";
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
	rbTree->levelPrint();
	rbTree->rRotate(rbTree->getRoot());
	//rbTree->lRotate(node);
	rbTree->levelPrint();
	rbTree->lRotate(rbTree->getRoot());
	rbTree->levelPrint();

}