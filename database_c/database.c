#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include "database.h"

int open_record(char* filename)
{
	int fd;
	fd = open(filename, O_CREAT|O_RDWR|O_APPEND, 0644);
	if(fd == -1)
		perror("open_record");

	return fd;
}

int open_record_update(char* filename)
{
	int fd;
	fd = open(filename, O_CREAT|O_RDWR, 0644);
	if(fd == -1)
		perror("open_record");

	return fd;
}

void close_record(int fd)
{
	close(fd);
}

int insert_record(int fd, record* rec)
{
	int ret;
	ret = write(fd, rec, sizeof(record));
	return ret;
}

int get_record(int fd, record* rec, int key)
{
	int ret;
	while((ret = read(fd, rec, sizeof(record))) != -1)
	{
		if(ret == 0)
		{
			memset(rec, 0, sizeof(record));
			break;
			return ret;
		}

		else if(key == rec->key)
			return ret;
	}
	memset(rec, 0, sizeof(record));
	return ret;
}

int delete_record(int fd, int key)
{
	int ret;
	record rec;
	off_t position;
	
	position = lseek(fd, 0, SEEK_SET);
	
 	while((ret = read(fd, &rec, sizeof(record))) != -1)
	{
		if(ret == 0)
		{
			return ret;
		}

		else if(key == rec.key)
		{
			lseek(fd, position, SEEK_SET);		
			rec.key = 0;
			ret = write(fd, &rec, sizeof(record));  
			return ret;
		}
		position = lseek(fd, 0, SEEK_CUR);
	}	

	return ret;

}



