#include<stdio.h>
#include<stdarg.h>

void myprintf(char *format, ...)
{
	va_list ap;
	va_start(ap,format);
	vprintf(format, ap);
	va_end(ap);
}


int main()
{
	myprintf("ID: %d, Name: %s, Age: %d\n", 13456, "Ramesh Kamath", 23);
	myprintf("%d number of %s\n", 2, "arguments");
return 0;
}
