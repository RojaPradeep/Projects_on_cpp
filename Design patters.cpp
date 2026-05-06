//singleton design patter
#include<iostream>
using namespace std;
class singleton
{
	private:
	static singleton *instance;
	singleton(){}
	public:
	static singleton* getinstance()
	{
		if(instance==nullptr)
		{
			instance=new singleton();
			
		}
		return instance;
	
	}
	
	void print()
	{
		cout<<"call the class\n";
	}
	
};
 singleton* singleton::instance=nullptr;
int main()
{
	singleton *s1=singleton::getinstance();
	s1->print();
	singleton *s2=singleton::getinstance();
	s2->print();
	return 0;
}
//factory design pattern

#include<iostream>
using namespace std;
class shape{
    public:
    virtual void draw()=0;
    virtual ~shape(){}
};
class circle:public shape{
    public:
    void draw()override{
        cout<<"drawing circle";}
        
};
class rectangle:public shape{

public:
void draw()override{
    cout<<"drawing rectangle";}
};
class shapefactory{
public:
static shape* createshape(const string type)
{
    if(type=="circle"){return new circle();}
    if(type=="rectangle"){return new rectangle();}
    else return nullptr;
}
};
int main()
{
    shape *obj=shapefactory::createshape("rectangle");
    obj->draw();
    return 0;
}

//strategy design pattern
#include<iostream>
using namespace std;
class paystrategy{
 public:
 virtual void pay()=0;
 virtual ~paystrategy(){}
};

class gpay:public paystrategy{
public:
 void pay() override{
    cout<<"pay through gpay";}
    
};
class phonepay:public paystrategy{
public:
void pay()override{
cout<<"pay through phonepay";}
};
class strategy{
 paystrategy *p;
 public:
 void setstrategy(paystrategy *obj)
 { 
     p=obj;
 }
 void notify()
 { 
     p->pay();
 }
    
};
int main()
{   
    strategy *s=new strategy();
    s->setstrategy(new gpay());
    s->notify();
    return 0;
}
