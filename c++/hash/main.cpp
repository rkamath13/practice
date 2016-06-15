#include<iostream>
#include<string>
#include "hash.h"

using namespace std;

int main(int argc, char* argv[])
{
	hash obj;
	string name;
	obj.AddItem("Ramesh", "Guiness");
	obj.AddItem("Vivek", "Old monk");
	obj.AddItem("Shashank", "Tuborg");
	obj.AddItem("Nirav", "Budweiser");
	obj.AddItem("Royan", "Royal Stag");
	obj.AddItem("Chitti", "Desi");
	obj.AddItem("Vicky", "Heinneken");
	obj.AddItem("Parth", "sex on the beach");
	obj.AddItem("Siddhesh", "antiquity blue");
	obj.AddItem("prantit", "black dogg");
	obj.AddItem("Manav", "hoegarden");
	
	obj.PrintHashTable();
	int count = 6;
	while(count)
	{
		string name;
		cout<<"enter the name to be removed"<<endl;
		cin>>name;
		obj.RemoveItem(name);
		count--;
	}
	
	obj.PrintHashTable();
	//obj.PrintItemsInIndex(1);
	//obj.PrintItemsInIndex(6);
	//obj.PrintItemsInIndex(8);
	
	//cout<<"Enter the name to be searched"<<endl;
	//cin>>name;
	//obj.FindDrink(name);	
	
return 0;
}
