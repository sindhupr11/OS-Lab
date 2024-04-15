//SINDHU P R
//20221080

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	int fd[2];
	int n, i, sum=0;
	pid_t p;
	
	pipe(fd);
	p = fork();
	
	if(p > 0){		
		close(fd[0]);
		printf("The process ID of parent is %d", getpid());
		printf("\n");
		printf("Enter the number of elements:");
		scanf("%d", &n);
		
		write(fd[1], &n, sizeof(n));
		
		printf("Enter numbers from parent to child:");
		for (i = 0; i < n; i++) {
      		int number;     		
      		scanf("%d", &number);
      		write(fd[1], &number, sizeof(number));
    	}    	
    	close(fd[1]);
    	
    	wait(NULL);    	
    } else {    
		sleep(6);
		close(fd[1]);
		printf("The process ID of child is %d", getpid());
		printf("\n");
		read(fd[0], &n, sizeof(n));

		printf("The numbers from parent are:");
		
		int numbers[n];
		for (i = 0; i < n; i++) {
		  read(fd[0], &numbers[i], sizeof(numbers[i]));    
		  printf("%d ", numbers[i]);  
		}
		printf("\n");
		
		close(fd[0]);
  }
 }
 
/*
 
The process ID of parent is 8785
Enter the number of elements:4
Enter numbers from parent to child:1 2 5 4
The process ID of child is 8786
The numbers from parent are:1 2 5 4 

*/
