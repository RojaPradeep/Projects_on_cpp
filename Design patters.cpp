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
