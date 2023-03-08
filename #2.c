#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) 
{
    
    //checks for integer parameter
    if( argc !=2) 
    {
        printf("Integer parameter is missing\n");
        return 1;
    }

    //set two pipes to bring s1 and s2 into parent process after being calculated in the children processes
    int pipefd1[2];
    int pipefd2[2];
    int p1 = pipe(pipefd1);
    int p2 = pipe(pipefd2);

    //convert string from argv[1] into an integer
    int num = atoi(argv[1]);

    //forking child one from parent process
    int child1 = fork();

    if (child1 == 0) 
    {
        //closes read and write end of second pipe in child one process 
        close(pipefd2[0]);
        close(pipefd2[1]);
        //closes read end of first pipe in child one process
        close(pipefd1[0]);

        int s1 = 0;
        //use for loop to add the odd numbers
        for (int i = 1; i <= num; i = i + 2) 
        {
            s1 = s1 + i;
        }

        //print s1 from child one process
        printf("S1: %d\n", s1);
        write(pipefd1[1], &s1, sizeof(int));
        close(pipefd1[1]);

    } 
    else 
    {
        wait(NULL);
        int child2 = fork();
        if (child2 == 0) 
        {
            //closes read and write end of first pipe in child two process 
            close(pipefd1[0]);
            close(pipefd1[1]);
            //closes read end of second pipe in child two process
            close(pipefd2[0]);

            int s2 = 0;
            //use for loop to add the even numbers
            for (int i = 0; i <= num; i = i + 2) 
            {
                s2 = s2 + i;
            }

            //print s2 from child two process
            printf("S2: %d\n", s2);
            write(pipefd2[1], &s2, sizeof(int));
            close(pipefd2[1]);
            
        } 
        else 
        {
            wait(NULL);

            //closes the write end of both pipes
            close(pipefd1[1]);
            close(pipefd2[1]);

            int s1, s2, s3;

            read(pipefd1[0], &s1, sizeof(int));
            read(pipefd2[0], &s2, sizeof(int));

            s3 = s1 + s2;

            //prints s3 from parent process
            printf("S3: %d\n", s3);

            close(pipefd1[0]);
            close(pipefd2[0]);
        }
    }

    return 0;
}