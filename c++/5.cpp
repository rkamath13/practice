#include<iostream>
#include<string>

using namespace std;

class A{
private:
	int age;
	int fakeage(){
		return age-3;
	}
public:
	void setage(int a){
	age = a;
	};

	void dispage(){
		cout<<"age is "<<fakeage()<<endl;
	};
};

int main()
{
	A Ram;
	Ram.setage(23);
	Ram.dispage();
return 0;
}	
