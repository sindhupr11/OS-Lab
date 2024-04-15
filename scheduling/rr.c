//SINDHU P R
//20221080

#include <stdio.h>

void sort_proc(int process[][3], int len) {
	int i, j, temp;

	for (i = 0; i < len - 1; ++i) {
		for (j = 0; j < len - i - 1; ++j) {
			if (process[j][1] > process[j + 1][1]) {
				temp = process[j][0];
				process[j][0] = process[j + 1][0];
				process[j + 1][0] = temp;

				temp = process[j][1];
				process[j][1] = process[j + 1][1];
				process[j + 1][1] = temp;

				temp = process[j][2];
				process[j][2] = process[j + 1][2];
				process[j + 1][2] = temp;
			}
		}
	}
}

int main(void){	
	int process_count, i, current_process, current_time, completed_processes, time_quanta;
	float avg_wt, avg_tat; 

	current_time = completed_processes = 0;

	printf("Enter the number of processes: ");
	scanf("%d", &process_count);
	
	int process[process_count][3], waiting_time[process_count], turnaround_time[process_count], completion_time[process_count], burst_time_copy[process_count]; 
	
	printf("time quantum: ");
	scanf("%d", &time_quanta);

	 printf("Enter arrival time for each process:");
	for (i = 0; i < process_count; ++i) {
		process[i][0] = i + 1;
		scanf("%d", &process[i][1]);
	}
	
	printf("Enter burst time for each process:");
	for (i = 0; i < process_count; ++i) {
		scanf("%d", &process[i][2]);
	}
	
	sort_proc(process, process_count);

	for (i = 0; i < process_count; ++i)
		burst_time_copy[i] = process[i][2];

	for (i = 0; i < process_count; ++i)
		waiting_time[i] = 0;

	current_time = process[i][1];
	for (i = 0; i < process_count; ++i)
		if (current_time > process[i][1])
			current_time = process[i][1];

	current_process = 0;
	while (completed_processes < process_count) {

		if (burst_time_copy[current_process] <= 0) {

			current_process = (current_process + 1) % process_count;
			continue;
		}		

		if (burst_time_copy[current_process] < time_quanta)
			burst_time_copy[current_process] = 0;
		else
			burst_time_copy[current_process] -= time_quanta;
		
		current_time += time_quanta;

		for (i = 0; i < process_count ; ++i)
			if ((i != current_process) && (process[i][1] < current_time) && (burst_time_copy[i] > 0))
				waiting_time[i] += time_quanta;

		if (burst_time_copy[current_process] == 0) {

			completion_time[current_process] = current_time;

			turnaround_time[current_process] = completion_time[current_process] - process[current_process][1];

			completed_processes++;
		}

		current_process = (current_process + 1) % process_count;
	}

	for (i = 0; i < process_count; ++i) {
		avg_wt += waiting_time[i];
		avg_tat += turnaround_time[i];
	}
	
	
	printf("process_Id|\tArrival-Time|\tBurst-Time|\tWait-Time|\tTurn-Around-Time|\n");
    for(int i=0;i<process_count;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i][0], process[i][1], process[i][2], waiting_time[i], turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    
    return 0;
}
    
/*
 
 Enter the number of processes: 4
time quantum: 5
Enter arrival time for each process:4 2 4 3
Enter burst time for each process:2 4 5 3
process_Id|	Arrival-Time|	Burst-Time|	Wait-Time|	Turn-Around-Time|
2		2		4		0		5
4		3		3		5		9
1		4		2		10		13
3		4		5		15		18

Average Waiting Time: 30.00
Average Turnaround Time: 11.25

*/   
	
