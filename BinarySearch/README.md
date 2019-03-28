#BinarySearch
## 
'''
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
'''
