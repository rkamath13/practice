#include<stdio.h>
#include<stdarg.h>

//Define a va_list variable
//begin with va_start and end with va_end

//Add variadic integers

int Add(int args, ...)
{
	va_list arg_param;
	va_start(arg_param, args);

	//my logic starts now
	int i = 0;
	int sum = 0;
	for(i=0;i<args;i++)
		sum = sum+va_arg(arg_param, int);

	va_end(arg_param); 
return sum;
}

int main()
{
	int result,a,b,c;
	printf("enter 3 numbers\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	result = Add(3,a,b,c);
	printf("result is %d\n", result);
return 0;
}
