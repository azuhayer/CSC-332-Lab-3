#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *file1, *file2;

    // create destination1.txt with read and write permissions
    file1 = fopen("destination1.txt", "w+");
    if (file1 == NULL) {
        printf("Error: failed to create destination1.txt\n");
        exit(1);
    }
    fclose(file1);

    // create destination2.txt with read and write permissions
    file2 = fopen("destination2.txt", "w+");
    if (file2 == NULL) 
    {
        printf("Error: failed to create destination2.txt\n");
        exit(1);
    }
    fclose(file2);

    printf("destination files created successfully\n");

    return 0;
}





