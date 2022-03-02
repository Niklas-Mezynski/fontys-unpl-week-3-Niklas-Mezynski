#include <stdio.h>

#define arr_size 7

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

Week weekArr[arr_size];

int readFromConsole();
int printToConsole();

int main(int argc, char **argv)
{
    Week day;
    day = Wed;
    if (day == Wed)
        printf("%d\n", day);
    return 0;
}

