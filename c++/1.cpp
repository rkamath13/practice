#include<iostream>

using namespace std;

class HumanBeing{
public:
	void display(){
		cout<<"hello there\n";
	}
	void displayAge(int a){
		cout<<"age is"<<a<<"\n";
	}
//private:
//	void disp1(){
//		cout<<"this is private\n";
//	}	
};


int main()
{
	HumanBeing Ramesh;
	Ramesh.display();
	Ramesh.displayAge(23);
//	Ramesh.disp1();

return 0;
}
