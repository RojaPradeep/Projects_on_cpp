#include<iostream>
#include<cstring>
using namespace std;

class String{
    int size;
    char *str;
    public:
	String(){size=0;str=new char[size+1];str[0]='\0';}
    String(string name)
	{
		size=name.length();
		str=new char[size+1];
		strcpy(str,name.c_str());
	}
	~String(){size=0;delete[] str;}
	const char* c_str()const {return str;}
	String(const String &obj)
	{
		size=obj.size;
		str=new char[size+1];
		strcpy(str,obj.c_str());
	}
	String operator=(String &obj)
	{
		if(this!=&obj)
		{
			delete [] str;
			size=obj.size;
			str=new char[size+1];
			strcpy(str,obj.c_str());
		}
		return *this;
	}
	
	String(String &&obj)noexcept
	{
	    size=obj.size;
		 str=obj.str;
		 obj.str=nullptr;
		 obj,size=0;
	}
	
	String& operator=(String &&obj)noexcept{
		
		if(this!=&obj)
		{
			delete [] str;
			str=obj.str;
			size=obj.size;
			obj.str=nullptr;
			obj.size=0;
		}
		return *this;
	}
	void print()
	{
		cout<<str;
	}
};
int main()
{
   String s("roja");
   String s1=s;
   String s2,dummy;
   s2=s;
   dummy=s;
   String s3=move(dummy);
   dummy=s;
   String s4;
   s4=move(dummy);
   s.print();
   s1.print();
   s2.print();
    return 0;
}