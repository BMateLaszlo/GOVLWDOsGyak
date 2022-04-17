#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main(){
char buffer[128];
int pid, file;
char in[] = "Bodnar Mate Laszlo";
char * fifo = "/govlwd";
mkfifo(fifo, 0666);

pid = fork();
if (pid < 0)
	exit(1);

if (pid == 0){
	file = open(fifo, O_WRONLY);
	write(file, input, strlen(input)+1);
	printf("Child: File irasa sikeres!\n");
}

else if (pid > 0 ){
	file = open(fifo, O_RDONLY);
	read(file, buffer, strlen(input)+1);
	printf("Parent: kapott: %s\n", buffer);
	close(file);
}

return 0;
}
