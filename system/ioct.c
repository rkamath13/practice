#include<termios.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<sys/ioctl.h>

int main()
{
	int fd, status;
	fd = open("/dev/ttyS0", O_RDONLY);
	if(fd < 0)
	{
		printf("caanot open file\n");
		return -1;
	}
	if(ioctl(fd, TIOCMGET, &status) == -1)
	{
		printf("TIOCMGET failed : %s\n",strerror(errno));
		return -1;
	}

	else
	{
		if(status & TIOCM_DTR)
			puts("TIOCM_DTR is not set\n");
		else
			puts("TIOCM_DTR is set\n");
	}
	close(fd);
return 0;
}
	
