#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int man ()
{

	pid_t pid=fork();
	if(pid<0){
		printf("Fork hiba");
		exit(-1);
	}

	else if (pid==0){
	execl("./child","child", (char *) NULL;
	}

	int status;
	waitpid(pid,&status,0);

	if(WIFEXITED(status)){
	int exitStatus=WEXITSTATUS(status);
	printf("A kilepes erteke: %d\n" exitStatus);
	}
	
	return 0;
}




