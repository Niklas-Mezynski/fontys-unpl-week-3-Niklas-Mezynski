#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *customgetenv(char *name);
int customsetenv(char *name, char *value, int override);
int printAllEnvs()
{
    char **envs = environ;
    for (; *envs; envs++)
    {
        printf("%s\n", *envs);
    }
    printf("\n\n");
}

int main()
{
    // printAllEnvs();
    char envVar[15];
    char newValue[50];
    strcpy(envVar, "USERNAME");
    printf("[%s]:  %s\n", envVar, customgetenv(envVar));
    strcpy(newValue, "Peter");
    customsetenv(envVar, newValue, 1);
    printf("[%s]:  %s\n", envVar, customgetenv(envVar));
    strcpy(envVar, "NewEnvVar");
    printf("[%s]:  %s\n", envVar, customgetenv(envVar));
    strcpy(newValue, "Peter");
    customsetenv(envVar, newValue, 0);
    printf("3\n");
    printf("[%s]:  %s\n", envVar, customgetenv(envVar));
    printf("4\n");

    // strcpy(envVar, "APPDATA");
    // printf("[C's getenv] %s:  %s\n", envVar, getenv(envVar));
    // printf("[Custom]     %s:  %s\n", envVar, customgetenv(envVar));

    // strcpy(envVar, "JAVA_HOME");
    // printf("[C's getenv] %s:  %s\n", envVar, getenv(envVar));
    // printf("[Custom]     %s:  %s\n", envVar, customgetenv(envVar));

    // strcpy(envVar, "IntelliJ IDEA");
    // printf("[C's getenv] %s:  %s\n", envVar, getenv(envVar));
    // printf("[Custom]     %s:  %s\n", envVar, customgetenv(envVar));

    // strcpy(envVar, "Oops");
    // printf("[C's getenv] %s:  %s\n", envVar, getenv(envVar));
    // printf("[Custom]     %s:  %s\n", envVar, customgetenv(envVar));

    return 0;
}

char *customgetenv(char *name)
{
    char **envs = environ;
    char *result;
    for (; *envs; envs++)
    {
        result = strstr(*envs, name);
        if (result != NULL)
        {
            return (strchr(result, '=') + 1);
        }
    }
    return NULL;
}

int customsetenv(char *name, char *value, int override)
{
    char *currentValue = customgetenv(name);
    if (currentValue != NULL && override != 0)
    {
        // Override current value
        strcpy(currentValue, value);
    }
    else if (currentValue == NULL)
    {
        // Create new var
        char newEnv[128] = {""};
        strcat(newEnv, name);
        strcat(newEnv, "=");
        strcat(newEnv, value);
        char **envs = environ;
        int i = 0;
        while (envs[i + 1] != NULL)
        {
            i++;
        }
        int envsSize = (&envs[i] - envs);
        printf("1\n");
        envs = (char **)realloc(envs, envsSize * sizeof(envs[0]) + (sizeof(newEnv) / sizeof(newEnv[0])));
        printf("2\n");
        // envs[i + 1] = newEnv;
        strcpy(*(envs + i + 1), newEnv);

        // printf("Envs size: %d\n", envsSize);
        // char **newEnvs = malloc(envsSize + sizeof(newEnv));
        // *(newEnvs + envsSize)  = newEnv;
        // envs = newEnvs;
        // printAllEnvs();
        // printf("%s\n", envs[i]);
        // strcpy(envs[i + 1], newEnv);
        printAllEnvs();
        printf("Snens1 %s\n", environ[i]);
        printf("Snens2 %s\n", environ[i + 1]);
        // strncpy(envs[i + 1], newEnv, sizeof(newEnv));
    }
}