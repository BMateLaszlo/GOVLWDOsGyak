#include <stdlib.h>
#include <stdio.h>
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
        perror(" SEMGET HIBA ...");
        return -1;
    } else {
        printf("A Semid: %d\n", sem_id);
    }
    int command = SETVAL;
    union semun argument;
    argument.val = 0;



    for (int i = 0; i < num_of_semaphs; i++) {
        int status = semctl(sem_id, i, command, argument);
        printf("%d. - set %d, semval: %d\n",i+1, argument.val, status);
    }
  return 0;
}
