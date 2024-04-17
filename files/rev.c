//SINDHU P R
//20221080

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main( int argc,char *argv[] )
{
    char buf;
    int src,dest,n;
    if(argc!=3)
    {
        write(STDOUT_FILENO,"./a.out <sourcefile> <destination file>\n",50);   
        exit(1);
    }
    else
    {
         src=open(argv[1],O_RDONLY);
         if(src==-1)
         {
            perror("Source File Error");
            exit(0);
         }
         else
         {
            dest=open(argv[2],O_WRONLY | O_CREAT | O_EXCL, 00644);
            if(dest==-1)
            {
                perror("Destinantion File Error");
                exit(0);
            }
            else
            {
       		int size = lseek(src,0,SEEK_END);
       		
                for(int i = size; i>=0 ; i--){
                
               		lseek(src, (off_t) i, SEEK_SET);
               		read(src, &buf, 1);
                    write(dest, &buf, 1);
 		}
                
                
                write(STDOUT_FILENO,"Files Copied\n",15);    
                close(src);
                close(dest);
            }
        }
    }
    return 0;
}	

/*

	BEFORE:

a.txt:

heyy 
helloo
hiii

b.txt:

//blank

	EXECUTION:
	$ ./a.out a.txt b.txt
	Files Copied

	AFTER:

a.txt:

heyy 
helloo
hiii

b.txt:

heyy 
helloo
hiii

*/
