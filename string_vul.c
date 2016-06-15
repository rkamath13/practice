#include<stdio.h>
#include<stdlib.h>

int main(void)
 {    
 char a[16];    
 char b[16];    
 char c[32];    
 strcpy(a, "0123456789abcdef");    
 strcpy(b, "0123456789abcdef");    
 strcpy(c, a);    
 strcpy(c, b);    
 printf("a = %s\n", a);
return 0;
 }
