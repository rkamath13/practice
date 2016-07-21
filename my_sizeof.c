#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stdlib.h>

#define mysize(a) (((char *)(&a+1))-((char *)(&a)))

int find_size(int args, ...)
{
	int my_int = 0;
	long my_long = 0;
	float my_float = 0;
	double my_double = 0;
	char my_char = '\0';
	
	int counter = 1;	

	va_list arg_param;
	va_start(arg_param, args);
	my_int = va_arg(arg_param, int);
	my_long = va_arg(arg_param, long);
	my_double = va_arg(arg_param, double);
	//my_char = va_arg(arg_param, uint8);

	if(my_int)
	{
		my_int = 1;
		while(my_int)
		{
			my_int = my_int << 1;
			counter++;
		}
		return counter;
	}
	
}


int main()
{
	char my_char = 'A';
	int my_int = 1;
	float my_float = 1;
	long int my_longint = 1;
	double my_double  = 1 ;
	long double my_longdouble = 1;
	
	int size = find_size(0, my_int);
	printf("size is %d\n", (size-1)/8);
	printf("%d\n",mysize(my_char));
return 0;
}

