#include <stdio.h>
#include <pthread.h>

int shared_data = 0;
pthread_mutex_t lock;

void *increment(void *arg) {
	int id = *(int *)arg;
	for (int i = 0; i < 5; i++) {
		pthread_mutex_lock(&lock);
		shared_data++;
		printf("[Thread %d] Incremented to %d\n", id, shared_data);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main() {
	pthread_t t1, t2;
	int id1 = 1, id2 = 2;

	pthread_mutex_init(&lock, NULL);

	printf("Initial value = %d\n\n", shared_data);

	pthread_create(&t1, NULL, increment, &id1);
	pthread_create(&t2, NULL, increment, &id2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("\nFinal value = %d (expected 10)\n", shared_data);

	pthread_mutex_destroy(&lock);

	return 0;
}
