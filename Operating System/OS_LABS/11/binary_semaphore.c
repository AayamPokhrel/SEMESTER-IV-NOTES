#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t binary_sem;
int shared_resource = 0;

void *worker(void *arg) {
	int id = *(int *)arg;

	printf("[Thread %d] Waiting to enter critical section...\n", id);
	sem_wait(&binary_sem);

	printf("[Thread %d] Entered critical section\n", id);
	shared_resource++;
	printf("[Thread %d] shared_resource = %d\n", id, shared_resource);
	usleep(500000);
	printf("[Thread %d] Leaving critical section\n", id);

	sem_post(&binary_sem);
	return NULL;
}

int main() {
	pthread_t threads[4];
	int ids[4];

	sem_init(&binary_sem, 0, 1);

	printf("Binary Semaphore Demo (4 threads)\n\n");

	for (int i = 0; i < 4; i++) {
		ids[i] = i + 1;
		pthread_create(&threads[i], NULL, worker, &ids[i]);
	}

	for (int i = 0; i < 4; i++)
		pthread_join(threads[i], NULL);

	sem_destroy(&binary_sem);

	printf("\nFinal shared_resource = %d\n", shared_resource);

	return 0;
}
