#include<iostream>
#include<string>

using namespace std;

class father{
protected:
	int height;
	string name;
public:
	father(int h, string n){
		cout<<"constructor of father class"<<endl;
	}
	~father(){
		cout<<"destructor of father class"<<endl;
	}
};

class mother{
protected:
	int age;
	string work;
public:
	mother(int a, string w){
		cout<<"constructor of mother class"<<endl;
	}
	~mother(){
		cout<<"destructor of mother class"<<endl;
	}
};

class child: public mother, public father{
public:
	child(int h, string n, int a, string w) : mother(a,w), father(h,n){
		cout<<"constructor of child class"<<endl;
		cout<<"height of father is"<<h<<endl;
		cout<<"name of father is"<<n<<endl;
		cout<<"age of mother is"<<a<<endl;
		cout<<"mother's profession is"<<w<<endl;
	}
	~child(){
	cout<<"Destructor of child class"<<endl;
	}
};

int main()
{
	child *obj = new child(6,"Raj",33,"bank");
	delete obj;
return 0;
}
