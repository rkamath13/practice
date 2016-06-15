#include<stdio.h>
#include<stdlib.h>

inline int add(int a, int b)
{
	int k;
	k = a+b;
	return k;
}

inline int mul(int a, int b)
{
	int k;
	k = a*b;
	return k;
}

int main()
{
	int a,b,c,d,e,f;
	a=5;
	b=6;
	c=3;
	d=9;
	int i;

	for(i=10; i>=0; i--)
	{	
		e=add(a,b);
		f=mul(c,d);
		e=add(e,f);
		f=add(a,d);
		d=mul(e,a);
		e=mul(d,f);
		a=add(d,f);
		d=mul(a,d);
	}
return 0;
}

