#include "stack.h"
#include <string>
//#include <stack>

int main()
{
	arrStack<int> intstack(10);
	for (int i = 0; i < 10; i++)
	{
		intstack.push(i);
	}
	int tmp = 0;
	intstack.pop(tmp);
	cout << tmp << endl;
	tmp = 0;
	intstack.pop(tmp);
	cout << tmp << endl;
	tmp = 0;
	intstack.pop(tmp);
	cout << tmp << endl;

	linkStack<int> linkintstack;
	for (int i = 0; i < 10; i++)
	{
		linkintstack.push(i);
	}
	int linktmp = 0;
	linkintstack.pop(linktmp);
	cout << linktmp << endl;
	linktmp = 0;
	linkintstack.pop(linktmp);
	cout << linktmp << endl;
	linktmp = 0;
	linkintstack.pop(linktmp);
	cout << linktmp << endl;
}
