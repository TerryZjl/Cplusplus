#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
struct ss
{
	int a;
	int b;
};

struct comp
{
	bool operator()(ss l, ss r)
	{
		if (l.a == r.a)
		{
			return l.b < r.b;
		}
		else
		{
			return l.a < r.a;
		}
	}
};
//struct comp
//{
//	bool operator()(ss l, ss r)
//	{
//		if (l.a <  r.a)
//		{
//			return true;
//		}
//		else if (l.a>r.a)
//		{
//			return false;
//		}
//		else
//		{
//			if (l.b <=  r.b)
//			{
//				return true;
//			}
//			else if (l.b>r.b)
//			{
//				return false;
//			}
//		}
//	}
//};
int main()
{
	vector<ss>v;
	ss s1, s2, s3, s4, s5, s6, s7, s8;
	s1.a = 2; s1.b = 23;
	s2.a = 1; s2.b = 213;
	s3.a = 2; s3.b = 231;
	s4.a = 5; s4.b = 123;
	s5.a = 3; s5.b = 223;
	s6.a = 3; s6.b = 15;
	s7.a = 3; s7.b = 123;
	s8.a = 1; s8.b = 5;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	v.push_back(s6);
	v.push_back(s7);
	v.push_back(s8);
	sort(v.begin(), v.end(), comp());
	vector<ss>::iterator ite_;
	int i = 0;
	for (ite_ = v.begin(); ite_ != v.end(); ++ite_)
	{
		cout << ite_->a << " " << ite_->b << endl;
	}
	system("pause");
	return 0;
}
