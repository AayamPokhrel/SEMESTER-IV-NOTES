#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int main() {
	int n, head, disk_size;

	printf("Enter size of disk queue: ");
	scanf("%d", &n);

	int queue[n];
	printf("Enter the disk queue:\n");
	for (int i = 0; i < n; i++) {
		printf("  Request %d: ", i + 1);
		scanf("%d", &queue[i]);
	}

	printf("Enter disk size (last position): ");
	scanf("%d", &disk_size);

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

	if (current != disk_size) {
		total_seek += abs(disk_size - current);
		current = disk_size;
		printf(" -> %d", current);
	}

	total_seek += disk_size;
	current = 0;
	printf(" -> %d", current);

	for (int i = 0; i < idx; i++) {
		total_seek += abs(queue[i] - current);
		current = queue[i];
		printf(" -> %d", current);
	}

	printf("\n\nTotal Seek Count = %d\n", total_seek);

	return 0;
}
