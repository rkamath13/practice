#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ioctl.h>


const char* device = "/dev/bus/usb/001/008";

int main()
{
	int fd;
	fd = open(device, O_RDONLY);
	
	if(fd < 0)
	{
		printf("Error opening device\n");
		return -1;
	}
	
	else
	{
		printf("successfully opened device\n");
	}
return 0;
}
