#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<sys/mman.h>
#include<linux/videodev2.h>

const char* device = "/dev/video0";

int main()
{

//------------------------------------------------------------//
// 			Opening Device                       //
//----------------------------------------------------------//

	int videofd;
	videofd = open(device, O_RDWR);
	if(videofd < 0)
	{
		perror("open");
		return -1;
	}
	
//---------------------------------------------------------//
// 		Retrieve Device Capabilities              //
//--------------------------------------------------------//

	struct v4l2_capability cap;
	
	if(ioctl(videofd, VIDIOC_QUERYCAP, &cap) <0 )
	{
		perror("VIDIOC_QUERYCAP");
		return -1;
	}
	
	printf("driver is %s\n", cap.driver);
	printf("card is %s\n", cap.card);
	printf("name of the bus is %s\n", cap.bus_info);
	printf("Kernel version for the driver is %u.%u.%u\n", (cap.version >> 16) & 0xFF, (cap.version >> 8 ) & 0xFF, (cap.version) & 0xFF); 
	
	if(!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))
	{
		printf("This device does not handle single planar video capture\n");
		return -1;
	}	

//------------------------------------------------------------//
// 			Set the Video Format                 //
//-----------------------------------------------------------//

	struct v4l2_format format;
	format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	format.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
	format.fmt.pix.width = 800;
	format.fmt.pix.height = 600;
	
	if(ioctl(videofd, VIDIOC_S_FMT, &format) < 0)
	{
		perror("VIDIOC_S_FMT");
		return -1;
	}


//--------------------------------------------------------------//
//		Inform about the future buffers                 //
//-------------------------------------------------------------//


	struct v4l2_requestbuffers bufrequest;
	bufrequest.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	bufrequest.memory = V4L2_MEMORY_MMAP;
	bufrequest.count = 10;
	
	if(ioctl(videofd, VIDIOC_REQBUFS, &bufrequest) < 0)
	{
		perror("VIDIO_REQBUFS");
		return -1;
	}


//--------------------------------------------------------------//
//			Allocate buffers 		       //
//------------------------------------------------------------//

	struct v4l2_buffer bufferinfo;
	memset(&bufferinfo, 0, sizeof(bufferinfo));
	bufferinfo.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	bufferinfo.memory = V4L2_MEMORY_MMAP;
	bufferinfo.index = 0;
		
	if(ioctl(videofd, VIDIOC_QUERYBUF, &bufferinfo) < 0)
	{
		perror("VIDIOC_QUERYBUF");
		return -1;
	}

	void* buffer_start = mmap(NULL, bufferinfo.length, PROT_READ|PROT_WRITE, MAP_SHARED,videofd, bufferinfo.m.offset);
	
	if(buffer_start == MAP_FAILED)
	{
		perror("mmap");
		return -1;
	}

	memset(buffer_start, 0, bufferinfo.length);

//---------------------------------------------------------------//
//          	    start capturing streams                     //
//-------------------------------------------------------------//

	int type = bufferinfo.type;
	if(ioctl(videofd, VIDIOC_STREAMON, &type) < 0)
	{
		perror("VIDIOC_STREAMON");
		return -1;
	}
	
	if(ioctl(videofd, VIDIOC_QBUF, &bufferinfo) < 0)
	{
		perror("VIDIOC_QBUF");
		return -1;
	}

	if(ioctl(videofd, VIDIOC_DQBUF, &bufferinfo) < 0)
	{
		perror("VIDIOC_DQBUF");
		return -1;
	}


	if(ioctl(videofd, VIDIOC_STREAMOFF, &type) < 0)
	{
		perror("VIDIOC_STREAMOFF");
		return -1;
	}

	int jpgfile;
	jpgfile = open("/tmp/myimage.jpeg", O_WRONLY | O_CREAT, 0660);
	if(jpgfile < 0)
	{
		perror("open");
		return -1;
	}

	write(jpgfile, buffer_start, bufferinfo.length);
	
	
	close(jpgfile);
	close(videofd);
return 0;
}

	
