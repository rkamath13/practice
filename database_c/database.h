#include<stdio.h>
#ifndef DATABASE_H
#define DATABASE_H

typedef struct{
	size_t key;
	char fname[20];
	char lname[20];
	unsigned int age;
}__attribute__((packed))record;

int open_record(char* filename);
void close_record(int fd);
int insert_record(int fd, record* rec);
int get_record(int fd, record* rec, int key);
int delete_record(int fd, int key);

#endif
