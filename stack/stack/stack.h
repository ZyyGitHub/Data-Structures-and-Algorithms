#pragma once
#include <iostream>
using namespace std;

template<typename T> 
class arrStack
{
public:
	arrStack(int size =10) :_mSize(size), _top(-1) {
		_arrst = new T[size];
	}
	~arrStack() {
		delete[] _arrst;
	}
	template <typename Ty>
	bool push(const Ty item) {
		cout << " arrStacktemplate <typename Ty>push(const Ty item)" << endl;
		if (isFull()) {
			cout << "the stack is full" << endl;
			return false;
		}
		else {
			_arrst[++_top] = item;
			return true;
		}
	}
	bool pop(T &item) {
		cout << "arrStack pop(T &item)" << endl;
		if (isEmpty()) {
			cout << "the stack is empty" << endl;
			return false;
		}
		else {
			item = _arrst[_top];
			_top--;
			return true;
		}
			
		
	}
	bool isFull()
	{
		return _top == _mSize - 1;
	}
	bool isEmpty()
	{
		return  _top == -1;
	}
private:
	int _mSize;
	int _top;
	int *_arrst;
};


template <typename T>
class linkStack {
public:
	linkStack():_size(0) {
		_top = new Node();
	}
	bool push(const T item);
	bool pop(T &item);
	bool isEmpty() {
		return _size == 0;
	}
private:
	class Node {
	public:
		Node(int data = T()):_data(data),_next(NULL){}
	private:
		T _data;
		Node *_next;
		friend class linkStack<T>;
	};
	Node *_top;
	int _size;
};
template <typename T>
bool linkStack<T>::push(const T item) {
	cout << "linkStack<T>::push(const T item)" << endl;
	Node *cur = new Node(item);   //创建直接链接好
	if (cur == NULL)
		return false;
	cur->_next = _top->_next;
	_top->_next = cur;
	_size++;
	return true;
}
template <typename T>
bool linkStack<T>::pop(T &item) {
	cout << "linkStack<T>::pop(const T &item)" << endl;
	if (isEmpty()) {
		cout << "linkStack is empty " << endl;
		return false;
	}
	else {
		Node *tmp = _top->_next;
		item = tmp->_data;
		_top->_next = _top->_next->_next;
		delete tmp;
		_size--;
		return true;
	}
	
}