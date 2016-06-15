#include<stdio.h>
#include<stdlib.h>

int main()
{

	int a = 0X12345678;
	int k1 = (a & 0x000000ff) << 24;
	int k2 = (a & 0x0000ff00) << 8;
	int k3 = (a & 0x00ff0000) >> 8;
	int k4 = (a & 0xff000000) >> 24;

	int k = (k1|k2|k3|k4);
	printf("little endian %x\n", a);	
	printf("big endian %x\n", k);
return 0;
}
