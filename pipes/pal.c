//SINDHU P R
//20221080

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  int fd1[2], fd2[2], i, num_palindromes = 0, num_strings;
  char strings[100][100], palindromes[100][100];  
  
  pipe(fd1); pipe(fd2);
  pid_t p = fork();
  
  if(p > 0){		
		printf("The process ID of parent is %d", getpid());
		printf("\n");
		printf("Parent Process - Enter the number of strings:");
		scanf("%d", &num_strings);
		
		write(fd1[1], &num_strings, sizeof(num_strings));
		
		int number[num_strings];
		printf("Parent Process - Enter stringss from parent to child:");
		for (i = 0; i < num_strings; i++) {    		
      		scanf("%s", strings[i]);     		      		
    	}
    	
    	write(fd1[1], &strings, 100*100);    	
    	
    	wait(NULL);
    	
    	printf("Parent Process - The palindromes are:");
    	printf("\n");
    	
    	read(fd2[0], &num_palindromes, sizeof(num_palindromes));
    	read(fd2[0], palindromes, 100*100); 
    	
    	for (i = 0; i < num_palindromes; i++) {		    			
			printf("%s\n", palindromes[i]);
		}
    	
    } else {    
		sleep(12);
		
		printf("The process ID of child is %d", getpid());
		printf("\n");
		
		read(fd1[0], &num_strings, sizeof(num_strings));
		
		char strings[100][100];
		read(fd1[0], &strings, 100*100);
		
		 for (i = 0; i < num_strings; i++) {
		        int j = 0;
		        int k = strlen(strings[i]) - 1;
		        int is_palindrome = 1; 

		        while (j < k) {
		            if (strings[i][j] != strings[i][k]) {
		                is_palindrome = 0; 
		                break;
		            }
		            j++;
		            k--;
		        }
		        if (is_palindrome) {		   
		            strcpy(palindromes[num_palindromes], strings[i]);
		            num_palindromes++; 
		        }
		    }			
		write(fd2[1], &num_palindromes, sizeof(num_palindromes));	
		write(fd2[1], &palindromes, 100*100);	  
  }
 }
 
/*

The process ID of parent is 8832
Parent Process - Enter the number of strings:3
Parent Process - Enter stringss from parent to child:sas gtg jjh
The process ID of child is 8833
Parent Process - The palindromes are:
sas
gtg

*/
