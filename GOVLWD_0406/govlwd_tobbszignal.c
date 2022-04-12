#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void do_nothing();
void handleSignals(int sig);

int main() {

   printf("PID: %d\n", getpid());

   signal(SIGINT, handleSignals);
   signal(SIGQUIT, handleSignals);
   signal(SIGALRM, do_nothing);
   unsigned masodperc=10;

   while (1) {
       alarm(masodperc);
       printf("Kérem várjon...\n");
       pause();
   }
   return 0;
}

void do_nothing(){ ;}
void handleSignals(int sig) {
  if (sig == SIGQUIT) {
     printf("SIGQUIT-et adott meg  -  %d\n", sig);
  }

  else if (sig == SIGINT) {
     printf(" SIGINT-et adott meg -  %d\n", sig);
     signal(SIGINT, SIG_DFL);
  }
}
