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
	}
};


int main()
{
	B obj;
	obj.display();
return 0;
}


