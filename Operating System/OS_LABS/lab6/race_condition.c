#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *increment(void *arg) {
	for (int i = 0; i < 1000000; i++)
		counter++;
	return NULL;
}

int main() {
	pthread_t t1, t2;

	printf("Initial counter = %d\n", counter);

	pthread_create(&t1, NULL, increment, NULL);
	pthread_create(&t2, NULL, increment, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Expected counter = %d\n", 2000000);
	printf("Actual counter   = %d\n", counter);

	if (counter != 2000000)
		printf("Race condition detected! Value differs from expected.\n");
	else
		printf("No race condition this time (try running again).\n");

	return 0;
}
