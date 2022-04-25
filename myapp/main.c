// C program to implement attack overflow and virable
// The above is our approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.c"
#include <stdbool.h>

void printUserAndPass()
{
    printf("admin details: \n");
    printFile("data/admin.txt");
    printf("user details: \n");
    printFile("data/user.txt");
}

int verifyUser(char *s, char *user)
{
    char pass[15];
    strcat(pass, " ");
    strcat(pass, s);
    strcat(pass, " \r");
    int v = verifyUserByFile("data/admin.txt", pass, user);
    if (v)
        return 2;
    else
        v = verifyUserByFile("data/user.txt", pass, user);
    return v;
}

int main(int argc, char **argv)
{
    int verify = 0;
    bool isAdmin = false;
    char userPass[9];
    char userName[9];
    printf("Please Enter Password :");
    gets(userPass);
    printf("Please Enter User Name :");
    gets(userName);
    verify = verifyUser(userPass, userName);
    if (verify == 2)
        isAdmin = true;
    if (isAdmin)
        printUserAndPass();
    return 0;
}
