#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){

char buffer[128];
int p[2], pid;
if (pipe(p) < 0){
	perror("Pipe hiba");
	exit(2);
}
pid = fork();
if (pid < 0)
	exit(1);

if (pid == 0){
	write(p[1], "Bodnar Mate Laszlo GOVLWD", 128);
	printf("Child: File irasa sikeres!\n");
}

else if (pid > 0 ){
	wait(NULL);
	read(p[0], buffer, 128);
	printf("Uzenet: %s\n", buffer);
}

return 0;
}
