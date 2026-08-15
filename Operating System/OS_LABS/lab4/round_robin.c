#include <stdio.h>

int main() {
	int n, quantum;

	printf("Enter number of processes: ");
	scanf("%d", &n);

	int burst[n], remaining[n], waiting[n], turnaround[n];

	printf("Enter burst times:\n");
	for (int i = 0; i < n; i++) {
		printf("  P%d: ", i + 1);
		scanf("%d", &burst[i]);
		remaining[i] = burst[i];
	}

	printf("Enter time quantum: ");
	scanf("%d", &quantum);

	int time = 0, done = 0;

	for (int i = 0; i < n; i++) {
		waiting[i] = 0;
		turnaround[i] = 0;
	}

	printf("\nExecution Order:\n");

	while (done < n) {
		for (int i = 0; i < n; i++) {
			if (remaining[i] <= 0)
				continue;

			int slice = remaining[i] < quantum ? remaining[i] : quantum;
			printf("  [t=%d] P%d runs for %d unit(s)\n", time, i + 1, slice);
			time += slice;
			remaining[i] -= slice;

			if (remaining[i] == 0) {
				turnaround[i] = time;
				waiting[i] = turnaround[i] - burst[i];
				done++;
			}
		}
	}

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
