#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    int s1 = 0, s2 = 0, s3 = 0;

    // create the first child process
    pid_t pid1 = fork();
    if (pid1 == -1) 
    {
        perror("fork");
        exit(1);
    } 
    else if (pid1 == 0) 
    {
        // child process 1 computes S1
        for (int i = 2; i <= n; i += 2) 
        {
            s1 += i;
        }
        printf("S1 = %d\n", s1);
        exit(0);
    } 
    else 
    {
        // create the second child process
        pid_t pid2 = fork();
        if (pid2 == -1) 
        {
            perror("fork");
            exit(1);
        } 
        else if (pid2 == 0) 
        {
            // child process 2 computes S2
            for (int i = 1; i <= n; i += 2) 
            {
                s2 += i;
            }
            printf("S2 = %d\n", s2);
            exit(0);
        } 
        else 
        {
            // parent process computes S3
            for (int i = 1; i <= n; i++) 
            {
                s3 += i;
            }
            printf("S3 = %d\n", s3);
            
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}