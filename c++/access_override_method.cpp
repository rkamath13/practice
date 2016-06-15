#include<iostream>
#include<string>

using namespace std;

class A{
public:
	void display(){
		cout<<"Hi I am method of class A"<<endl;
	}
};
	
class B : public A{
public:
	void display(){
		cout<<"Hi i am method of class B"<<endl;
		//second way
		A::display();
	}
};


int main()
{
	B obj1;
	B obj2;
	//first way
	obj1.A::display();
	obj2.display();
return 0;
}


