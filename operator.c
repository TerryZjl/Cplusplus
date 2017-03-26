#include <iostream>  
#include <string.h>  
#include <string>  
#include <stdio.h>  
  
  
  
using namespace std;  
  
class String  
{  
        friend bool operator == (const String &,const String &);  
        friend bool operator != (const String &,const String &);  
        friend bool operator <  (const String &,const String &);  
        friend bool operator >  (const String &,const String &);  
        friend bool operator <= (const String &,const String &);  
        friend bool operator >= (const String &,const String &);  
  
        friend ostream &operator <<(ostream &os,const String &s);  
        friend istream &operator >>(istream &os,String &s);  
  
  
public:  
        //无参构造函数  
        String()  
        {  
         pstr_=new char[1];  
        }  
  
        //有参构造函数  
        String (const charchar *s)  
        {  
         pstr_=new char[strlen(s)+1];  
         strcpy(pstr_,s);  
        }  
  
  
        //复制构造函数  
        String (const String &rhs)  
        {  
          pstr_=new char[strlen(rhs.pstr_)+1];  
          strcpy(pstr_,rhs.pstr_);  
        }  
  
  
        //赋值对象重载函数  
        String &operator = (const String &rhs)  
        {  
         if(this!=&rhs)//如果不是自复制  
         {  
          delete []pstr_;//先删除掉原有的内容  
          pstr_=new char[strlen(rhs.pstr_)+1];  
          strcpy(pstr_,rhs.pstr_);  
         }  
         returnreturn *this;  
        }  
  
  
        //赋值字符串重载函数  
        String &operator = (const charchar *s)  
        {  
         pstr_=new char[strlen(s)+1];  
         strcpy(pstr_,s);  
         returnreturn *this;  
        }  
  
  
        //重载+=运算符  左边对象本身发生了改变  
        String & operator +=(const String & rhs)  
        {  
         //用临时的字符串指针存放  
         charchar *tmp;  
         tmp=new char[strlen(pstr_)+strlen(rhs.pstr_)+1];  
         strcpy(tmp,pstr_);  
         strcat(tmp,rhs.pstr_);  
         delete []pstr_;  
         pstr_=tmp;  
         returnreturn *this;  
  
        }  
        String &operator += (const charchar *pstr)  
        {  
         charchar *tmp;  
         tmp = new char[strlen(pstr_)+strlen(pstr)+1];//先开空间  
         strcpy(tmp,pstr_);  
         strcat(tmp,pstr);  
         delete []pstr_;  
         pstr_=tmp;  
         returnreturn *this;  
        }  
  
  
        //重载[]下标运算符  
        char &operator[](size_t index)  
        {  
         static char sNULL='\0';  
         //要判断给出的下标越界的情况  
         if(index<strlen(pstr_) && index>0)  
         {  
          return pstr_[index];  
         }  
         else  
         {  
          cout<<"下标越界"<<endl;  
          return sNULL;  
         }  
        }  
        //重载const对象的运算符  
        const char &operator[](size_t index) const  
        {  
          static char sNULL='\0';  
         //要判断给出的下标越界的情况  
         if(index<strlen(pstr_) && index>0)  
         {  
          return pstr_[index];  
         }  
         else  
         {  
          cout<<"下标越界"<<endl;  
          return sNULL;  
         }  
        }  
  
  
  
  
        //返回字符串长度函数  函数后面加const代表这里面的所有变量只能读不能改  
        size_t size() const  
        {  
          return strlen(pstr_);  
        }  
  
        //重载c_str函数  返回的是当前字符串的首字符地址  
        const char* c_str()const  
        {  
         return pstr_;  
        }  
  
  
  
  
        //析构函数  
        ~String()  
        {  
         delete []pstr_;  
        }  
  
