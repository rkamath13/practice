#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "database.h"

int main(int argc, char* argv[])
{
	int fd;
	record rec;
	
	//fd = open_record("database");
	
	if(argc > 1)
	{
		/* Insertion */
		if(argc > 5 && !strcmp(argv[1], "insert"))
		{
			fd = open_record("database");
			rec.key = atoi(argv[2]);
			strcpy(rec.fname, argv[3]);
			strcpy(rec.lname, argv[4]);
			rec.age = atoi(argv[5]);
			insert_record(fd, &rec);
		} 
		
		/* Deletion */
	        else if(argc >2 && !strcmp(argv[1], "delete"))
		{
			fd = open_record_update("database");
			delete_record(fd, atoi(argv[2]));
		}

		/* print */
		else if(argc > 2 && !strcmp(argv[1], "print"));
		{
			fd = open_record("database");
			get_record(fd, &rec, atoi(argv[2]));
			
			printf("key = %d\n", rec.key);
			printf("first name = %s\n", rec.fname);
			printf("last name = %s\n", rec.lname);
			printf("age = %d\n", rec.age);
		}
	 }
	
	close_record(fd);
return 0;
}
