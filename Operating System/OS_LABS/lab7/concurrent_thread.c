#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
	for (int i = 1; i <= 5; i++) {
		printf("[Thread] Count: %d\n", i);
		usleep(300000);
	}
	printf("[Thread] Finished.\n");
	return NULL;
}

int main() {
	pthread_t tid;

	printf("[Main] Creating thread...\n");
	pthread_create(&tid, NULL, thread_func, NULL);

	for (int i = 1; i <= 5; i++) {
		printf("[Main] Count: %d\n", i);
		usleep(500000);
	}

	pthread_join(tid, NULL);
	printf("[Main] Thread joined. Done.\n");

	return 0;
}
