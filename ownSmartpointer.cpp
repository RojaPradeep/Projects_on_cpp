#include<iostream>
using namespace std;
class test{
int value;
public:
test(int x):value(x){}
void print(){cout<<value;}
};

class smartpointer{
 test *ptr;
 public:
  smartpointer(int data=0)
  {
   ptr=new test(data);
  }
  ~smartpointer()
  {
  if(ptr){delete ptr;}
  }
  smartpointer(const smartpointer &)=delete;
  smartpointer& operator=(smartpointer &obj)=delete;
  
  smartpointer(smartpointer &&obj)noexcept
  {
       ptr=obj.ptr;
       obj.ptr=nullptr;   	   
  }
  smartpointer& operator=(smartpointer &&obj)noexcept
  {
      if(this!=&obj)
	  {
	    delete ptr;
	    ptr=obj.ptr;
		obj.ptr=nullptr;
	  }
	  return *this;
  }
  test* operator->(){return ptr;}
  test operator*(){return *ptr;}
};

int main()
{
smartpointer pobj(10);
pobj->print();
}