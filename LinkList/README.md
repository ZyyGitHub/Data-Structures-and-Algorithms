# 链表的实现
- 定义一个开始节点初始化为空
- 链表的前驱和后继，开始节点（头节点没有前驱只有唯一后继），尾节点（没有后继只有唯一前驱，
- 链表存储的节点有两部分组成：数据段和指针域（后继地址）
- 建立链表
- 清除链表
- 插入一个新元素
- 删除一个元素
- 修改一个元素
- 检索
带头结点的单链表
– 整个单链表： head
– 第一个结点： head->next，head ≠ NULL
– 空表判断： head->next == NULL
当前结点a1：fence->next (curr 隐含)
```
template <typename T>
class Link;
//类模板   除了构造和析构的名字可以省略参数列表，其他抵挡不能省略
template <typename T>
class Node
{
public:
	Node(T data = T()):_data(data),_pnext(NULL){}
private:
	T _data;
	Node<T> *_pnext;   //_pnext私有成员不能访问

#if 0    //含有太多的多余关系
	template <typename T>
	friend class Link;
#endif

	friend class Link<T>;
};

template <typename T>
class Link {
public:
	Link();
	~Link();
	bool isEmptyLink();   //检查链表是否为空
	void clearLink();     //将链表存储的内容清除，成为空表
	int lengthLink();     //链表的长度
	bool appendLink(const T value);   //尾部扩展节点
	bool insertHeadLink(const T value); //头部插入节点
	bool insertLink(const int p, const T value);   //某个节点插入
	bool deleteLink(const int p);    //删除某个节点
	bool getValueLink(const int p, T &value);   //获取节点的值
	bool getPosLink(int &p, const T value);     //检索
	void showLink();     //显示链表
	void reserveLink();   //翻转链表
	void deleteEndPosNode(int n);   //删除倒数N个节点
private:
	Node<T> *_phead;     //类的组合关系，利用友元类
};
```