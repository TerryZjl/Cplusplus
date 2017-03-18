#include<iostream>
using namespace std;

class Array
{
public:

	Array(int sz)
		:_sz(sz)
		, _ptr(new int[_sz])
	{
		cout << "Array" << endl;
	}
	
	//Array(const Array& cp)      
	//{
	//	_sz = cp._sz;
	//	_ptr = cp._ptr;
	//}

	
	Array(const Array& cp)      
		:_sz(cp._sz)            
		, _ptr(new int[_sz])
	{
		cout << "Array(const Array& cp)" << endl;
	}
	~Array()
	{
		if (_ptr != NULL)
		{
			delete[] _ptr;
		}
		cout << "~Array" << endl;
	}

private:
	int _sz;
	int *_ptr;
};

int main()
{
	Array p1(5);
	Array p2(p1);

	return 0;
}












