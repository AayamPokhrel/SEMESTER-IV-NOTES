#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		printf("Fork failed!\n");
		return 1;
	}

	if (pid == 0) {
		printf("Child Process:\n");
		printf("  Child PID  = %d\n", getpid());
		printf("  Parent PID = %d\n", getppid());
	} else {
		wait(NULL);
		printf("Parent Process:\n");
		printf("  Parent PID = %d\n", getpid());
		printf("  Child PID  = %d\n", pid);
	}

	return 0;
}
