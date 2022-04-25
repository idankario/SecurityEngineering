// Simple C program to encrypt and decrypt a string
#include <stdio.h>
int i;

// the key for encryption is 3 that is added to ASCII value
void encryptString(char *str)
{
    for (i = 1; (i < 100 && str[i] != ' '); i++)
        str[i] = str[i] + 3;
}

// the key for encryption is 3 that is subtracted to ASCII value
void decryptedString(char *str)
{
    for (i = 1; (i < 100 && str[i] != ' '); i++)
        str[i] = str[i] - 3;
}