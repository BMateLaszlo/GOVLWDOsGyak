#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 44221L
#define flag 00666
int main()
{
	int shmid;
	key_t key;
	int size=300;
	int shmflg;
	struct vmi {
		int  hossz;
		char szoveg[300-sizeof(int)];
	} *segm;
	key = SHMKEY;
	shmflg = 0;

	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("Az shmget system-call sikertelen!\n");
	    exit(-1);
	}

	shmflg = flag | SHM_RND;
	segm = (struct vmi *)shmat(shmid, NULL, shmflg);
	if (segm == (void *)-1) {
		perror("Az attach sikertelen!\n");
		exit(-1);
	}
	if (strlen(segm->szoveg) > 0) 
		printf("\n A regi szoveg: %s (%d hosszon)",segm->szoveg,segm->hossz);
 
	printf("\nKerem adjon meg egy uj szoveget!\n");
	gets(segm->szoveg);
	printf("Az uj szoveg: %s\n",segm->szoveg);
	segm->hossz=strlen(segm->szoveg);
	shmdt(segm);
exit(0);
}
