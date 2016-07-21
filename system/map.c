#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
	int fd;
	struct stat mystat;
	int size;
	void *map;
	char *src;
	
	fd = open("test.txt", O_RDWR);
	
	if(fd == -1)
	{
		perror("file cannot be opened\n");
		return -1;
	}
	//printf("file descriptor number is %d\n", fd);
	size = fstat(fd, &mystat);
	if(size < 0)
	{
		perror("fstat");
		close(fd);
		return -1;
	}
	//printf("size of the file is %llu\n", mystat.st_size);

	map = mmap(0, mystat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(map == MAP_FAILED)
	{
		//printf("failed mapping\n");
		perror("mmap");
		close(fd);
		return -1;
	}
	
	int *address;
	address = (int *)map;
	//printf("location of the mapped file is %p\n",address);
	
	src = (char*)map;
	int i=0;
	while(src[i] != '\0')
	{
		printf("%c",src[i]);
		i++;
	}
	printf("\n");
	i=0;
	while(src[i] != '\0')
	{
		src[i] = 'X';
		printf("%c", src[i]);
		i++;
	}
		
	close(fd);
return 0;
}
