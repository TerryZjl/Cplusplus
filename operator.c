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
        //�޲ι��캯��  
        String()  
        {  
         pstr_=new char[1];  
        }  
  
        //�вι��캯��  
        String (const charchar *s)  
        {  
         pstr_=new char[strlen(s)+1];  
         strcpy(pstr_,s);  
        }  
  
  
        //���ƹ��캯��  
        String (const String &rhs)  
        {  
          pstr_=new char[strlen(rhs.pstr_)+1];  
          strcpy(pstr_,rhs.pstr_);  
        }  
  
  
        //��ֵ�������غ���  
        String &operator = (const String &rhs)  
        {  
         if(this!=&rhs)//��������Ը���  
         {  
          delete []pstr_;//��ɾ����ԭ�е�����  
          pstr_=new char[strlen(rhs.pstr_)+1];  
          strcpy(pstr_,rhs.pstr_);  
         }  
         returnreturn *this;  
        }  
  
  
        //��ֵ�ַ������غ���  
        String &operator = (const charchar *s)  
        {  
         pstr_=new char[strlen(s)+1];  
         strcpy(pstr_,s);  
         returnreturn *this;  
        }  
  
  
        //����+=�����  ��߶��������˸ı�  
        String & operator +=(const String & rhs)  
        {  
         //����ʱ���ַ���ָ����  
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
         tmp = new char[strlen(pstr_)+strlen(pstr)+1];//�ȿ��ռ�  
         strcpy(tmp,pstr_);  
         strcat(tmp,pstr);  
         delete []pstr_;  
         pstr_=tmp;  
         returnreturn *this;  
        }  
  
  
        //����[]�±������  
        char &operator[](size_t index)  
        {  
         static char sNULL='\0';  
         //Ҫ�жϸ������±�Խ������  
         if(index<strlen(pstr_) && index>0)  
         {  
          return pstr_[index];  
         }  
         else  
         {  
          cout<<"�±�Խ��"<<endl;  
          return sNULL;  
         }  
        }  
        //����const����������  
        const char &operator[](size_t index) const  
        {  
          static char sNULL='\0';  
         //Ҫ�жϸ������±�Խ������  
         if(index<strlen(pstr_) && index>0)  
         {  
          return pstr_[index];  
         }  
         else  
         {  
          cout<<"�±�Խ��"<<endl;  
          return sNULL;  
         }  
        }  
  
  
  
  
        //�����ַ������Ⱥ���  ���������const��������������б���ֻ�ܶ����ܸ�  
        size_t size() const  
        {  
          return strlen(pstr_);  
        }  
  
        //����c_str����  ���ص��ǵ�ǰ�ַ��������ַ���ַ  
        const char* c_str()const  
        {  
         return pstr_;  
        }  
  
  
  
  
        //��������  
        ~String()  
        {  
         delete []pstr_;  
        }  
  
        //��ӡ����  
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
//����== ����  
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
//����!=����  
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
//����< ����  
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
//����>����  
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
//����<=����  
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
  
//����>=����  
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
  
//����<<��  
ostream &operator <<(ostream &ofs,const String &rhs)  
{  
        ofs<<rhs.pstr_<<endl;  
        return ofs;  
}  
//����>>��  
istream &operator >>(istream &ifs, String &rhs)  
{  
  
        char tmp[1024];//�ȿ��ռ�  
        ifs>>tmp;  
        rhs.pstr_=tmp;//������ַ� �ŵ�rhs��  
        return ifs;  
  
}  
//����+(��������֮��)  
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
  
        String s1;//�޲κ���  
        s1.print();  
  
        String s2="hello";//�вκ���  
        s2.print();  
  
        String s3=s2;//���ø��ƹ��캯��  
        s3.print();  
  
        String s4="world";//��ֵ�������غ���  
        s4=s2;  
        s4.print();  
  
        String s5; //��ֵ�ַ������غ���  
        s5="hello";  
        s5.print();  
  
  
        String s6="hello";//����+=����  
        String s7="world";  
        s6+=s7;  
        s6.print();  
  
        String s8="hello";//����++����  
        s8+="world";  
        s8.print();  
  
        s8[3]='A';  
        cout<<s8[3]<<endl;//����[]�����  
        s8.print();  
  
  
        String s9="hello";//����c_str����  
        const char* s;  
        s=s9.c_str();  
        cout<<s<<endl;  
  
  
        String s10="hello";  
        if(s9==s10)       //����==  
        {  
         cout<<"equal"<<endl;  
        }  
  
  
        String s11="world";  
        if(s10!=s11)     //����!=  
        {  
         cout<<"unequal"<<endl;  
        }  
  
  
        String s12="i am the max string";//����<  
  
        if(s11<s12)  
        {  
         cout<<"�ұ��ַ�����"<<endl;  
        }  
        else  
        {  
        cout<<"����ַ�����"<<endl;  
        }  
       String s13="hello";//����<<  
        cout<<s13;  
  
        String s14;//����>>  
        cin>>s14;  
        cout<<s14;  
  
        String s15="hello";//����+ �õ���+=  
        String s16="world";  
        cout<<s15+s16<<endl;  
  
  
        return 0;  
  
  
}  
