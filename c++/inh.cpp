#include<iostream>
#include<string>

using namespace std;

class Person{
public:
	int age;
	string name;
	void setName(string iname){ name = iname;}
	void setAge(int iage){ age = iage;}
};

class student : public Person{
public:
	long ID;
	void setID(long iID) { ID = iID;}
	void intro(){
		cout<<"name "<<name<<endl<<"age "<<age<<endl<<"ID "<<ID<<endl;
	}
};

int main()
{
	student obj;
	obj.setName("ramesh");
	obj.setAge(24);
	obj.setID(1153365);
	obj.intro();
return 0;
}
