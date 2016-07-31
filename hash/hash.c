#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

struct node{
	int value;
	struct node* next;
};

struct node* arr_hash[TABLE_SIZE];

void initialize()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		arr_hash[i] = NULL;
	}
}

int HashFunction(int data)
{
	int sum = 0, res;
	while(data)
	{
		res = data%10;
		sum = sum + res;
		data = data/10;
	}
	return sum%TABLE_SIZE;
}

void InsertTable(int data)
{
	int key = HashFunction(data);
	if(arr_hash[key] == NULL)
	{
		arr_hash[key] = (struct node *)malloc(sizeof(struct node));
		arr_hash[key]->value = data;
		arr_hash[key]->next = NULL;
	}
	else
	{
		struct node* head = arr_hash[key];
		while(head->next)
		{
			head = head->next;
		}
		head->next = (struct node *)malloc(sizeof(struct node));
		head->next->value = data;
		head->next->next = NULL;
	}
}

void PrintTable()
{
	int index = 0;
	while(index != TABLE_SIZE)
	{
		if(arr_hash[index] != NULL)
		{
			printf("for index %d\n",index);
			struct node* head = arr_hash[index];
			while(head)
			{
				printf("%d\t", head->value);
				head = head->next;
			}
		index++;
		printf("\n");
		}
		else
			index++;
	}
}

void Delete(int data)
{
	int key = HashFunction(data);
	if(arr_hash[key] == NULL)
	{
		printf("there is no such value in the hash table\n");
		return;
	}

	else if(arr_hash[key] != NULL && arr_hash[key]->next == NULL)
	{
		if(arr_hash[key]->value == data)
		{
			arr_hash[key] = NULL;
			printf("deleted the element\n");
			return;
		}

		else
		{
			printf("there is no such value in the hash table\n");
			return;
		}
	}
	
	else if(arr_hash[key]->value == data && arr_hash[key]->next != NULL)
	{
		struct node* head = arr_hash[key];
		arr_hash[key] = arr_hash[key]->next;
		free(head);
		printf("deleted the element\n");
		return;
	}
	
	else
	{
		struct node* p1 = arr_hash[key]->next;
		struct node* p2 = arr_hash[key];
		
		while(p1 != NULL && p1->value != data)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if(p1 == NULL)
			printf("no such element\n");
			
		else
		{
			struct node* temp = p1;
			p1 = p1->next;
			p2->next = p1;
			free(temp);
			printf("deleted the element\n");
		}
	}
}

int main()
{
	int i, result, select;
	printf("press 1 to insert, 2 to print, 3 to delete and ctrl+c to exit\n");
	while(1)
	{
		scanf("%d", &select);
		switch(select)
		{
			case 1 :
			{
			printf("Enter the value to be inserted\n");
			scanf("%d",&result); 
			InsertTable(result);
			break;
			}
		
			case 2:
			{
				PrintTable();
				break;
			}
			
			case 3:
			{
			printf("enter the value to be deleted\n");
			scanf("%d", &result);
			Delete(result);
			break;
			}
		
			default :
				break;
		}
	}

return 0;
}