        //打印函数  
        void print()  
        {  
         if(pstr_==NULL)  
         {  
         cout<<""<<endl;  
         }  
        else  
        {  
         cout<<"string :"<<pstr_<<endl;  
        }  
        }  
  
private:  
        charchar *pstr_;  
  
};  
//重载== 函数  
bool operator == (const String &lhs,const String &rhs)  
{  
        if(strcmp(lhs.pstr_,rhs.pstr_)==0)  
        {  
         return 1;  
        }  
        else  
         {  
         return 0;  
         }  
}  
//重载!=函数  
bool operator != (const String &lhs,const String &rhs)  
{  
        if(strcmp(lhs.pstr_,rhs.pstr_)==0)  
        {  
         return 0;  
        }  
        else  
         {  
         return 1;  
         }  
}  
//重载< 函数  
bool operator <(const String &lhs,const String &rhs)  
{  
        if(strcmp(lhs.pstr_,rhs.pstr_)<0)  
        {  
         return 1;  
        }  
        else  
        {  
         return 0;  
        }  
}  
//重载>函数  
bool operator >(const String &lhs,const String &rhs)  
{  
        if(strcmp(lhs.pstr_,rhs.pstr_)>0)  
        {  
         return 1;  
        }  
        else  
        {  
         return 0;  
        }  
}  
//重载<=函数  
bool operator <=(const String &lhs,const String &rhs)  
{  
        if(strcmp(lhs.pstr_,rhs.pstr_)<=0)  
        {  
         return 1;  
        }  
        else  
        {  
         return 0;  
        }  
}  
  
//重载>=函数  
bool operator >=(const String &lhs,const String &rhs)  
{  
   if(strcmp(lhs.pstr_,rhs.pstr_)>=0)  
        {  
         return 1;  
        }  
        else  
        {  
         return 0;  
        }  
}  
  
//重载<<流  
ostream &operator <<(ostream &ofs,const String &rhs)  
{  
        ofs<<rhs.pstr_<<endl;  
        return ofs;  
}  
//重载>>流  
istream &operator >>(istream &ifs, String &rhs)  
{  
  
        char tmp[1024];//先开空间  
        ifs>>tmp;  
        rhs.pstr_=tmp;//输入的字符 放到rhs中  
        return ifs;  
  
}  
//重载+(两个对象之间)  
String operator +(const String &lhs,const String & rhs)  
{  
        String str(lhs);  
        str+=rhs;  
        return str;  
}  
String operator +(const String &lhs,const charchar *s)  
{  
        String str(lhs);  
        str+=s;  
        return str;  
}  
String operator +(const charchar *s,const String &rhs)  
{  
        String str(rhs);  
        str+=s;  
        return s;  
  
}  
  
  
int main()  
{  
  
        String s1;//无参函数  
        s1.print();  
  
        String s2="hello";//有参函数  
        s2.print();  
  
        String s3=s2;//调用复制构造函数  
        s3.print();  
  
        String s4="world";//赋值对象重载函数  
        s4=s2;  
        s4.print();  
  
        String s5; //赋值字符串重载函数  
        s5="hello";  
        s5.print();  
  
  
        String s6="hello";//重载+=函数  
        String s7="world";  
        s6+=s7;  
        s6.print();  
  
        String s8="hello";//重载++函数  
        s8+="world";  
        s8.print();  
  
        s8[3]='A';  
        cout<<s8[3]<<endl;//重载[]运算符  
        s8.print();  
  
  
        String s9="hello";//重载c_str函数  
        const char* s;  
        s=s9.c_str();  
        cout<<s<<endl;  
  
  
        String s10="hello";  
        if(s9==s10)       //重载==  
        {  
         cout<<"equal"<<endl;  
        }  
  
  
        String s11="world";  
        if(s10!=s11)     //重载!=  
        {  
         cout<<"unequal"<<endl;  
        }  
  
  
        String s12="i am the max string";//重载<  
  
        if(s11<s12)  
        {  
         cout<<"右边字符串大"<<endl;  
        }  
        else  
        {  
        cout<<"左边字符串大"<<endl;  
        }  
       String s13="hello";//重载<<  
        cout<<s13;  
  
        String s14;//重载>>  
        cin>>s14;  
        cout<<s14;  
  
        String s15="hello";//重载+ 用到了+=  
        String s16="world";  
        cout<<s15+s16<<endl;  
  
  
        return 0;  
  
  
}  
