#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, head;

	printf("Enter size of disk queue: ");
	scanf("%d", &n);

	int queue[n], visited[n];
	printf("Enter the disk queue:\n");
	for (int i = 0; i < n; i++) {
		printf("  Request %d: ", i + 1);
		scanf("%d", &queue[i]);
		visited[i] = 0;
	}

	printf("Enter initial head position: ");
	scanf("%d", &head);

	int total_seek = 0;
	int current = head;

	printf("\nHead movement: %d", current);

	for (int count = 0; count < n; count++) {
		int min_dist = __INT_MAX__;
		int idx = -1;

		for (int i = 0; i < n; i++) {
			if (!visited[i] && abs(queue[i] - current) < min_dist) {
				min_dist = abs(queue[i] - current);
				idx = i;
			}
		}

		visited[idx] = 1;
		total_seek += min_dist;
		current = queue[idx];
		printf(" -> %d", current);
	}

	printf("\n\nTotal Seek Count = %d\n", total_seek);

	return 0;
}
