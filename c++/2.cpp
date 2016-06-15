#include<iostream>
#include<string>

using namespace std;

class School{
public:
	string name;
	void intro(){
		cout<< "Name of school is "<<name<<"\n";
	}
	
};

int main()
{
	School SCU;
	SCU.name = "Santa Clara Universiy";
	SCU.intro();
	
	School CRCE;
	CRCE.name = "Fr. Agnel Bandra";
	CRCE.intro();

return 0;
}
