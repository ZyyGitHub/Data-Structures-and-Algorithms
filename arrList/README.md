# arrList 线性表利用模板实现
## 1、模板的调用要看到模板的定义，模板的实例化实在编译阶段进行的，编译阶段每一个cpp文件都是单独进行编译
## 2、类模板不能重载
## 3、线性表的增删改查
## 4、线性表应该注意边界问题防治溢出
### class
```
template <typename T>
class arrList
{
public:
	arrList(const int size);
	~arrList();
	void clearArr();
	int lengthArr();
	bool fullArr();        //判断是否满
	bool apendArr(const T value);    //尾部添加元素
	bool insertArr(const int p, const T value);   //插入元素
	bool deleteArr(const int p);      //删除元素
	bool setValueArr(const int p, const T value);    //修改某个位置的元素
	bool getValueArr(const int p, T& value);       //获取某个位置的元素
	bool getPosArr(int &p, const T value);      //查找是否有这个值在表中
	void showArr();
private:
	int _curLen;        //表实例当前长度
	int _maxLen;		//表实例最大长度   有一个元素0的时候长度为1
	T *_aList;          //存储表实例
	int _position;      //当前处理位置  处理位置从0开始
};
```








