#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct example
{
	int no;
	char gender;
	char name[100];
}stud;

typedef struct example2
{
	char* school;
	int no1;
	stud new;
}data;



stud* function1(void );
data* function(stud* );

stud* function1()
{
	stud old;	
	stud *point = malloc(sizeof(stud));
	point->no = 6015;
	point->gender = 'M';
	strcpy(point->name, "Ramesh");
	
return point;
}

data* function(stud* stptr)
{
	data ex;	
	data *point = malloc(sizeof(data));
	point->no1 = 100;
	strcpy(point->school, "SVHS");
	point->new= *stptr->no;
	//point->stptr->gender = stptr->gender;
	//point->stptr->name = stptr->name;
	
return point;
}

int main()
{

data ex;
stud* struct_point = function1();
printf("%d\n", struct_point->no);
printf("%c\n", struct_point->gender);
printf("%s\n", struct_point->name);
data* struct_pointer = function(struct_point);

printf("%d\n", struct_pointer->new->no);
printf("%c\n", struct_pointer->new->gender);
printf("%s\n", struct_pointer->new->name);

//free(struct_pointer);
return 0;
}

