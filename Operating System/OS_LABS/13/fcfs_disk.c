#include <stdio.h>
#include <stdlib.h>

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

	int total_seek = 0;
	int current = head;

	printf("\nHead movement: %d", current);
	for (int i = 0; i < n; i++) {
		int seek = abs(queue[i] - current);
		total_seek += seek;
		current = queue[i];
		printf(" -> %d", current);
	}

	printf("\n\nTotal Seek Count = %d\n", total_seek);

	return 0;
}
