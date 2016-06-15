#include<iostream>
#include<string>

using namespace std;

class A{
public:
	string name;
	void intro();
};
//string A::name = "ramesh";
void A::intro(){
	cout<<"Hi I am "<<A::name<<endl;
}

int main()
{
	A Ramesh;
	Ramesh.name = "Ramesh";
	Ramesh.intro();

return 0;
}
