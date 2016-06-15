#include<iostream>
#include<string>

using namespace std;

class parent{
public:
	virtual void intro(){
	cout<<"I am parent class"<<endl;
	}
};

class child : public parent{
public:
	void intro(){
	cout<<"I am the derived child class"<<endl;
	}
};

class subchild : public parent{
public:
	void intro(){
	cout<<"I am from the sub child class"<<endl;
	}
};

void whoAmI(parent &p)
{
	p.intro();
}

int main()
{
	parent Raj;
	child Ram;
	subchild Rak;
	whoAmI(Raj);
	whoAmI(Ram);
	whoAmI(Rak);

return 0;
}
