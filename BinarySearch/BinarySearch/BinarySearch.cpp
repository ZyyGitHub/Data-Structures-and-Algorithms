#include <iostream>
#include <string>
using namespace std;


//迭代二分法查找
template <typename T>
int BinarySearch(T key, T *tmp,int length)
{
	int lower = 0;
	int higher = length -1;
	int mid;
	while (lower <= higher) {
		mid = lower + (higher - lower) / 2;
		if (key < tmp[mid]) {
			higher = mid - 1;
		}
		else if (key > tmp[mid]) {
			lower = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}
int main()
{	
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int b;
	cout << "Please input a number of found key:" << endl;
	cin >> b;
	int tmp = BinarySearch<int>(b, a,sizeof(a)/sizeof(int));
	if (tmp < 0) {
		cout << "not found num in array" << endl;
	}
	else {
		cout << "found mid :" << tmp << " num : " << a[tmp] << endl;
	}
	string strArr[] = { "hello","my", "name" , "is", "C++" };
	string strtmp;
	cout << "Please input a string of found key:" << endl;
	cin >> strtmp;
	int strsul = BinarySearch<string>(strtmp, strArr, sizeof(strArr) / sizeof(string));
	if (strsul < 0) {
		cout << "not found num in array" << endl;
	}
	else {
		cout << "found mid :" << strsul << " num : " << strArr[strsul] << endl;
	}
	return  0;
}