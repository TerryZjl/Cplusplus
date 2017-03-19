#include<iostream>
#include<assert.h>
using namespace std;

typedef int DataType;

class Seqlinst
{
public:
	Seqlinst()
		:_a(NULL)
		, _size(0)
		, _capacity(0)
	{
	}
	Seqlinst(const Seqlinst& s)
	{
		if (_a == NULL)
		{
			_a = (DataType*)malloc(sizeof(DataType)*s._size);
			memcpy(_a, s._a, sizeof(DataType)*s._size);
		}
		else
		{
			_a = NULL;
			_a = (DataType*)malloc(sizeof(DataType)*s._size);
			memcpy(_a, s._a, sizeof(DataType)*s._size);
		}
	}

	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			_capacity = _capacity * 2 + 3;
			_a = (DataType*)realloc(_a, _capacity*sizeof(DataType));
		}
	}

	void Erase(size_t pos)
	{
		assert(pos < _size);
		while(pos < _size - 1)
		{
			_a[pos] = _a[pos + 1];
			pos++;
	    }
		_size--;
	}


	int Find(DataType x)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_a[i] == x)
			{
				return i;
			}
		}
		return -1;
	}
	void Insert(size_t pos, DataType x)
	{
		CheckCapacity();
		_a[pos] = x;
		_size++;
	}

	void print()
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << _a[i] << "->";
		}
		cout << "NULL" << endl;
	}

	~Seqlinst()
	{
		if (_a != NULL)
		{
			free(_a);
			_size = _capacity = 0;
		}
	}


private:
	DataType* _a;
	int _size;
	int _capacity;
};



int main()
{
	Seqlinst a;
	a.Insert(0, 1);
	a.Insert(1, 2);
	a.Insert(2, 3);
	a.Insert(3, 4);
	a.Insert(4, 5);
	a.Erase(1);
	int ret = a.Find(3);
	if (ret == -1)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "pos:[" << ret << "]" << endl;
	}
	a.print();
	return 0;
}
















