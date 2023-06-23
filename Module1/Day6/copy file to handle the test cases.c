#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFFER_SIZE 1024
void convertToUpper(char* str) 
{
    while (*str) 
    {
        *str = toupper((unsigned char)*str);
        str++;
    }
}
void convertToLower(char* str) 
{
    while (*str) 
    {
        *str = tolower((unsigned char)*str);
        str++;
    }
}
void convertToPureUpper(char* str) 
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) 
    {
        if (isalpha(str[i]))
            str[i] = toupper((unsigned char)str[i]);
    }
}
void copyFile(FILE* sourceFile, FILE* destinationFile, int option) 
{
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) 
    {
        if (option == 1)
            convertToUpper(buffer);
        else if (option == 2)
            convertToLower(buffer);
        else if (option == 3)
            convertToPureUpper(buffer);
        fwrite(buffer, 1, bytesRead, destinationFile);
    }
}
int main(int argc, char* argv[]) 
{
    if (argc < 3) 
    {
        printf("Usage: ./cp [option] source_file destination_file\n");
        return 1;
    }
    int option = 0;
    char* optionStr = argv[1];
    if (strcmp(optionStr, "-u") == 0)
        option = 1;
    else if (strcmp(optionStr, "-l") == 0)
        option = 2;
    else if (strcmp(optionStr, "-s") == 0)
        option = 3;
    FILE* sourceFile = fopen(argv[2], "rb");
    if (sourceFile == NULL) 
    {
        printf("Error opening the source file.\n");
        return 1;
    }
    FILE* destinationFile = fopen(argv[3], "wb");
    if (destinationFile == NULL) 
    {
        printf("Error opening the destination file.\n");
        fclose(sourceFile);
        return 1;
    }
    copyFile(sourceFile, destinationFile, option);
    printf("File copied successfully.\n");
    fclose(sourceFile);
    fclose(destinationFile);
    return 0;
}