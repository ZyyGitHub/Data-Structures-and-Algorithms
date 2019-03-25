#pragma once

#include <iostream>
using namespace std;

template <typename T>
class arrList
{
public:
	arrList(const int size);
	~arrList();
	void clearArr();
	int lengthArr();
	bool fullArr();
	bool apendArr(const T value);
	bool insertArr(const int p, const T value);
	bool deleteArr(const int p);
	bool setValueArr(const int p, const T value);
	bool getValueArr(const int p, T& value);
	bool getPosArr(int &p, const T value);
	void showArr();
private:
	int _curLen;        //��ʵ����ǰ����
	int _maxLen;		//��ʵ����󳤶�   ��һ��Ԫ��0��ʱ�򳤶�Ϊ1
	T *_aList;          //�洢��ʵ��
	int _position;      //��ǰ����λ��  ����λ�ô�0��ʼ
};

template <typename T>
arrList<T>::arrList(const int size):_curLen(0),_maxLen(size),_position(0)
{
	cout << "arrList(const int size)" << endl;
	_aList = new T[size];
	cout << "type(_aList) :" << typeid(_aList).name() << endl;
	cout << "_maxLen ��" << _maxLen << endl;
	cout << sizeof(_aList)/sizeof(int) << endl;
}

template <typename T>
arrList<T>::~arrList()
{
	cout << "~arrList()" << endl;
	delete[] _aList;
	_aList = NULL;
}

template <typename T>
void arrList<T>::clearArr()    //��˳����е��������㣬��Ϊ�ձ�
{
	cout << "clearArr()" << endl;
	delete[] _aList;
	_aList = new T[_maxLen];
	_curLen = _position = 0;
}

template <typename T>
int arrList<T>::lengthArr()   //�Żص�ǰ��ʵ�ʳ���
{
	cout << "lengthArr()" << endl;
	return _curLen;
}

template <typename T>
bool arrList<T>::fullArr() 
{
	cout << "fullArr()" << endl;
	return _curLen == _maxLen;
}

template <typename T>
bool arrList<T>::apendArr(const T value)   //�ڱ�β���Ԫ��V
{
	cout << "apendArr(const T value)" << endl;
	if (_curLen >= _maxLen) {
		cout << "This list is overflow" << endl;
		return false;
	}
	_aList[_curLen] = value;
	_curLen++;
}
template <typename T>
bool arrList<T>::insertArr(const int p, const T value)   //����Ԫ��
{
	int i;
	cout << "insertArr(const int p, const T value)" << endl;
	if (_curLen >= _maxLen) {
		cout << "This list is overflow" << endl;
		return false;
	}
	if (p < 0 || p >= _curLen) {
		cout << "insert postion is illegal" << endl;
		return false;
	}
	for (i = _curLen; i > p; i--)
	{
		_aList[i] = _aList[i- 1];
	}
	_aList[p] = value;
	_curLen++;
	return true;
}

template <typename T> 
bool arrList<T>::deleteArr(const int p)     //ɾ��λ��p�ϵ�Ԫ��
{
	int i;
	cout << "deleteArr(const int p)" << endl;
	cout << "__curLen �� " << _curLen << endl;
	if (_curLen <= 0) {
		cout << "no element to delete" << endl;
		return false;
	}
	if (p < 0 || p > _curLen) {
		cout << "delate postion is illegal" << endl;
		return false;
	}
	cout << "_position �� " << _position << endl;
	for (i = p; i < _curLen - 1; i++) {
		cout << "_position �� " << _position << endl;
		_aList[i] = _aList[i + 1];
	}
	_curLen--;
	cout << "__curLen �� " << _curLen << endl;
	return true;
}

template <typename T>
bool arrList<T>::setValueArr(const int p, const T value) //����Ԫ��ֵ
{
	cout << "setValueArr(const int p, const T value)" << endl;
	if (p < 0 || p > _curLen -1) {
		cout << "setValueArr postion is illegal" << endl;
		return false;
	}
	_aList[p] = value;
	return true;
}

template <typename T>
bool arrList<T>::getValueArr(const int p, T& value)   //����Ԫ��
{
	cout << "getValueArr(const int p, T& value)" << endl;
	if (_curLen <= 0) {
		cout << "no element to delete" << endl;
		return false;
	}
	if (p < 0 || p > _curLen) {
		cout << "insert postion is illegal" << endl;
		return false;
	}
	value = _aList[p];
	return true;
}

template <typename T>
bool arrList<T>::getPosArr(int &p, const T value)    //����Ԫ��
{
	cout << "getPosArr(int &p, const T value)" << endl;
	if (_curLen <= 0) {
		cout << "no element to find" << endl;
		return false;
	}
	for (_position = 0; _position < _curLen; _position++)
	{
		if (value == _aList[_position]) {
			p = _position;
			return true;
		}
	}
	return false;
}
template <typename T>
void arrList<T>::showArr()
{
	cout << "showArr()" << endl;
	_position = 0;
	while (_position < _curLen) {
		cout << _aList[_position++] << " ";
	}
	cout << endl;
}
