#pragma once
#include <iostream>
using namespace std;

template <typename T>
class arrQueue {
public:
	arrQueue(int size = 10) {
		cout << "arrQueue(int size = 10)" << endl;
		mSize = size + 1; //�洢Ԫ�ص����������һ����λ
		qu = new T[mSize];
		front = 1;
		rear = 0;
	}
	~arrQueue() {
		cout << "~arrQueue()" << endl;
		delete[] qu;
 	}
	void clear()
	{
		front = rear + 1;
	}
	bool enQueue(const T item)
	{
		cout << "enQueue(const T item)" << endl;
		if (((rear + 2) % mSize) == front)
			return false;
		rear = (rear + 1) % mSize;
		qu[rear] = item;
		return true;
	}
	bool deQueue( T & item)
	{
		cout << "deQueue( T & item)" << endl;
		if (length() == 0)
			return false;
		item = qu[front];
		front = (front + 1) % mSize;
		return true;
	}
	bool frontValue(T &item)const {
		if (length() == 0)
			return false;
		item = qu[front];
	}
	int length() const {
		return ((front - rear + 1) % mSize);
	}
	bool isEmpty()
	{
		if (length() == 0)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (length() == mSize)
			return true;
		else
			return false;
	}
private:
	int mSize;
	int front;   //����Ԫ��ָ��  ���г���Ԫ��λ��
	int rear;    //��βԪ��ָ��  �������Ԫ��λ��
	T *qu;
};
#if 0
template <typename T>
class LinkQueue {
public:
	bool enQueue(const T item);
	bool deQueue(const T & item);
private:
	class Node {
		Node(int data = T());
	private:
		int data;
		Node *next;
	};
	int size;
	Node *front;
	Node *rear��
};
#endif

