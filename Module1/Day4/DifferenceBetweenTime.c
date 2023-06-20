#include <stdio.h>
struct Time 
{
    int hours;
    int minutes;
    int seconds;
};
struct Time calculateTimeDifference(struct Time t1, struct Time t2) 
{
    struct Time diff;
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int diffSeconds = totalSeconds2 - totalSeconds1;
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;
    return diff;
}
int main() 
{
    struct Time startTime, endTime, timeDiff;
    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    timeDiff = calculateTimeDifference(startTime, endTime);
    printf("Time difference: %d hours, %d minutes, %d seconds\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);
    return 0;
}