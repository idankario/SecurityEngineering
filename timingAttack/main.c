#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
// #include <unistd.h>
#include "server.c"
const char BUFFER[] = "adiknstv";
const int SIZE = 7;

void startAttack(char *pass)
{
    int maxTime = 0;
    int diffTime = 0;
    int i = 0;
    time_t startTime, endTime;
    bool isSuccess = false;
    int buffi = -1;
    while (!(isSuccess))
    {
        // Start te detrmine time from now unfil end time to stop watch
        startTime = time(NULL);
        isSuccess = protectServer(pass);
        endTime = time(NULL);
        diffTime = endTime - startTime;
        if (maxTime < diffTime)
        {
            printf("Decryption %s \n", pass);
            buffi = 0;
            i++;
            maxTime = diffTime;
        }
        else
        {
            buffi++;
        }
        printf("Max time %d index %d\n", maxTime, buffi);
        pass[i] = BUFFER[buffi];
    }
}

void timingAttack()
{
    char pass[] = "0000000000000";
    startAttack(pass);
    printf("Decryption password %s \n", pass);
}

int main()
{
    timingAttack();
    return 0;
}