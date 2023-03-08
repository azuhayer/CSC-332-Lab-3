#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() 
{
    int fd1, fd2;

    // Create destination1.txt
    fd1 = open("destination1.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd1 < 0) 
    {
        printf("Error creating destination1.txt.");
        return 1;
    }
    close(fd1);

    // Create destination2.txt
    fd2 = open("destination2.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) 
    {
        printf("Error creating destination2.txt.");
        return 1;
    }
    close(fd2);

    printf("Program completed successfully.");

    return 0;
}





