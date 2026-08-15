#include <stdio.h>

int main() {
	int n;

	printf("Enter number of processes: ");
	scanf("%d", &n);

	int burst[n], waiting[n], turnaround[n], order[n];

	printf("Enter burst times:\n");
	for (int i = 0; i < n; i++) {
		printf("  P%d: ", i + 1);
		scanf("%d", &burst[i]);
		order[i] = i;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (burst[order[j]] < burst[order[i]]) {
				int temp = order[i];
				order[i] = order[j];
				order[j] = temp;
			}
		}
	}

	printf("\nExecution order (shortest first):\n");
	for (int i = 0; i < n; i++)
		printf("  P%d (burst=%d)\n", order[i] + 1, burst[order[i]]);

	waiting[order[0]] = 0;
	for (int i = 1; i < n; i++)
		waiting[order[i]] = waiting[order[i - 1]] + burst[order[i - 1]];

	for (int i = 0; i < n; i++)
		turnaround[i] = waiting[i] + burst[i];

	float total_wt = 0, total_tat = 0;

	printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
	for (int i = 0; i < n; i++) {
		printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
		total_wt += waiting[i];
		total_tat += turnaround[i];
	}

	printf("\nAverage Waiting Time    = %.2f\n", total_wt / n);
	printf("Average Turnaround Time = %.2f\n", total_tat / n);

	return 0;
}
