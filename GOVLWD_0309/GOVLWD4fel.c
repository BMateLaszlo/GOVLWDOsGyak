#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("Hello child\n");
		execlp("ls", "ls", (char *) NULL);
	}
	else
	{
		printf("Hello parent\n");
	}
	return 0;
}
