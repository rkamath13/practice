#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10

struct node{
	char* name;
	struct node* next;
};

struct node* arr_hash[TABLE_SIZE];

void initialize()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		arr_hash[i] = (struct node *)malloc(sizeof(struct node)) ;
		arr_hash[i]->name = "empty";
		arr_hash[i]->next = NULL;
	}
		
}


struct node* MakeNode(char* value)
{
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->name = value;
	temp->next = NULL;
	return temp;
}

int HashFunction(char* value)
{


	int key = 0;
	while(*value++ != '\0')
		key = key + *value;
	return key%TABLE_SIZE;

}

void Insert(char* value)
{
	/*
	int key = HashFunction(value);
	printf("the key is %d\n", key);
	if(arr_hash[key] == NULL)
	{
		arr_hash[key] = MakeNode(value);
	}
	else
	{
		struct node* head = arr_hash[key];
		while(head)
			head = head->next;
		head = MakeNode(value);
	}
	*/

	int key = HashFunction(value);
	char emp[] = "empty";
	char* check = (char *)malloc(sizeof(strlen(emp)+1));
        if(Compare(arr_hash[key]->name, check))
        {
                arr_hash[key]->name = value;
        }
	else
        {
                struct node* ptr = arr_hash[key];
                struct node* n = MakeNode(value);
                while(ptr->next)
                        ptr = ptr->next;
                ptr->next = n;
        }

}

int Compare(char* A, char* B)
{
	while(*A != '\0' && *B != '\0')
	{
		if(*A != *B)
			return 0;
		else
		{
			printf("%c%c\t", *A, *B);
			A++;
			B++;
		}
	}
	return 1;
}

void IsContains(char* value)
{
	int key = HashFunction(value);
	printf("the key is %d\n", key);
	struct node* head = arr_hash[key];
	printf("%s\n", arr_hash[key]->name);

	while(head)
	{
		if(Compare(value, head->name))
		{
			printf("contains\n");
			return;
		}
		head = head->next;
	}
		printf("not contains\n");
		return;
}

void Delete(char* value)
{
	int key = HashFunction(value);
	
	
	//if index is NULL
	if(arr_hash[key] == NULL)
		printf("Cannot delete....no value in the index\n");

	//if only one element is present in the index
	else if(Compare(arr_hash[key]->name, value) && (arr_hash[key]->next == NULL))
	{
		arr_hash[key] = NULL;
		printf("removed the value from hash table\n");
	}
	
	//if the element is found on index and it has a chain
	else if(Compare(arr_hash[key]->name, value) && (arr_hash[key]->next != NULL))
	{
		struct node* temp = arr_hash[key];
		arr_hash[key] = arr_hash[key]->next;
		free(temp);
		printf("removed the value from hash table\n");
	}
	
	//if element is not found on the first index...search in the chain
	else 
	{
		struct node* head = arr_hash[key];
		while(head)
		{
			if(Compare(head->name, value))
			{
				head = head->next;
				free(head);
				return;
			}
			else
				head = head->next;
		}
		printf("Cannot delete....no such value found\n");
	}
}

int main()
{
	int i;
	initialize();
	char fname[20];
	
	for(i=0;i<5;i++)
	{
		printf("Enter the string %d\n", i);
		scanf("%s", fname);
		char* value = (char *)malloc(sizeof(strlen(fname)+1));
		value = fname;
		Insert(value);
	}


	for(i=0;i<5;i++)
	{
		printf("Enter the string you want to search\n");
		scanf("%s", fname);
		char* value = (char *)malloc(sizeof(strlen(fname)+1));
                value = fname;
		IsContains(value);
	}
return 0;
}
