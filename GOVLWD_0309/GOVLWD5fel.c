#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("child\n");
		exit(0);
	}
	else{
		printf("parent\n");
	}

	if(fork())
	{
		printf("c\n");
		abort();
	}else{
		printf("p\n");
	}

/*	double szam;
	if(fork())
	{
		szam=1/0;
	}
*/
	return 0;
}
