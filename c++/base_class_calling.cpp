#include<iostream>
#include<string>

using namespace std;

class parent{
public:
	void intro(){
	cout<<"I am parent class"<<endl;
	}
};

class child : public parent{
public:
	void intro(){
	cout<<"I am the derived child class"<<endl;
	}
};

void whoAmI(parent p)
{
	p.intro();
}

int main()
{
	child Ram;
	whoAmI(Ram);
return 0;
}
