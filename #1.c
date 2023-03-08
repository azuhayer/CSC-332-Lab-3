#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t child_pid1, child_pid2;

    child_pid1 = fork();
    if (child_pid1 == 0) 
    {
        printf("I am child one, my pid is: %d\n", getpid());
        return 0;
    }

    child_pid2 = fork();
    if (child_pid2 == 0) 
    {
        printf("I am child two, my pid is: %d\n", getpid());
        return 0;
    }

    // wait for both children to finish
    printf("Parent is waiting \n");
    waitpid(child_pid1, NULL, 0);
    waitpid(child_pid2, NULL, 0);
    printf("Parent is done waiting \n");

    return 0;
}