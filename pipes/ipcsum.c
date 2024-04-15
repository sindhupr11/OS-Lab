//SINDHU P R
//20221080

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

int main(){
	int fd[2];
	int n, i, sum=0;
	pid_t p;
	
	pipe(fd);
	p = fork();
	
	if(p > 0){		
		printf("The process ID of parent is %d", getpid());
		printf("\n");
		printf("Enter the number of elements:");
		scanf("%d", &n);
		
		write(fd[1], &n, sizeof(n));
		
		int number[n];
		printf("Enter numbers from parent to child:");
		for (i = 0; i < n; i++) {    		
      		scanf("%d", &number[i]);        		
    	}   	
    	write(fd[1], number, n*sizeof(int));
    	
    	wait(NULL);
    	
    	printf("\nParent Process\n");

    	read(fd[0], &sum, sizeof(sum));

    	printf("The sum of the numbers is %d\n", sum);    	
    } else {    
		sleep(8);
		
		printf("The process ID of child is %d", getpid());
		printf("\n");
		
		read(fd[0], &n, sizeof(n));
		int numbers[n];
		read(fd[0], numbers, n*sizeof(int));
		
		for (i = 0; i < n; i++) {   
		  sum += numbers[i]; 
		}
		printf("\n");
		
		write(fd[1], &sum, sizeof(sum));
  }
 }
 
/*

The process ID of parent is 8796
Enter the number of elements:4
Enter numbers from parent to child:1 5 4 6
The process ID of child is 8797


Parent Process
The sum of the numbers is 16

*/
