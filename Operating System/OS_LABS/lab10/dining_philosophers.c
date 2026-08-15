#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t chopstick[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
	int id = *(int *)arg;
	int left = id;
	int right = (id + 1) % NUM_PHILOSOPHERS;

	for (int i = 0; i < 3; i++) {
		printf("Philosopher %d is thinking...\n", id);
		usleep(100000);

		sem_wait(&chopstick[left]);
		sem_wait(&chopstick[right]);

		printf("Philosopher %d picks up chopstick %d and %d -> eating\n", id, left, right);
		usleep(200000);

		sem_post(&chopstick[left]);
		sem_post(&chopstick[right]);

		printf("Philosopher %d puts down chopstick %d and %d\n", id, left, right);
	}

	return NULL;
}

int main() {
	pthread_t threads[NUM_PHILOSOPHERS];
	int ids[NUM_PHILOSOPHERS];

	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
		sem_init(&chopstick[i], 0, 1);

	printf("Dining Philosophers Problem (%d philosophers, %d chopsticks)\n\n",
		NUM_PHILOSOPHERS, NUM_PHILOSOPHERS);

	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		ids[i] = i;
		pthread_create(&threads[i], NULL, philosopher, &ids[i]);
	}

	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
		pthread_join(threads[i], NULL);

	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
		sem_destroy(&chopstick[i]);

	printf("\nAll philosophers finished dining.\n");

	return 0;
}
