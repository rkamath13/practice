#include<iostream>
#include<string>

using namespace std;

class A{
public:
        string name;
	void intro(){
		cout<<"hi I am "<<name<<endl;
	}
};

//string A::name = "Rkamath";


int main()
{
	
	A Ramesh;
	//Ramesh.name = "Ramesh";
	Ramesh.intro();
	
	A *Suresh = new A();
	Suresh->name = "Suresh";
	Suresh->intro();
	
	//delete Suresh;
return 0;
}
