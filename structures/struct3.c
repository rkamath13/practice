#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// using typedef for defining structure
typedef struct example
{
	int no;
	char gender;
	char name[100];
}data;
data *struct_pointer;

data* function(void );

data* function()
{
	data ex;	
	data *point = malloc(sizeof(data));
	point->no = 100;
	point->gender = 'M';
	strcpy(point->name, "Ramesh");
return point;
}

int main()
{

data new;
struct_pointer = function();

printf("%d\n", struct_pointer->no);
printf("%c\n", struct_pointer->gender);
printf("%s\n", struct_pointer->name);

free(struct_pointer);
return 0;
}

