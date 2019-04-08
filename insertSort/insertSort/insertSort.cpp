#include <iostream>

using namespace std;

template <typename T>
void ImproveInsertSort(T *array, int n) {
	T temp;
	int i, j;
	for (i = 1; i < n; i++)
	{
		temp = array[i];
		int j = i - 1;
		while (j >= 0 && temp < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
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
	ImproveInsertSort<int>(array, 10);
	cout << "Insert sort" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}