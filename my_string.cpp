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
//	String(char *str = "")                       //Ĭ�ϲ�����һ�����ַ�������һ�������ַ
//		:_str(new char[(strlen(str)+1)])         //Ϊstr����һ�οռ䣬���г�ʼ��
//	{
//
//		strcpy(_str, str);
//		cout << "String(const char* s)" << endl;
//	}
//
//	////��ͳ���
//	//String(const String& s)
//	//	:_str(new char[strlen(s._str) + 1])    //������캯��
//	//{
//	//	strcpy(_str, s._str);
//	//	cout << "String(const String& s)" << endl;
//	//}
//
//	//�����ķ�ʽ��������
//	String(const String& s)     
//		:_str(NULL)              //���� String str3; str3 = str1; ���������������ֵʱ��Ҫ���ÿ������죬
//	{                            //str3._str�Ǵ����õ�һ�����ַ�������ַ��һ������ĵ�ַ����ΪNULL��
//		String tmp(s._str);      // �������ݺ���������tmpʱ�ͻ����delete�����ǲ�û�ж�̬���ٿռ䣻������Ҫ�������_str�ÿ�
//		std::swap(_str, tmp._str);
//		cout<<"String(const String& s)"<<endl;
//	}
//	////��ͳ��ֵ
//	//String& operator=(const String& s2)                   //��Ҫstr1 = str2������ֱ����str1ָ��str2�Ƕοռ䣬������¿���һ�Σ������������ʱ������
//	//{
//	//	delete[] _str;                                     //�Ȱ�thisָ��ָ���_str�Ŀռ��ͷ���,�ٸ�_str�����µĿռ�
//	//	if (_str != s2._str)
//	//	{
//	//		_str = new char[strlen(s2._str) + 1];
//	//		strcpy(_str, s2._str);
//	//	}
//	//	return *this;
//	//}
//	//������ֵ����
//	String& operator=(String s2)     //������ÿ������캯������һ�οռ临��s2��Ȼ�󽻻�s2��*this���ַ���
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
//	String(char *str = "")                       //Ĭ�ϲ�����һ�����ַ�������һ�������ַ
//		:_str(new char[(strlen(str) + 1)])       //Ϊstr����һ�οռ䣬���г�ʼ��
//		, _size(new int(1))
//	{
//		strcpy(_str, str);
//		cout << "String(const char* s)" << endl;
//	}
//
//	////��ͳ���
//	//String(const String& s)
//	//	:_str(new char[strlen(s._str) + 1])    //������캯��
//	//{
//	//	strcpy(_str, s._str);
//	//	cout << "String(const String& s)" << endl;
//	//}
//
//	//дʱ����
//	String(const String& s)
//		:_str(s._str)
//		, _size(s._size)
//	{
//		++(*_size);
//	}
//
//	//дʱ��ֵs1 = s2
//	//String& operator=(const String& s)
//	//{
//	//	if (_str != s._str)
//	//	{
//	//		CheckRelease();      
//	//		_str = s._str;     //��s1._strָ��s2._str
//	//		_size = s._size;   //��s1._sizeָ��s2._size
//	//		++(*s._size);      //���ü�����һ
//
//	//	}
//	//}
//	String& operator=(String s)
//	{
//		swap(_str, s._str);
//		swap(_size, s._size);    //s�ں�����������Զ��ͷ���
//		return *this;
//
//	}
//	////��ͳ��ֵ
//	//String& operator=(const String& s2)                   //��Ҫstr1 = str2������ֱ����str1ָ��str2�Ƕοռ䣬������¿���һ�Σ������������ʱ������
//	//{
//	//	delete[] _str;                                     //�Ȱ�thisָ��ָ���_str�Ŀռ��ͷ���,�ٸ�_str�����µĿռ�
//	//	if (_str != s2._str)
//	//	{
//	//		_str = new char[strlen(s2._str) + 1];
//	//		strcpy(_str, s2._str);
//	//	}
//	//	return *this;
//	//}
//
//
//	void CheckRelease()   //���Ҫ���ı��s1��ָ��Ŀռ��Ƿ�ֻ��s1һ������ָ�ţ��������ͷ�
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
	//��鲢�����ڴ�
	void CheckCapacity(int count)
	{
		size_t len = _size + count;
		if (len > _capacity)
		{
			char* tmp = (char*)realloc(_str, len+1);  //���ٿռ�ʱlen+1���ܳ�����+1��û�ط�\0
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

	//����ָ���ַ���
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
	//ɾ��ָ�������ַ���
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
    String s1("abaaaaaacdef");
	String s2("123456");
	//s1[5] = 'a';     //��
	//s1.PushBack('a');   ////β��
	//s1.Insert(0, "c");  //��һ��
	//s2.Erase(0, 2);        //ɾ
	String tmp = s1.SubStr(2, 6);
	
	//int ret = s2.Find("345");
	//if (ret == -1)
	//{
	//	cout << "û�ҵ�" << endl;
	//}
	//else
	//{
	//	cout << "���±�[" <<ret<<"]��"<< endl;
	//}
	cout << s1 << endl;
	cout << tmp << endl;
	cout << s2 << endl;
	
}















