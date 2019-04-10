#pragma once
#include <iostream>
template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
};
template <typename T>
class BinaryTreeNode {
	friend class BinaryTree;
public:
	BinaryTreeNode();
	BinaryTreeNode(const T& ele);
	BinaryTreeNode(const T&ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);
	T value() const;
	BinaryTreeNode<T>* leftchild() const;
	BinaryTreeNode<T>* rightchild() const;
	void setLeftchild(BinaryTreeNode<T> *l);
	void setRightchild(BinaryTreeNode<T> *r);
	void setValue(const T& val);
	bool isLeaf() const;
	BinaryTreeNode<T> & operator = (const BinaryTreeNode<T>& Node);
	BinaryTreeNode<T> * Parent(BinaryTreeNode<T>*current);
	BinaryTreeNode<T> * LeftSibing(BinaryTreeNode<T>*current);
	BinaryTreeNode<T> * RightSibing(BinaryTreeNode<T>*current);
	void createTree(const T& info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree);
	void preOrder(BinaryTreeNode<T>*root);
	void inOrder(BinaryTreeNode<T>*root);
	void postOrder(BinaryTreeNode<T>*root);
	void levelOrder(BinaryTreeNode<T>*root);
	void DeleteOrder(BinaryTreeNode<T>*root);
private:
	T info;

};
template<class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T> *root)
{
	using std::stack;
	stack<BinaryTreeNode<T>*> aStack;
	BinaryTreeNode<T> *pointer = root;
	aStack.push(NULL);
	while (pointer) {
		Visit(pointer->value);
		if (pointer->rightchild() != NULL) {
			aStack.push(pointer->rightchild());
		}
		if (pointer->leftchild() != NULL) {
			pointer = pointer->leftchild();
		}
		else {
			pointer = aStack.top();
			aStack.pop();
		}
	}
}

