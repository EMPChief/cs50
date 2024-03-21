#include <stdio.h>
#include "cs50.h"

int string_length(string s);

int main(void)
{

    string name = get_string("What's your name? ");
    
    int length = string_length(name);
    printf("Length: %i\n", length);
}

int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
-------------
#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: %s\n", s);
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}
---------------
#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
--------------
#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
--------------
#include <stdio.h>
#include "cs50.h"

int main(int argc, string argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("Hello, %s\n", argv[i]);
    }
}
--------------
#include <stdio.h>
#include "cs50.h"

int main(int argc, string argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("Hello, %s\n", argv[i]);
    }

    printf("\n");
    printf("        *****        \n");
    printf("    ***       ***    \n");
    printf("  **             **  \n");
    printf(" **   \\  O O  /   ** \n");
    printf("**     \\  ^  /     **\n");
    printf("**     |     |     **\n");
    printf("**     |     |     **\n");
    printf(" **    \\___/    **  \n");
    printf("  **           **   \n");
    printf("    ***     ***     \n");
    printf("        *****       \n");
    printf("\n");

    return 0;
}
--------------
$ make scrabble                                                                 
$ ./scrabble                                                                    
Player 1: Question?                                                             
Player 2: Question!                                                             
Tie!                                                                            
$ ./scrabble                                                                    
Player 1: red                                                                   
Player 2: wheelbarrow                                                           
Player 2 wins!                                                                  
$ ./scrabble                                                                    
Before Grade 1                                                                  
$ ./readability                                                                 
Text: Congratulations! Today is your day. You're off to Great Places! You're off
 and away!                                                                      
Grade 3                                                                         
$ ./readability                                                                 
Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hate
d the summer holidays more than any other time of year. For another, he really w
anted to do his homework, but was forced to do it in secret, in the dead of the 
night. And he also happened to be a wizard.                                     
Grade 5                                                                         
$                                              