#include<iostream>
#include<string>
#include "hash.h"

using namespace std;

hash::hash(){
	cout<<"constructor called"<<endl;
	for(int i=0;i<tableSize;i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty"; 
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

void hash::AddItem(string name, string drink)
{
	int index = Hash(name);
	
	if(HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	
	else
	{
		item* ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while(ptr->next)
			ptr = ptr->next;
		ptr->next = n;
	}
}

int hash::NumberOfItemsInIndex(int index)
{
	int count = 0;
	
	if(HashTable[index]->name == "empty")
		return count;
	else
	{
		count++;
		item* ptr = HashTable[index];
		while(ptr->next)
		{
			count++;
			ptr=ptr->next;
		}
	}
	return count;
}	

void hash::PrintHashTable()
{
	int number;
	for(int i=0;i<tableSize;i++)
	{
		number = NumberOfItemsInIndex(i);
		cout<<"-------------------------"<<endl;
		cout<<"index = "<<i <<endl;
		cout<<"Name is "<<HashTable[i]->name<<endl;
		cout<<"drink is "<<HashTable[i]->drink<<endl;
		cout<<" # of items in the index is "<<number<<endl;
		cout<<"-------------------------"<<endl;
	}
}

void hash::PrintItemsInIndex(int index)
{
	item* ptr = HashTable[index];
	
	if(ptr->name == "empty")
		cout<<"Index is empty"<<endl;
	else
	{
		cout<<"index "<<index<<" the following items - "<<endl;
		while(ptr)
		{
			cout<<"------------------"<<endl;
			cout<<"name is "<<ptr->name<<endl;
			cout<<"drink is "<<ptr->drink<<endl;
			cout<<"------------------"<<endl;
			ptr = ptr->next;
		}
	}
}

void hash::FindDrink(string name)
{
	int index = Hash(name);
	bool foundName = false;
	string drink;
	
	item* ptr = HashTable[index];
	while(ptr)
	{
		if(ptr->name == name)
		{	
			cout<<"found the drink"<<endl;
			drink = ptr->drink;
			foundName = true;
		}
		ptr = ptr->next;
	}
	
	if(foundName == true)
		cout<<drink<<endl;
	else
		cout<<"name is not in the table"<<endl;
	
}			

void hash::RemoveItem(string name)
{
	int index = Hash(name);
	item* ptr;
	item* p1;
	item* p2;
	
	//case 0 - bucket is empty
	if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
		cout<<"Index is empty cannot remove the given name"<<endl;
	
	//case 1 - only 1 item in bucket and it matches the name
	else if(HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		cout<<"The name was removed from the HashTable"<<endl;
	}
	
	
	//case 2 - match is located in the first item but more items present
	else if(HashTable[index]->name == name && HashTable[index]->next != NULL)
	{
		ptr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete ptr;
		cout<<"The name was removed from the HashTable"<<endl;
	}
	
	
	//case 3 - first item is not a match, 3.1 - no match, 3.2 - find match
	else
	{
		p1 = HashTable[index]->next;
		p2 = HashTable[index];
		while(p1 != NULL && p1->name != name )
		{
			p2 = p1;
			p1 = p1->next;
		}
	 	if(p1 == NULL)
			cout<<"No match found for the name in the HashTable"<<endl;
		else
		{
			ptr = p1;
			p1 = p1->next;
			p2->next = p1;
			delete ptr;
			cout<<"removed the item from Hashtable"<<endl;
		}

	}
	

}
	
int hash::Hash(string key)
{
	int hash = 0;
	int index,i;
	index = key.length();
	
	for(i=0;i<index;i++)
		hash += (int)key[i];
//return hash;	
return (hash%tableSize);
}
