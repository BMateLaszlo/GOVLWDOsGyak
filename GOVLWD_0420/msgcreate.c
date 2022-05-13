#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 122445L
#define flag 00666

struct msgbuf1 {
	long type;
	char text[300];
} sendbuf, *msgp;

int main()
{
	int msgid;
	key_t key;
	int msgflg;
	int ret, msgsz;
   	 key = MSGKEY;
	msgflg = flag | IPC_CREAT;
	msgid = msgget(key, msgflg);
 	if (msgid == -1) {
                perror("msgget Errror...");
                exit(-1);
        }
	printf("Letrejott az msgid: %d, %x\n", msgid,msgid);

	msgp = &sendbuf;
	msgp->type = 1;
 	strcpy(msgp->text,"Nev: Bodnar Mate");
	msgsz       = strlen(msgp->text) + 1;
	ret = msgsnd(msgid,(struct msgbuf *)msgp, msgsz, msgflg);

    printf("Az 1. msgsnd ezt adta vissza: %d\n", ret);

	printf("A kikuldott uzenet: %s\n", msgp->text);
	strcpy(msgp->text,"Neptun: GOVLWD");

	msgsz = strlen(msgp->text) + 1;

	ret = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);

	printf("A 2. msgsnd ezt adta vissza: %d\n", ret);

	printf("A kikuldott uzenet vegul: %s\n", msgp->text);

	exit(0);
}
