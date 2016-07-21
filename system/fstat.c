#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd = open("Ramesh_Kamath_resume.pdf", O_CREAT|O_RDWR);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}

	struct stat mystat;
	
	if(fstat(fd, &mystat))
	{
		perror("fstat");
		close(fd);
		return -1;
	}
	
	printf("File type:                ");

        switch (mystat.st_mode & S_IFMT) 
	{
        	case S_IFBLK:  printf("block device\n");            break;
        	case S_IFCHR:  printf("character device\n");        break;
           	case S_IFDIR:  printf("directory\n");               break;
           	case S_IFIFO:  printf("FIFO/pipe\n");               break;
           	case S_IFLNK:  printf("symlink\n");                 break;
           	case S_IFREG:  printf("regular file\n");            break;
           	case S_IFSOCK: printf("socket\n");                  break;
		default:       printf("unknown?\n");                break;
        }

        printf("I-node number:%ld\n", (long) mystat.st_ino);
	printf("Mode:%lo (octal)\n",(unsigned long) mystat.st_mode);
	printf("Link count:%ld\n", (long) mystat.st_nlink);
       	printf("Ownership:UID=%ldGID=%ld\n",(long) mystat.st_uid, (long) mystat.st_gid);
	printf("Preferred I/O block size: %ld bytes\n",(long) mystat.st_blksize);
        printf("File size: %lld bytes\n",(long long) mystat.st_size);
        printf("Blocks allocated:%lld\n",(long long) mystat.st_blocks);
	printf("Last status change:%s", ctime(&mystat.st_ctime));
        printf("Last file access:%s", ctime(&mystat.st_atime));
        printf("Last file modification:%s", ctime(&mystat.st_mtime));

	close(fd);
	return 0;
}

	
