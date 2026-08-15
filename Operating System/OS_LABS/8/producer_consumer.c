#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define TOTAL_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
	for (int i = 1; i <= TOTAL_ITEMS; i++) {
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);

		buffer[in] = i;
		printf("[Producer] Produced item %d at buffer[%d]\n", i, in);
		in = (in + 1) % BUFFER_SIZE;

		pthread_mutex_unlock(&mutex);
		sem_post(&full);

		usleep(100000);
	}
	return NULL;
}

void *consumer(void *arg) {
	for (int i = 1; i <= TOTAL_ITEMS; i++) {
		sem_wait(&full);
		pthread_mutex_lock(&mutex);

		int item = buffer[out];
		printf("[Consumer] Consumed item %d from buffer[%d]\n", item, out);
		out = (out + 1) % BUFFER_SIZE;

		pthread_mutex_unlock(&mutex);
		sem_post(&empty);

		usleep(200000);
	}
	return NULL;
}

int main() {
	pthread_t prod, cons;

	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	pthread_mutex_init(&mutex, NULL);

	printf("Buffer size: %d | Total items: %d\n\n", BUFFER_SIZE, TOTAL_ITEMS);

	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);

	pthread_join(prod, NULL);
	pthread_join(cons, NULL);

	sem_destroy(&empty);
	sem_destroy(&full);
	pthread_mutex_destroy(&mutex);

	printf("\nAll items produced and consumed.\n");

	return 0;
}
