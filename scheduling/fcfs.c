//SINDHU P R
//20221080

#include <stdio.h>

int main(){
	int n,tat_sum, wt_sum, tat[n], wt[n], bt[n], at[n],ct = 0; 
	float avg_tat, avg_wt;	
	
	printf("Enter the number of processes: ");
	scanf("%d",&n);	
	
	printf("Enter the arrival time of processes:");
	for(int i = 0; i < n ; i++)	
		scanf("%d",&at[i]);	
		
	printf("Enter the burst time of processes:");
	for(int i = 0; i < n ; i++)	
		scanf("%d",&bt[i]);	 
		
	for(int i = 0; i < n ; i++){
		while(at[i]>ct)	
			ct++;		
		wt[i] = ct - at[i];		
		if(wt[i]<0)	
			wt[i] = 0;		
		ct += bt[i];}
			
	for(int i = 0; i < n ; i++) 
		tat[i] = wt[i] + bt[i];
		
	for(int i = 0; i < n ; i++){
		tat_sum += tat[i];
		wt_sum += wt[i];}
			
	avg_tat = (float)tat_sum/(float)n;
	avg_wt = (float)wt_sum/(float)n;
		
	printf("|Process no\t|Arrival Time\t|Burst Time\t|Wait Time\t|Turn Around Time\t|");
	for(int i = 0; i < n ; i++)	
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",i,at[i],bt[i],wt[i],tat[i]);
		
	printf("\nAverage wait Time: %f", avg_wt);
	printf("\nAverage Turn Around Time: %f\n", avg_tat);
}

/*

Enter the number of processes: 4
Enter the arrival time of processes:1 4 3 2
Enter the burst time of processes:1 3 5 3
|Process no	|Arrival Time	|Burst Time	|Wait Time	|Turn Around Time	|
0		1		1		0		1		
1		4		3		0		3		
2		3		5		4		9		
3		2		3		10		13		
Average wait Time: 3.500000
Average Turn Around Time: 6.500000

*/

