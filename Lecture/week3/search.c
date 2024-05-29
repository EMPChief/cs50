#include <cs50.h>
#include <stdio.h>
#include <string.h>
void draw(int height);
int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int height)
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height; j++)
        {
            if (j < height - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}