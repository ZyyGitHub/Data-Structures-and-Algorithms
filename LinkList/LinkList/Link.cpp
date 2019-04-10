#include "Link.h"
//模板不能在.cpp文件中实现

int main()
{
	//类模板的选择实例化。成员方法只有在使用的时候实例化
	Link<int> link1;
	link1.showLink();
	cout << "==============================" << endl;
	link1.appendLink(11);
	link1.showLink();
	cout << "==============================" << endl;
	link1.insertHeadLink(10);
	link1.insertHeadLink(12);
	link1.insertHeadLink(15);
	link1.insertHeadLink(13);
	link1.insertHeadLink(14);
	link1.showLink();
	cout << "==============================" << endl;
	link1.reserveLink();
	link1.showLink();
	cout << "==============================" << endl;
	//int p = 0;
	//link1.getPosLink(p, 10);
	//cout << endl << p << endl;
	cout << "==============================reserveLink" << endl;
	int value = 0;
	link1.getValueLink(1, value);
	cout << endl << value << endl;
	cout << "==============================" << endl;
	int len = link1.lengthLink();
	cout << "len: " << len << endl;
	link1.deleteLink(5);
	link1.showLink();
	cout << "==============================" << endl;
	int len2 = link1.lengthLink();
	cout << "len: " << len2 << endl;
	cout << "==============================" << endl;
	link1.clearLink();
	link1.showLink();
	cout << "==============================" << endl;
	link1.insertLink(1, 12);
	link1.showLink();
	cout << "==============================" << endl;
	link1.deleteEndPosNode(1);
	link1.showLink();
	cout << "==============================" << endl;
	char* str = new char[sizeof("hello")];
	memcpy(str, "hello", sizeof("hello"));
	Link<const char*> link2;
	link2.appendLink(str);
	link2.showLink();
	link2.insertHeadLink("hi");
	link2.showLink();
	int len3 = link2.lengthLink();
	cout << "len: " << len3 << endl;
}
