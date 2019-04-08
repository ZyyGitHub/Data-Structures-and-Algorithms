#include <iostream>

using namespace std;

template <typename T>
void selectSort(T *array,int n) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		int minflag = i;
		for ( j = i+1; j < n; j++)
		{
			if ( array[j] < array[minflag])
			{
				swap(array[j], array[minflag]);
			}
		}
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
	selectSort<int>(array, 10);
	cout << "select sort" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}