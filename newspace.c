#include<iostream>
using namespace std;


void TestNew()
{
	int *p1 = new int;
	int *p2 = new int(4);
	int *p3 = new int[5];

	delete p1;
	delete p2;
	delete[] p3;

}
int main()
{
	TestNew();
	return 0;
}


