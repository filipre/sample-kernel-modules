#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = -42;
	int wstatus = -42;
	int ret = -1;
	
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork\n");
			return EXIT_FAILURE;
			
		case 0:
			sleep(5);
			printf("Noooooo!\n");
			exit(0);
		
		default:
			printf("I am your father, %d\n", pid);
			break;
	}
	
	ret = waitpid(pid, &wstatus, 0); // waits until process "pid" returns
	if (ret == -1)
	{
		perror("wait pid\n");
		return EXIT_FAILURE;
	}
	
	printf("Child exit status: %d\n", WEXITSTATUS(wstatus));
	
	return EXIT_SUCCESS;
}
