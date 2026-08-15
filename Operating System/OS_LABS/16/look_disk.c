#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int main() {
	int n, head;

	printf("Enter size of disk queue: ");
	scanf("%d", &n);

	int queue[n];
	printf("Enter the disk queue:\n");
	for (int i = 0; i < n; i++) {
		printf("  Request %d: ", i + 1);
		scanf("%d", &queue[i]);
	}

	printf("Enter initial head position: ");
	scanf("%d", &head);

	qsort(queue, n, sizeof(int), compare);

	int total_seek = 0;
	int current = head;
	int idx = 0;

	while (idx < n && queue[idx] < head)
		idx++;

	printf("\nHead movement: %d", current);

	for (int i = idx; i < n; i++) {
		total_seek += abs(queue[i] - current);
		current = queue[i];
		printf(" -> %d", current);
	}

	for (int i = idx - 1; i >= 0; i--) {
		total_seek += abs(queue[i] - current);
		current = queue[i];
		printf(" -> %d", current);
	}

	printf("\n\nTotal Seek Count = %d\n", total_seek);

	return 0;
}
