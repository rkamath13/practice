#include<iostream>
#include<string.h>

using namespace std;

class A{
private:
	string name;
	int age;
public:
	A(string iname, int iage){
	cout<<"Inside the constructor"<<endl;
	name = iname;
	age = iage;
	}
	
	void disp(){
	cout<<name<<endl<<age<<endl;
	}
	friend void dips2(A obj);
};

void disp2(A obj){
	cout<<obj.name<<endl<<obj.age<<endl;
}

int main()
{
	A troll("ramesh", 23);
	disp2(troll);
return 0;
}
