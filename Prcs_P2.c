#include <stdio.h>

int main() 
{
    FILE *source, *dest1, *dest2;
    char buffer1[101], buffer2[51];
    int count1, count2;

    source = fopen("source.txt", "r");
    dest1 = fopen("destination1.txt", "w");
    dest2 = fopen("destination2.txt", "w");

    if (source == NULL || dest1 == NULL || dest2 == NULL) 
    {
        printf("Error opening files.");
        return 1;
    }

    while (!feof(source)) 
    {
        count1 = fread(buffer1, sizeof(char), 100, source);
        count2 = fread(buffer2, sizeof(char), 50, source);

        for (int i = 0; i < count1; i++) 
        {
            if (buffer1[i] == '1') 
            {
                buffer1[i] = 'L';
            }
        }

        for (int i = 0; i < count2; i++) 
        {
            if (buffer2[i] == '3') 
            {
                buffer2[i] = 'E';
            }
        }

        fwrite(buffer1, sizeof(char), count1, dest1);
        fwrite(buffer2, sizeof(char), count2, dest2);
    }

    fclose(source);
    fclose(dest1);
    fclose(dest2);

    printf("Copying process completed successfully.");

    return 0;
}