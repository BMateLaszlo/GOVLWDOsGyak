#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    	int fd, ret;
    	char buf[64];
	buf[0]=0;

    fd = open("govlwd.txt", O_RDWR);
    if (fd == -1) {
        perror("open() hiba!");
        exit(-1);
    }

    	ret = read(fd, buf, 64);
    	printf("read() olvasott %d byte-ot, ami a kovetkezo: %s\n",ret,buf);
	strcpy(buf,"GOVLWD");
    	
	ret=lseek(fd, 0, SEEK_SET);
    	printf("lseek() mondja: %d\n", ret);
	
	ret = write(fd, buf, 6);
	printf("write() mondja: %d\n", ret);


 
    	close(fd);
	return 0;
}
