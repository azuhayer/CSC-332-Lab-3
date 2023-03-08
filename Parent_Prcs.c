#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    // Create Child 1
    pid1 = fork();

    if (pid1 < 0) {
        printf("Error creating Child 1.");
        return 1;
    } else if (pid1 == 0) {
        // This is Child 1
        char *args[] = {"./Prcs_P1", NULL};
        execv(args[0], args);
        exit(0);
    } else {
        // This is Parent
        wait(NULL);
    }

    // Create Child 2
    pid2 = fork();

    if (pid2 < 0) {
        printf("Error creating Child 2.");
        return 1;
    } else if (pid2 == 0) {
        // This is Child 2
        char *args[] = {"./Prcs_P2", NULL};
        execv(args[0], args);
        exit(0);
    } else {
        // This is Parent
        wait(NULL);
    }

    printf("Program completed successfully.");

    return 0;
}