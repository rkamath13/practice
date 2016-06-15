#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>

int main()
{
	char ip[20];
	printf("Enter the IP address\n");
	scanf("%s", ip);
	//printf("%s", ip);
	
	char* ip_ptr = (char*)malloc(sizeof(char));
	ip_ptr = ip;
/*	int dot_count = 0;
	while(*ip_ptr!='\0')
	{
		if(*ip_ptr == '.')
			dot_count++;
		ip_ptr++;
	}
	if(dot_count != 3)
		perror("IP address doesnt have 4 octets\n");
	ip_ptr = ip;
	//printf("%c", *ip_ptr);	
*/
	while(*ip_ptr != '\0')
	{
		char single_octet[3];
		//char* sing_oct = (char*)malloc(sizeof(char));
		char* sing_oct =  single_octet;
		while(*ip_ptr != '.')
		{
			*sing_oct = *ip_ptr;
			ip_ptr++;
			sing_oct++;
		}
			*sing_oct = '\0';
			printf("%s\n", single_octet);
		
			ip_ptr++;
			
	}
	/*
		int ip_number = atoi(single_octet);
		if(ip_number > 255)
		{
			perror("octet size greater than 255, invalid!!\n");
			change = 0;
		}
		ip_ptr++;
	}
	//if(change == 1)
		printf("valid IP address\n");
*/return 0;
}		
