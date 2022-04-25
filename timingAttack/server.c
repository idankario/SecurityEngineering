// ProtectServer will check evry two sec the pass if
// Correct return true else false and sleep two sec
int protectServer(char *pass)
{
    char *myPass = "idanstavattak";
    for (int i = 0; i < strlen(myPass); i++)
    {
        if (pass[i] != myPass[i])
            return 0;
        sleep(1);
    }
    return 1;
}