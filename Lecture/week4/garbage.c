#include <stdio.h>

int main(void)
{
    int scores[2000];

    for (int index = 0; index < 2000; index++)
    {
        scores[index] = index;
        printf("%d\n", scores[index]);
    }
    return 0;
}