#include<iostream>
#include<string>

using namespace std;

class A{
public:
	A(){
		cout<<"A created\n";
	}
	~A(){
		cout<<"A destroyed"<<endl;
	}
};

class B : public A{
public:
	B(){
		cout<<"B created"<<endl;
	}
	~B(){
		cout<<"B destroyed"<<endl;
	}
};

int main()
{
	B *obj = new B();
	delete obj;
return 0;
}


