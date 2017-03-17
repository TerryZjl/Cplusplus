

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
	//��鲢�����ڴ�
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
				cout << "�����ڴ�ʧ��" << endl;
				exit(1);
			}
			_capacity = len;
		}
	}
	//β��
	void PushBack(char ch)
	{
		CheckCapacity(5);
		_str[_size] = ch;
		_str[_size + 1] = '\0';
		++_size;
	}
	//��ָ��λ�ò���ָ�����ȵ��ַ�������
	void Insert(size_t pos, const String&s, size_t SubPos, size_t Len)
	{
		assert(pos <= _size&&SubPos<s._size);

		while (Len>0)  //�弸��ѭ������
		{
			--Len;
			this->Insert(pos, s._str[SubPos - 1]);
			++pos;
			++SubPos;
		}
	}
	//�����ַ�
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
	//����ָ���ַ���
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
			_str[pos + i] = str[i];
			--len;
			++i;
		}
	}
	//ɾ��ָ�������ַ���
	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if ((pos + len)>_size)
		{
			_str[pos] = '\0';
			++pos;
			_size = strlen(_str);
		}
		else
		{
			size_t i = len;
			while (i>0)
			{
				_str[pos] = _str[pos+len];
				--i;
				++pos;
			}
			_size = strlen(_str);
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
	//����[]
	char& operator[](const size_t a)
	{
		if (a<0 || a>_size)
		{
			cout << "�޸Ķ����ַ��±�����" << endl;
			exit(1);
		}
		return _str[a];
	}
	//��ֵ
	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}
	//��������
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
//���������
ostream& operator<<(ostream& out, String& s)
{
	out << s._str;
	return out;
}


int main()
{
	String s1("abcdef");
	String s2("123456");
	//s1[5] = 'a';     ////��
	//s1.PushBack('a');   ////β��
	//s1.Insert(4, s2, 3, 3);  //��һ��
	//s2.Erase(3, 2);        //ɾ
	int ret = s2.Find(2);
	if (ret == -1)
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�±�[ret]" << endl;
	}
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
