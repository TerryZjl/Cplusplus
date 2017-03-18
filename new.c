#include<iostream>
using namespace std;

void test()
{
	int *p1 = (int*)malloc(sizeof(int)*4);
	free(p1);

	int *p2 = (int*)calloc(4, sizeof(int));
	int *p3 = (int *)realloc(p2, sizeof(int)* 6);

	free(p3);
}
int main()
{
	test();
	return 0;
}

void test()
{
	int *p1 = new int;
	int *p2 = new int(4);
	int *p3 = new int[5];

	delete p1;
	delete p2;
	delete[] p3;

}

class Array
{
public:
	Array(size_t size = 10)
		:_a(0)
		, _size(size)
	{
		cout << "Array()" << endl;
		if (_size > 0)
		{
			_a = new int[size];
		}
	}
	~Array()
	{
		cout << "~cout()" << endl;
		delete[] _a;
		_a = 0;
		_size = 0;
	}
private:
	int* _a;
	size_t _size;
};

int main()
{
	//Array* p1 = (Array*)malloc(sizeof(Array));
	//Array* p2 = new Array;
	//Array* p3 = new Array(20);
	Array* p4 = new Array[3];
/*	*((int*)p4 - 1) = 5; */     //10->5

	//free(p1);
	//delete p2;
	//delete p3;
	delete[] p4;

	//int* p1 = new int[10];  
	//delete[] p1;            
	                          
	return 0;
}
