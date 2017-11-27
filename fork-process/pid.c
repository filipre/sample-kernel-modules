#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = -42;
	char cat_proc[1024];
	
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork\n");
			return EXIT_FAILURE;
			
		case 0:
			// child process
			sleep(1); // don't die immediately
			exit(0);
		
		default:
			break;
	}
	
	// father process
	printf("Child process PID: %d\n", pid);
	snprintf(cat_proc, sizeof(cat_proc), "cat /proc/%d/maps", pid);
	printf("Result of \"%s\"\n", cat_proc);
	system (cat_proc);
	
	return EXIT_SUCCESS;
}
