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
		:_str(new char[strlen(str)+1])
		,_size(strlen(str))
		,_capacity(strlen(str))
	{
		strcpy(_str, str);
	}
	String(const String& s)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}
	void CheckCapacity(int count)
	{
		size_t len = _size + count;
		if (len > _capacity)
		{
			char* tmp = (char*)realloc(_str, len);
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
	void PushBack(char ch)
	{
		CheckCapacity(5);
		_str[_size] = ch;
		_str[_size+1] = '\0';
		++_size;
	}
	void Insert(size_t pos, const String&s, size_t SubPos, size_t Len)
	{
		assert(pos <= _size);

		while (Len)
		{
			--Len;
			this->Insert(pos, s._str[SubPos]);
			++pos;
			++SubPos;
		}
		_str[pos] = '\0';
	}
	void Insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		CheckCapacity(5);
		int end = _size;
		while(end >= pos)
		{
			_str[end+1] = _str[end];
			--end;
		}
		_str[pos] = ch;
	}
	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		int len = strlen(str);
		CheckCapacity(_size + len);
		size_t end = _size;
		while (end >= pos)
		{
			_str[end + len] = _str[end];
			--end;
		}
		int i = 0;
		while (len)
		{
			_str[pos+i] = str[i];
			--len;
			++i;
		}
	}
	char& operator[](const size_t a)
	{
		if (a<0 || a>_size)
		{
			cout << "修改对象字符下标有误" << endl;
			exit(1);
		}
		return _str[a];
	}
	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}
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

ostream& operator<<(ostream& out, String& s)
{
	out << s._str;
	return out;
}


int main()
{
	String s1("abcdef");
	String s2("123456");
	//s1[5] = 'a';
	//s1.PushBack('a');
	s1.Insert(4, s2, 3, 3);
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}

