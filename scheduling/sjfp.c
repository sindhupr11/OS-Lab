//SINDHU P R
//20221080

#include<stdio.h>

struct process{
    int WT,AT,BT,TAT;
};

struct process a[10];

int main(){
    int n,temp[10];
    int count=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("\n");
    
    int at[n], bt[n];
    
    printf("Enter the arrival time of the processes: ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].AT);
		at[i] = a[i].AT;
	}
	
	printf("Enter the burst time of the processes: ");
	for(int i=0;i<n;i++){		
		scanf("%d", &a[i].BT);
		temp[i]=a[i].BT;
		bt[i]= a[i].BT;
	}

    a[9].BT=10000;

    for(t=0;count!=n;t++){
        short_P=9;
        for(int i=0;i<n;i++){
            if(a[i].BT<a[short_P].BT && (a[i].AT<=t && a[i].BT>0)){
                short_P=i;
                }            
        }
        
        a[short_P].BT=a[short_P].BT-1;        

        if(a[short_P].BT==0){
            count++;
            a[short_P].WT=t+1-a[short_P].AT-temp[short_P];
            a[short_P].TAT=t+1-a[short_P].AT;

            total_WT=total_WT+a[short_P].WT;
            total_TAT=total_TAT+a[short_P].TAT;
        }           
    }
    
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
    printf("process_Id|\tArrival-Time|\tBurst-Time|\tWait-Time|\tTurn-Around-Time|\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],a[i].WT,a[i].TAT);
    }
    printf("Avg waiting time of the process is %f\n",Avg_WT);
    printf("Avg turn around time of the process %f\n",Avg_TAT);
    
}

/*

Enter number of processes: 4

Enter the arrival time of the processes: 1 2 3 4
Enter the burst time of the processes: 2 1 4 5
process_Id|	Arrival-Time|	Burst-Time|	Wait-Time|	Turn-Around-Time|
1		1		2		0		2
2		2		1		1		2
3		3		4		1		5
4		4		5		4		9
Avg waiting time of the process is 1.500000
Avg turn around time of the process 4.500000

*/
