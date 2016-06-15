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

void print(data );

void print(data c)
{
	c.no = 156;
	printf("%d\n", c.no);
	printf("%c\n", c.gender);
	printf("%s\n", c.name);
}

int main()
{

data ex;

ex.no = 100;
ex.gender = 'M';
strcpy(ex.name, "Ramesh");

//printf("%d\n", ex.no);
//printf("%c\n", ex.gender);
//printf("%s\n", ex.name);

print(ex);

return 0;
}


