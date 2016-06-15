#include<iostream>
#include<string>

using namespace std;

class A{
private:
	int age;
	string name;
public:
	A(){
		age = 0;
		name = "untitled";
		cout<<"Inside the constructor"<<endl;
	}
	void Display();
};

void A::Display(){
	cout<<"Name is "<<name<<endl<<"Age is "<<age<<endl;
}

int main(){

	A Ram;
	Ram.Display();

return 0;
}
