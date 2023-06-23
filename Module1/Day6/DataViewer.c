#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100
#define MAX_SENSOR_NAME 20
#define MAX_TIMESTAMP 10
typedef struct 
{
    int entryNo;
    char sensorNo[MAX_SENSOR_NAME];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_TIMESTAMP];
} LogEntry;
int extractLogEntries(LogEntry logEntries[]) 
{
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) 
    {
        printf("Error opening the data file.\n");
        return 0;
    }
    char line[100];
    int entryCount = 0;
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file)) 
    {
        line[strcspn(line, "\n")] = '\0';
        char* token = strtok(line, ",");
        int tokenCount = 0;
        while (token != NULL) 
        {
            switch (tokenCount) 
            {
                case 0:
                    logEntries[entryCount].entryNo = atoi(token);
                    break;
                case 1:
                    strncpy(logEntries[entryCount].sensorNo, token, sizeof(logEntries[entryCount].sensorNo));
                    break;
                case 2:
                    logEntries[entryCount].temperature = atof(token);
                    break;
                case 3:
                    logEntries[entryCount].humidity = atoi(token);
                    break;
                case 4:
                    logEntries[entryCount].light = atoi(token);
                    break;
                case 5:
                    strncpy(logEntries[entryCount].timestamp, token, sizeof(logEntries[entryCount].timestamp));
                    break;
            }
            token = strtok(NULL, ",");
            tokenCount++;
        }
        entryCount++;
    }
    fclose(file);
    return entryCount;
}
void displayLogEntries(LogEntry logEntries[], int entryCount) 
{
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < entryCount; i++) 
    {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}
int main() 
{
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = extractLogEntries(logEntries);
    if (entryCount > 0) 
    {
        displayLogEntries(logEntries, entryCount);
    } else 
    {
        printf("No log entries found.\n");
    }
    return 0;
}