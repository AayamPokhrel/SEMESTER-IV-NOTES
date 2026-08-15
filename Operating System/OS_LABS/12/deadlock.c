#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex_a, mutex_b;

void *thread1_func(void *arg) {
	printf("[Thread 1] Locking mutex_a...\n");
	pthread_mutex_lock(&mutex_a);
	printf("[Thread 1] Locked mutex_a\n");

	usleep(100000);

	printf("[Thread 1] Trying to lock mutex_b...\n");
	pthread_mutex_lock(&mutex_b);
	printf("[Thread 1] Locked mutex_b\n");

	pthread_mutex_unlock(&mutex_b);
	pthread_mutex_unlock(&mutex_a);
	return NULL;
}

void *thread2_func(void *arg) {
	printf("[Thread 2] Locking mutex_b...\n");
	pthread_mutex_lock(&mutex_b);
	printf("[Thread 2] Locked mutex_b\n");

	usleep(100000);

	printf("[Thread 2] Trying to lock mutex_a...\n");
	pthread_mutex_lock(&mutex_a);
	printf("[Thread 2] Locked mutex_a\n");

	pthread_mutex_unlock(&mutex_a);
	pthread_mutex_unlock(&mutex_b);
	return NULL;
}

int main() {
	pthread_t t1, t2;

	pthread_mutex_init(&mutex_a, NULL);
	pthread_mutex_init(&mutex_b, NULL);

	printf("Deadlock Demonstration\n");
	printf("Thread 1 locks A then B, Thread 2 locks B then A\n\n");

	pthread_create(&t1, NULL, thread1_func, NULL);
	pthread_create(&t2, NULL, thread2_func, NULL);

	sleep(3);

	printf("\nProgram hung for 3 seconds - deadlock occurred!\n");
	printf("Thread 1 holds mutex_a, waits for mutex_b\n");
	printf("Thread 2 holds mutex_b, waits for mutex_a\n");
	printf("Terminating.\n");

	return 0;
}
