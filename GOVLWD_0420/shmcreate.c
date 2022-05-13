#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define flag 00666
#define SHMKEY 44221L

int main()
{
	int shmid;
	key_t key;
	int size = 250;
	int shmflg;
	key = SHMKEY;
	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	   printf("Nem letezik meg a szegmens... Keszitsuk el!\n");
	   shmflg = flag | IPC_CREAT;
	   if ((shmid=shmget(key, size, shmflg)) < 0) {
	      perror("Skertelem az shmget system call!\n");
	      exit(-1);
	   }
	} else printf("Van mar ilyen shm szegmens!\n");

	printf("\nAz shm szegmens azonositoja %d: \n", shmid);

	exit(0);
}
