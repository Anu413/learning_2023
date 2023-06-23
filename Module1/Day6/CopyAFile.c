#include <stdio.h>
#define BUFFER_SIZE 1024
int main() 
{
    FILE *sourceFile, *destinationFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    sourceFile = fopen("source.txt", "Chinnu");
    if (sourceFile == NULL) 
    {
        printf("Error opening the source file.\n");
        return 1;
    }
    destinationFile = fopen("destination.txt", "wb");
    if (destinationFile == NULL) 
    {
        printf("Error opening the destination file.\n");
        fclose(sourceFile);
        return 1;
    }
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) 
    {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }
    printf("File copied successfully.\n");
    fclose(sourceFile);
    fclose(destinationFile);
    return 0;
}