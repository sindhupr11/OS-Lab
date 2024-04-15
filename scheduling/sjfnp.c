//SINDHU P R
//20221080

#include<stdio.h>
#include<stdlib.h>

struct Process {
    int process_number;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completed;
};

void sortProcesses(struct Process *processes, int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time for each process:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i].arrival_time);
        processes[i].process_number = i + 1;
        processes[i].completed = 0;
    }
    
    printf("Enter burst time for each process:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i].burst_time);
    }

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    printf("\nProcess_ID|\tArrival-Time|\tBurst-Time|\tWait-Time|\tTurn-around-Time|\n");

    while (1) {
        int shortest = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !processes[i].completed) {
                if (shortest == -1 || processes[i].burst_time < processes[shortest].burst_time) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            int min_arrival_time = __INT_MAX__;
            for (int i = 0; i < n; i++) {
                if (!processes[i].completed && processes[i].arrival_time < min_arrival_time) {
                    min_arrival_time = processes[i].arrival_time;
                }
            }
            current_time = min_arrival_time;
            continue;
        }

        processes[shortest].waiting_time = current_time - processes[shortest].arrival_time;
        processes[shortest].turnaround_time = processes[shortest].waiting_time + processes[shortest].burst_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[shortest].process_number,
               processes[shortest].arrival_time, processes[shortest].burst_time,
               processes[shortest].waiting_time, processes[shortest].turnaround_time);

        total_waiting_time += processes[shortest].waiting_time;
        total_turnaround_time += processes[shortest].turnaround_time;
        current_time += processes[shortest].burst_time;
        processes[shortest].completed = 1;

        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            break;
        }
    }

    printf("\nAverage Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);

    return 0;
}

/*

Enter the number of processes: 4
Enter arrival time for each process:1 3 2 4
Enter burst time for each process:1  2 4 3

Process_ID|	Arrival-Time|	Burst-Time|	Wait-Time|	Turn-around-Time|
1		1		1		0		1
3		2		4		0		4
2		3		2		3		5
4		4		3		4		7

Average Waiting Time: 1.75
Average Turnaround Time: 4.25

*/
