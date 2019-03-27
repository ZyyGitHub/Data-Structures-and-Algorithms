#include "queue.h"
#include <queue>


int main()
{
	arrQueue<int> intQueue(10);
	for (int i = 11; i > 0; i--)
	{
		intQueue.enQueue(i);
	}
	int tmp ;
	intQueue.deQueue(tmp);
	cout << tmp << endl;
}