#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 44221L

int main()
{
	int shmid;
	key_t key;
	int size = 300;
	int shmflg;
	struct shmid_ds shmid_ds, *buf;
	buf = &shmid_ds;
	int rtn;
	int cmd;
	key = SHMKEY;
	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("Sikeretelen az shmget system call!!\n");
	    exit(-1);
	}

	do
	{
		printf("\nAdd meg a parancs szamat:\n");
		printf("0. IPC_STAT (statusz)\n");
		printf("1. IPC_RMID (torles)\n> ");
		scanf("%d",&cmd);
	} while (cmd < 0 || cmd > 1);

	switch (cmd)
	{
	    case 0:
		rtn = shmctl(shmid, IPC_STAT, buf);
		printf("A szegmens merete: %ld\n",buf->shm_segsz);
		printf("Az utolso shmop processz pid-je: %d\n",buf->shm_lpid);
		break;
	    case 1:
		rtn = shmctl(shmid, IPC_RMID, NULL);
		printf("A szegmens torolve... Hibakod: %d\n", rtn);
	}

	exit(0);

}
