//#include<iostream>
//#include<string>
//
//using namespace std;
//#pragma warning (disable:4996)
//
//class String
//{
//    friend ostream& operator<<(ostream& out, const String& s);
//public:
//	String(char *str = "")                       //默认参数是一个空字符串，是一个随机地址
//		:_str(new char[(strlen(str)+1)])         //为str开辟一段空间，进行初始化
//	{
//
//		strcpy(_str, str);
//		cout << "String(const char* s)" << endl;
//	}
//
//	////传统深拷贝
//	//String(const String& s)
//	//	:_str(new char[strlen(s._str) + 1])    //深拷贝构造函数
//	//{
//	//	strcpy(_str, s._str);
//	//	cout << "String(const String& s)" << endl;
//	//}
//
//	//交换的方式拷贝构造
//	String(const String& s)     
//		:_str(NULL)              //若是 String str3; str3 = str1; 这种情况，交换赋值时需要调用拷贝构造，
//	{                            //str3._str是创建好的一个空字符串，地址是一个随机的地址，不为NULL，
//		String tmp(s._str);      // 交换内容后，下面析构tmp时就会调用delete，但是并没有动态开辟空间；所以需要在这里把_str置空
//		std::swap(_str, tmp._str);
//		cout<<"String(const String& s)"<<endl;
//	}
//	////传统赋值
//	//String& operator=(const String& s2)                   //想要str1 = str2，不能直接让str1指向str2那段空间，必须从新开辟一段，否则会在析构时出问题
//	//{
//	//	delete[] _str;                                     //先把this指针指向的_str的空间释放了,再给_str开辟新的空间
//	//	if (_str != s2._str)
//	//	{
//	//		_str = new char[strlen(s2._str) + 1];
//	//		strcpy(_str, s2._str);
//	//	}
//	//	return *this;
//	//}
//	//交换赋值方法
//	String& operator=(String s2)     //这里调用拷贝构造函数开辟一段空间复制s2，然后交换s2和*this的字符串
//	{
//		std::swap(_str, s2._str);
//		return *this;
//	}
//
//	~String()
//	{
//		cout << "~String() " << endl;
//		if (_str != NULL)
//		{ 
//			delete[] _str;
//			_str = NULL;
//		}
//	}
//
//	//void CheckCapacity(int count)
//	//{
//	//	if (_size + count >= _capacity)
//	//	{
//	//		int _count = (2 * _capacity)>(_capacity + count) ? (2 * _capacity) : (_capacity + count);
//	//		char *tmp = new char[_count];
//	//		strcpy(tmp, _pstr);
//	//		delete[]_pstr;
//	//		_pstr = tmp;
//	//		_capacity = _count;
//	//	}
//	//}
//private:
//	char *_str;
//
//};
//
//
//ostream& operator<<(ostream& out, const String& s)
//{
//	out << s._str;
//	return out;
//}
//
//
//int main()
//{  
//	String str1 = "pppppppp";
//	String str2(str1);
//	String str3;
//	str3 = str1;
//	cout << str1 << endl;
//	cout << str2 << endl;
//
//	return 0;
//}




//#include<iostream>
//#include<string>
//
//using namespace std;
//#pragma warning (disable:4996)
//
//class String
//{
//	friend ostream& operator<<(ostream& out, const String& s);
//public:
//	String(char *str = "")                       //默认参数是一个空字符串，是一个随机地址
//		:_str(new char[(strlen(str) + 1)])       //为str开辟一段空间，进行初始化
//		, _size(new int(1))
//	{
//		strcpy(_str, str);
//		cout << "String(const char* s)" << endl;
//	}
//
//	////传统深拷贝
//	//String(const String& s)
//	//	:_str(new char[strlen(s._str) + 1])    //深拷贝构造函数
//	//{
//	//	strcpy(_str, s._str);
//	//	cout << "String(const String& s)" << endl;
//	//}
//
//	//写时拷贝
//	String(const String& s)
//		:_str(s._str)
//		, _size(s._size)
//	{
//		++(*_size);
//	}
//
//	//写时赋值s1 = s2
//	//String& operator=(const String& s)
//	//{
//	//	if (_str != s._str)
//	//	{
//	//		CheckRelease();      
//	//		_str = s._str;     //让s1._str指向s2._str
//	//		_size = s._size;   //让s1._size指向s2._size
//	//		++(*s._size);      //引用计数加一
//
//	//	}
//	//}
//	String& operator=(String s)
//	{
//		swap(_str, s._str);
//		swap(_size, s._size);    //s在函数调用完就自动释放了
//		return *this;
//
//	}
//	////传统赋值
//	//String& operator=(const String& s2)                   //想要str1 = str2，不能直接让str1指向str2那段空间，必须从新开辟一段，否则会在析构时出问题
//	//{
//	//	delete[] _str;                                     //先把this指针指向的_str的空间释放了,再给_str开辟新的空间
//	//	if (_str != s2._str)
//	//	{
//	//		_str = new char[strlen(s2._str) + 1];
//	//		strcpy(_str, s2._str);
//	//	}
//	//	return *this;
//	//}
//
//
//	void CheckRelease()   //检查要被改变的s1所指向的空间是否只有s1一个对象指着，若是则释放
//	{
//		if (--(*_size) == 0)
//		{
//			delete[] _str;
//			_str = NULL;
//		}
//	}
//
//	~String()
//	{
//		CheckRelease();
//		cout << "~String() " << endl;
//	}
//
//
//private:
//	char *_str;
//	int *_size;
//};
//
//
//ostream& operator<<(ostream& out, const String& s)
//{
//	out << s._str;
//	return out;
//}
//
//
//int main()
//{
//	String str1 = "pppppppp";
//	String str2(str1);
//	String str3;
//	/*str3 = str1;*/
//	cout << str1 << endl;
//	cout << str2 << endl;
//
//	return 0;
//}
//




