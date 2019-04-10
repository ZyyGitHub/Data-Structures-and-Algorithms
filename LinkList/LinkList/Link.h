#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class Link;
//类模板   除了构造和析构的名字可以省略参数列表，其他抵挡不能省略
template <typename T>
class Node
{
public:
	Node(T data = T()):_data(data),_pnext(NULL){}
private:
	T _data;
	Node<T> *_pnext;   //_pnext私有成员不能访问

#if 0    //含有太多的多余关系
	template <typename T>
	friend class Link;
#endif

	friend class Link<T>;
};

template <typename T>
class Link {
public:
	Link();
	~Link();
	bool isEmptyLink();
	void clearLink();
	int lengthLink();
	bool appendLink(const T value);
	bool insertHeadLink(const T value);
	bool insertLink(const int p, const T value);
	bool deleteLink(const int p);
	bool getValueLink(const int p, T &value);
	bool getPosLink(int &p, const T value);
	void showLink();
	void reserveLink();
	void deleteEndPosNode(int n);
private:
	Node<T> *_phead;     //类的组合关系，利用友元类
};

template <typename T>
Link<T>::Link() {
	cout << "Link()" << endl;
	cout << "data type : " << typeid(_phead).name() << endl;
	_phead = new Node<T>();
}

template <typename T>
Link<T>::~Link() {
	Node<T> *ptmp = _phead;
	while (ptmp != NULL) {
		_phead = _phead->_pnext;
		delete ptmp;
		ptmp = _phead;
	}
}

template <typename T>
bool Link<T>::isEmptyLink()
{
	return _phead->_pnext == NULL;
}
template <typename T>
void Link<T>::clearLink()
{
	Node<T> *ptmp = _phead;
	Node<T> *pcur = ptmp->_pnext;
	while (pcur != NULL) {
		ptmp = ptmp->_pnext;
		delete pcur;
		pcur = ptmp;
	}
}

template <typename T>
int Link<T>::lengthLink()
{
	int i = 0;
	Node<T> *pcur = _phead;
	while(pcur->_pnext != NULL)
	{
		pcur = pcur->_pnext;
		i++;
	}
	return i;
}

template <typename T>
bool Link<T>::appendLink(const T value)
{
	cout << "appendLink(const T value)" << endl;
	Node<T> *ptmp = new Node<T>(value);
	if (ptmp == NULL) {
		cout << "no space to new" << endl;
		return false;
	}
	Node<T> *pcur = _phead;
	while (pcur->_pnext != NULL) {
		pcur = pcur->_pnext;
	}
	pcur->_pnext = ptmp;
	return true;
}

template <typename T>
bool Link<T>::insertHeadLink(const T value)
{
	cout << "insertHeadLink(const T value)" << endl;
	Node<T> *ptmp = new Node<T>(value);
	if (ptmp == NULL) {
		cout << "no space to new" << endl;
		return false;
	}
	ptmp->_pnext = _phead->_pnext;
	_phead->_pnext = ptmp;
	return true;
}

template <typename T>
bool Link<T>::insertLink(const int p, const T value)
{
	cout << "insertLink(const int p, const T value)" << endl;
	int i;
	Node<T> *ptmp = new Node<T>(value);
	Node<T> *pcur = _phead;
	for ( i = 1; i < p; i++)
	{
		if (pcur->_pnext == NULL) {
			if (i != p) {
				cout << "no position of p" << endl;
				return false;
			}
			else {
				break;
			}
		}
		pcur = pcur->_pnext;
	}
	ptmp->_pnext = pcur->_pnext;
	pcur->_pnext = ptmp;
	return true;
}

template <typename T>
bool Link<T>::deleteLink(const int p) 
{
	cout << "deleteLink(const int p)" << endl;
	int i ;
	Node<T> *pcur = _phead;
	for ( i = 1; i < p; i++)
	{
		if (pcur->_pnext == NULL) {
			cout << "no hava postion of p" << endl;
			return false;
		}
		pcur = pcur->_pnext;
	}
	Node<T> *ptmp = pcur->_pnext;
	pcur->_pnext = pcur->_pnext->_pnext;
	delete ptmp;
	ptmp = NULL;
	return true;
}

template <typename T>
bool Link<T>::getValueLink(const int p, T &value)
{
	cout << "getValueLink(const int p, T &value)" << endl;
	Node<T> *pcur = _phead;
	int i;
	for ( i = 1; i <= p; i++)
	{
		if (pcur->_pnext == NULL) {
			cout << "no hava postion of p" << endl;
			return false;
		}
		pcur = pcur->_pnext;
	}
	value = pcur->_data;
	return false;
}

template <typename T>
bool Link<T>::getPosLink(int &p, const T value) 
{
	cout << "getPosLink(int &p, const T value) " << endl;
	int i = 1;
	Node<T> *pcur = _phead->_pnext;
	while (pcur->_data != value && pcur->_pnext != NULL) {
		pcur = pcur->_pnext;
		i++;
	}
	if (pcur->_data == value) {
		p = i;
		return true;
	}
	return false;
	cout << endl;
}

template <typename T>
void Link<T>::showLink()
{ 
	cout << "showLink()" << endl;
	Node<T> *pcur = _phead->_pnext;
	while (pcur != NULL) {
		cout <<" data : "<< pcur->_data;
		pcur = pcur->_pnext;
	}
	cout << endl;
}

template <typename T>
void Link<T>::reserveLink() {
	Node<T> *pNode = _phead;
	Node<T> *pPrev = NULL;
	Node<T> *pReverseList = NULL;
	while (pNode != NULL) {
		Node<T> *next = pNode->_pnext;
		if (next == NULL) {
			pReverseList = pNode;
		}
		pNode->_pnext = pPrev；
		pPrev = pNode;
		pNode = next;
	}
	_phead->_pnext = pReverseList;
}

template <typename T>
void Link<T>::deleteEndPosNode(int n) 
{
	Node<T> *tmp = new Node<T>();
	tmp->_pnext = _phead;
	Node<T> *firsthead = tmp;
	Node<T> *secondhead = tmp;
	for (int i = 0; i <= n; i++)
	{
		firsthead = firsthead->_pnext;
	}
	while (firsthead != NULL)
	{
		firsthead = firsthead->_pnext;
		secondhead = secondhead->_pnext;
	}
	Node<T> *del = secondhead->_pnext;
	secondhead->_pnext = secondhead->_pnext->_pnext;
	delete del;
}