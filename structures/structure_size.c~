#include<stdio.h>
#include<stdlib.h>

struct stud{
	int roll;
	float marks;
	char gender;
};

struct marks{
  int p:3;
  int c:3;
  int m:2;
};

struct stud s[3];

int main()
{
	int start;
	int end;
	start = &s[0].roll;
	end = &s[1].roll;

	printf("sizeof operator %d\n", sizeof(struct stud));
	printf("without sizeof %d\n", end-start);
	
	printf("sizeof operator %d\n", sizeof(struct marks));

return 0;
}
	
