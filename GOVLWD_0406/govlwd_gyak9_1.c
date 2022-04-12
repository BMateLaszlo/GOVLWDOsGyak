#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h> 
#include <unistd.h>

void signalHandler(int);

int main(){
	pid_t pid = getpid();
	printf("PID: %d\n", (int)pid);
	printf("Signal kezelo atvetele: %d\n", signal(SIGALRM, signalHandler));

	printf("Kérem Várjon...\n");
	pause();

	printf("Nincs blokkolás...kérem várjon\n");
	return 0;
}
void signalHandler(int sig){
	printf("GOVLWD\n");
}