#include<iostream>
#include<string>
#include<assert.h>
#pragma warning (disable:4996)
using namespace std;


class String
{
	friend ostream& operator<<(ostream& out, String& s);
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
		, _size(strlen(str))
		, _capacity(strlen(str))
	{
		strcpy(_str, str);
	}
	String(const String& s)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}
	//检查并分配内存
	void CheckCapacity(int count)
	{
		size_t len = _size + count;
		if (len > _capacity)
		{
			char* tmp = (char*)realloc(_str, len+1);  //开辟空间时len+1是总长，不+1就没地放\0
			if (tmp != NULL)
			{
				_str = tmp;
			}
			else
			{
				cout << "开辟内存失败" << endl;
				exit(1);
			}
			_capacity = len;
		}
	}
	//尾插
	void PushBack(char ch)
	{
		CheckCapacity(5);
		_str[_size] = ch;
		_str[_size + 1] = '\0';
		++_size;
	}
	//在指定位置插入指定长度的字符串对象
	void Insert(size_t pos, const String&s, size_t SubPos, size_t Len)
	{
		assert(pos <= _size&&SubPos<s._size);

		while (Len>0)  //插几个循环几次
		{
			--Len;
			this->Insert(pos, s._str[SubPos - 1]);
			++pos;
			++SubPos;
		}
	}
	//插入字符
	inline void Insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		CheckCapacity(5);
		int end = _size;
		while (end >= pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		++_size;
	}

	String SubStr(size_t pos, size_t len)
	{
		assert(pos < _size);
		size_t count = len;
		if (pos + len>_size - 1)
		{
			count = _size - pos;
		}

		String Sub;
		Sub.CheckCapacity(count);
		char* dst = Sub._str;
		char* src = _str + pos;
		for (size_t i = 0; i < count;i++)
		{
			dst[i] = src[i];
		}
		dst[count] = '\0';
		Sub._size = count;
		return Sub;
	}

	//插入指定字符串
	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		int len = strlen(str);
		CheckCapacity(_size + len);
		int end = _size;
		while (end >= (int)pos)//1 2 3 4 5 6
		{
			_str[end + len] = _str[end];
			--end;
		}
		int i = 0;
		while (len)
		{
			_str[pos + i] = str[i];
			--len;
			++i;
			_size++;
		}
	}
	//删除指定长度字符串
	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if ((pos + len) >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			char* dst = _str + pos + len;
			char* src = _str + pos;
			strcpy(src, dst);
			_size -= len ;
		}

	}

	int Find(char ch)
	{
		int i = strlen(_str);
		int j = 0;
		for (j = 0; j < i; j++)
		{
			if (ch == _str[j])
			{
				return j;
			}
		}
		return -1;
	}
	int Find(char* str)
	{
		int i = strlen(_str);
		int j = 0;
		for (j = 0; j < i; j++)
		{
			int n = j;
			char* tmp = str;
			while(*tmp == _str[n])
			{
				tmp++;
				n++;
			}
			if (*tmp == '\0')
			{
				return j;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
	//重载[]
	char& operator[](const size_t a)
	{
		if (a<0 || a>_size)
		{
			cout << "修改对象字符下标有误" << endl;
			exit(1);
		}
		return _str[a];
	}
	//赋值
	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}
	//交换对象
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	~String()
	{
		if (_str != NULL)
		{
			delete[] _str;
			_size = NULL;
			_size = _capacity = 0;
		}
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
//重载输出符
ostream& operator<<(ostream& out, String& s)
{
	out << s._str;
	return out;
}


int main()
{
    String s1("abaaaaaacdef");
	String s2("123456");
	//s1[5] = 'a';     //增
	//s1.PushBack('a');   ////尾插
	//s1.Insert(0, "c");  //插一串
	//s2.Erase(0, 2);        //删
	String tmp = s1.SubStr(2, 6);
	
	//int ret = s2.Find("345");
	//if (ret == -1)
	//{
	//	cout << "没找到" << endl;
	//}
	//else
	//{
	//	cout << "在下标[" <<ret<<"]处"<< endl;
	//}
	cout << s1 << endl;
	cout << tmp << endl;
	cout << s2 << endl;
	
}















