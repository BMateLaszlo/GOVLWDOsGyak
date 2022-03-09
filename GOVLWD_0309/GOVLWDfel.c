#include <sys/wait.h>

űint main(void)
{
	int status;

	if ( (status = system("date")) <0)
	perror("system() error");

	
	if (WIFEXTITED(status))
	printf("Normális befejezés,
	visszaadott érték = %d\n",
	WEXITSTATUS(status));

	if ( ( status = system("username")) < 0)
		perror("system() error");

	if (WIFEXITED(status))
		printf("Normális befejeződés, visszaadott érték = %d\n",
	WEXITSTATUS(status));


	return (0);
}

