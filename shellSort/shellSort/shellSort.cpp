#include <iostream>
using namespace std;
template <typename T>
void ModInsSort(T * array, int n, int delta) {
	int i, j;
	for ( i = delta; i < n; i += delta)
	{
		cout << "ModInsSort" << endl;
		for ( j = i; j >= delta; j -= delta)
		{
			if (array[j] < array[j - delta])
			{
				swap(array[j], array[j - delta]);
			}
			else break;
		}
	}
}
template <typename T>
void shellSort(T *array, int n) {
	int i, delta;
	for ( delta = n/2; delta > 0; delta /= 2)
	{
		cout << delta << endl;
		for ( i = 0; i < delta; i++)
		{
			cout << "ModInsSort(&array[i], n - i, delta);" << endl;
			ModInsSort(&array[i], n - i, delta);
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
	shellSort<int>(array, 10);
	cout << "shell sort" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}