#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUM_OF_SEMS 3

int main(void) {
    key_t key = ftok("semset.c", (int)'S');
    int flag = 00666 | IPC_CREAT;
    int num_of_semaphs = NUM_OF_SEMS;
    int sem_id = semget(key, num_of_semaphs, flag);

    if (sem_id < 0) {
        perror("SEMGET HIBA ...");
        return -1;
    } else {
        printf("A Semid: %d\n", sem_id);
    }
    struct sembuf sem_op_buf;
    sem_op_buf.sem_op = 1;
    sem_op_buf.sem_flg = 0666;
    printf("Semaph. number: ");
    scanf("%hu", &sem_op_buf.sem_num);

    int rtn = semop(sem_id, &sem_op_buf, 1);
    printf("up rtn: %d\n", rtn);


    return 0;
}
