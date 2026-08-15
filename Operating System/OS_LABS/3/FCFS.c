#include <stdio.h>

int main() {
	int n;

	printf("Enter number of processes: ");
	scanf("%d", &n);

	int burst[n], waiting[n], turnaround[n];

	printf("Enter burst times:\n");
	for (int i = 0; i < n; i++) {
		printf("  P%d: ", i + 1);
		scanf("%d", &burst[i]);
	}

	waiting[0] = 0;
	for (int i = 1; i < n; i++)
		waiting[i] = waiting[i - 1] + burst[i - 1];

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
