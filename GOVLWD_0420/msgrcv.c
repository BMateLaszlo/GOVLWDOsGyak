#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define flag 00666
#define MSGKEY 12245L

struct msgbuf1 {
	long type;
	char text[300];
} recievebuf, *msgp;

struct msqid_ds ds, *buf;


int main()
{
	int msgid;
	key_t key;
	int type, msgflg;
	int ret, msgsz;

	key = MSGKEY;
	msgflg = flag | IPC_CREAT | MSG_NOERROR;

	msgid = msgget(key, msgflg);
 	if (msgid == -1) {
                perror("Nem sikerult...");
                exit(-1);
        }
	printf("Az msgid-je: %d\n",msgid);

	msgp = &recievebuf;
	buf = &ds;
	msgsz = 32;
	type = 0;

	ret = msgctl(msgid, IPC_STAT, buf);
	printf("Az uzenetek szama az uzenetsorban: %ld\n", buf->msg_qnum);

	while (buf->msg_qnum) {
		ret = msgrcv(msgid,(struct msgbuf *)msgp, msgsz, type, msgflg);
		printf("Visszaadva: %d, A kapott uzenet: %s\n",ret, msgp->text);
		ret = msgctl(msgid, IPC_STAT, buf);

	}

	exit(0);
}
