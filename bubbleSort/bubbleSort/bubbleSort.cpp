#include <iostream>
using namespace std;

//�����λ�ã�ÿ�δӵ�һ����ʼ�Ƚϲ��ñȽ��³��Ժ����������С��Ԫ��
template <typename T>
void bubbleSort(T *array, int n) {
	int i, j;
	bool bubbleFlag = false;
	for ( i = 0; i < n - 1 && !bubbleFlag; i++)
	{
		cout << i << endl;
		bubbleFlag = true;
		for ( j = 0; j < n - i -1; j++)
		{ 
			cout << j << endl;
			if (array[j] > array[j+1])
			{
				cout << "swap" << array[j] << " " << array[j + 1] << endl;
				swap(array[j], array[j+1]);
				bubbleFlag = false;
			}
		}
		cout << "one cricle" << endl;
	}
}
int main(int argc, char **argv) {
	int array[10];
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	bubbleSort<int>(array, 10);
	cout << "bubble sort" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
