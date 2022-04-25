#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.c"
#include <stdbool.h>
#define FILE_OK 0
#define FILE_NOT_EXIST 1
#define FILE_TOO_LARGE 2
#define FILE_READ_ERROR 3

char *c_read_file(const char *f_name, int *err)
{
    char *buffer;
    size_t length;
    FILE *f = fopen(f_name, "rb");
    size_t read_length;
    if (f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        // Checker to quit when file is bigger than 1 GiB. can crash a computer
        if (length > 1073741824)
        {
            *err = FILE_TOO_LARGE;
            return NULL;
        }
        buffer = (char *)malloc(length + 1);
        if (length)
        {
            read_length = fread(buffer, 1, length, f);
            if (length != read_length)
            {
                free(buffer);
                *err = FILE_READ_ERROR;
                return NULL;
            }
        }
        fclose(f);
        *err = FILE_OK;
        buffer[length] = '\0';
    }
    else
    {
        *err = FILE_NOT_EXIST;
        return NULL;
    }
    return buffer;
}
void printFile(char *pathFile)
{
    int err;
    char *f_data = c_read_file(pathFile, &err);
    if (err)
    {
        printf("error");
    }
    else
    {
        char *token = strtok(f_data, "\n");
        while (token != NULL)
        {
            printf("%c", token[0]);
            while (*token != '\0')
            {
                printf("%c", token[0]);
                if (token++[0] == 'p')
                {
                    printf("%c", token[0]);
                    if (token++[0] == 'a')
                    {
                        printf("%c", token[0]);
                        if (token++[0] == 's')
                        {
                            printf("%c", token[0]);
                            if (token++[0] == 's')
                            {
                                printf("%c", token[0]);
                                if (token++[0] == ':')
                                {

                                    decryptedString(token);
                                    printf("%s \n", token);
                                }
                            }
                        }
                    }
                }
            }
            token = strtok(NULL, "\n");
        }
        free(f_data);
    }
}

int verifyUserByFile(char *pathFile, char *pass, char *user)
{
    int err;
    char *f_data = c_read_file(pathFile, &err);
    if (err)
    {
        printf("error");
    }
    else
    {
        char *token = strtok(f_data, "\n");
        char *temp1;
        while (token != NULL)
        {
            while (*token != '\0')
            {
                if (token++[0] == 'u')
                    if (token++[0] == 's')
                        if (token++[0] == 'e')
                            if (token++[0] == 'r')
                                if (token++[0] == ':')
                                {
                                    char *const sep_at = strchr(token, ',');
                                    *sep_at = '\0';
                                    if (strcmp(token, user) == 0)
                                    {
                                        while ((token++)[0] != 'p')
                                            ;
                                        if (token++[0] == 'a')
                                        {
                                            if (token++[0] == 's')
                                            {
                                                if (token++[0] == 's')
                                                {
                                                    if (token++[0] == ':')
                                                    {
                                                        decryptedString(token);
                                                        if (strcmp(token, pass) == 0)
                                                            return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
            }
            token = strtok(NULL, "\n");
        }
        free(f_data);
    }
    return 0;
}
