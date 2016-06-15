#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv) 
{
	unsigned long ip = 0;

    	if (argc < 2) 
   	 {
        	printf("Usage: %s <ipv4>\n", argv[0]);
    		exit(EXIT_FAILURE);
    	 }

   	 if (0 == inet_pton(AF_INET, argv[1], &ip)) 
	 {
        	printf("Failed\n");
        	exit(EXIT_FAILURE);
   	 }

    //printf("IP: %ld\n", ip);
    return 0;
}
