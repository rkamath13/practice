#include<stdio.h>
#include "list_lib.h"

int main()
{
	insert_tail(3);
	insert_head(4);
	insert_tail(1);
	print();
	insert_head(7);
	insert_head(8);
	print();
	insert_head(17);
	delete(2);
	insert_head(21);
	print();
	delete(4);
	print();
	reverse();
	print();
return 0;
}
