#include <stdio.h>
#include <string.h>

#define arr_size 5

enum week
{
    Mon,
    Tue,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};

typedef enum week Week;

const char *weekStrings[] = {"Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};

Week weekArr[arr_size];

int readFromConsole();
int printToConsole();

int main(int argc, char **argv)
{
    readFromConsole();

    printf("\nThe weekdays you entered were:\n");
    printToConsole();
    return 0;
}


int readFromConsole()
{

    for (size_t i = 0; i < arr_size; i++)
    {
        printf("Enter a weekday\n");
        char input[5];
        scanf("%s", input);
        short wasFound = 0;
        for (size_t j = 0; j < 7; j++)
        {
            if (strcmp(weekStrings[j], input) == 0)
            {
                weekArr[i] = j;
                wasFound = 1;
                break;
            }
        }
        if (wasFound == 0) {
            printf("Invalid day\n");
            i--;
        }
    }
}


int printToConsole()
{
    for (size_t i = 0; i < sizeof(weekArr) / sizeof(weekArr[0]); i++)
    {
        printf("%d: %s\n", i + 1, weekStrings[weekArr[i]]);
    }
}