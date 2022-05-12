#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUM_OF_SEMS 3

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct semaphinfo *__buf;
};

int main(void) {
    key_t key = ftok("semset.c", (int)'S');
    int flag = 00666 | IPC_CREAT;
    int num_of_semaphs = NUM_OF_SEMS;
    int sem_id = semget(key, num_of_semaphs, flag);

    if (sem_id < 0) {
        perror(" SMGET HIBA....");
    return -1;
    } else {
        printf("A Semid: %d\n", sem_id);
    }

    int command = IPC_RMID;
    union semun argument;

    int status = semctl(sem_id, 0, command, argument);

    printf("Semaphore kill...\n");

    return 0;
}
