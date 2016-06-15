#include<stdio.h>
#include<stdlib.h>
#define TOTAL_ADDR 100

int IP_TABLE[256] = {0};

void randomize_host(char ip[])
{
	char* ip_ptr = ip;
	int dot_count = 0;
	char* octet_ptr = (char*)malloc(5*sizeof(char));
	char last_octet[5];
	octet_ptr = last_octet;
	int i = 0, ip_size = 0;
	while(*ip_ptr != '\0')
	{	
		if(*ip_ptr == '.')
		{
			dot_count++;
			ip_ptr++;
			//printf("%d", dot_count);
		}
		else if(*ip_ptr != '.' && dot_count == 3)
		{
				*octet_ptr = *ip_ptr;
				//printf("%c", *last);
				ip_ptr++;
				octet_ptr++;
				i++;
		}
	
		else
			ip_ptr++;
		ip_size++;
	}
	*octet_ptr = '\0';
	//printf("%s\n", last_octet);
	
	i = 0;
	while(last_octet[i] != '\0')
		i++;
	//printf("%d\n", i);
	//printf("%d\n", ip_size);
	
	char new_ip[ip_size-i];
	//new_ip[ip_size-i+1] = '\0';
	memcpy(new_ip, ip, (ip_size-i));
	new_ip[ip_size-i+1] = '\0';
	//printf("%s\n", new_ip);
	int original_last_octet = atoi(last_octet);
	IP_TABLE[original_last_octet] = 1;
	
	int num = 0;
	while(num != TOTAL_ADDR)
	{
		int rand_last_octet = rand()%255;
	

		if(IP_TABLE[rand_last_octet] == 1)
		{
			while(IP_TABLE[rand_last_octet]!=0)
				rand_last_octet = rand()%255;

		}
		IP_TABLE[rand_last_octet] = 1;
		
		sprintf(ip, "%s%d",new_ip, rand_last_octet);
		printf("%s\n", ip);
		num++;
	}
}	
		

void randomize()
{
	char ip[20];
	int i = 0;
	while(i!=10)
	{
		int a,b,c,d;
		a = rand()%255;
		b = rand()%255;
		c = rand()%255;	
		d = rand()%255;
		sprintf(ip,"%d.%d.%d.%d",a,b,c,d);
		printf("%s\n", ip);
		i++;
	}
}

int main()
{
	char ip[20];
	printf("enter an IP address\n");
	scanf("%s", ip);	
	//randomize()
	randomize_host(ip);	

return 0;
}
