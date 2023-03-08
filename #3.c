#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid1, pid2;
    int status1, status2;

    printf("Parent process with PID: %d\n", getpid());

    // Create first child process to display date and time
    pid1 = fork();
    if (pid1 < 0) 
    {
        perror("Failed to fork first child");
        exit(1);
    }
    else if (pid1 == 0) 
    {
        printf("First child process with PID: %d\n", getpid());
        execl("/bin/date", "date", (char*)NULL);
        perror("execl failed");
        exit(1);
    }

    // Create second child process to display directory contents
    pid2 = fork();
    if (pid2 < 0) 
    {
        perror("Failed to fork second child");
        exit(1);
    }
    else if (pid2 == 0) 
    {
        printf("Second child process with PID: %d\n", getpid());
        char *args[] = {"ls", "-al", NULL};
        execvp("ls", args);
        perror("execvp failed");
        exit(1);
    }

    // Wait for both child processes to finish
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);

    printf("Both child processes have completed.\n");

    return 0;
}