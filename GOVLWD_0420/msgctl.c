#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MSGKEY 122445L
#define flag 00666

int main()
{
	int msgid, msgflg,ret;
	key_t key;

	key = MSGKEY;
	msgflg = flag | IPC_CREAT;

	msgid = msgget(key, msgflg);

	ret = msgctl(msgid, IPC_RMID, NULL);
	printf ("\n Visszatert: %d\n", ret);

	exit(0);
}
