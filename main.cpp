#include<iostream>
#include<utility>
using namespace std;
template <typename T>
class smartpointer{
    private:
    T *ptr;
    public:
    smartpointer(){ptr=nullptr;}
    smartpointer(T *p){ptr=p;}
    ~smartpointer(){delete ptr;}
    smartpointer(const smartpointer &obj)=delete;
	smartpointer & operator=(smartpointer &)=delete;
    smartpointer(smartpointer && obj)noexcept
    {ptr=obj.ptr;
    obj.ptr=nullptr;}
    
	smartpointer& operator=(smartpointer&& obj)noexcept{
		if(this!=&obj)
		{
			delete ptr;
			ptr=obj.ptr;
			obj.ptr=nullptr;
		}return *this;
	}
	T* operator->(){return ptr;}
	T& operator*(){return *ptr;}
};
class Rectangle{
    int len,breadth;
   public:
   void area(){cout<<len*breadth;}
   Rectangle(int l,int b):len(l),breadth(b){}
   ~Rectangle(){}
};
int main()
{
    smartpointer<Rectangle>r1(new Rectangle(1,2));
    r1->area();
    smartpointer<Rectangle>r2;
    r2=move(r1);
    r2->area();
    
    return 0;
}