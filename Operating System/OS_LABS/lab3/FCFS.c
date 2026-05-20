#include<stdio.h>
int main()
{
	int n;
	printf("Enter numbeer of processes: ");
	scanf("%d",&n);
	int burst[n],waiting[n],turnaround[n];
	printf("Enyer burst times:\n");
	for(int i=0;i<n;i++)
	{
		printf("Process P%d: ",i+1);
		scanf("%d",&burst[i]);
	}
	waiting[0]=0;
	for(int i=1;i<n;i++)
	{
		waiting[i]=waiting[i-1]+burst[i-1];
	}
	for(int i=0;i<n;i++)
	{
		turnaround[i]=waiting[i] + burst[i];
	}
	float avg_waiting =0,avg_turnaround=0;
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t\t%d\t\t%d\t\t%d\n",i+1,burst[i],waiting[i],turnaround[i]);
		avg_waiting +=waiting[i];
		avg_turnaround +=turnaround[i];
	}
	avg_waiting = avg_waiting / n;
	avg_turnaround = avg_turnaround / n;
	printf("\nAverage Waiting Time = %.2f\n", avg_waiting);
	printf("Average Turnaround Time = %.2f\n", avg_turnaround);
	return 0;
}
