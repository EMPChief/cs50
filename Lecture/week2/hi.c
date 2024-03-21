#include <stdio.h>
#include "cs50.h"

int main(void)
{
    // Declaring the characters
    char c1 = 'H';
    char c2 = 'e';
    char c3 = 'l';
    char c4 = 'o';
    // Printing the characters
    printf ("%c%c%c%c%c\n", c1, c2, c3, c3, c4);
    // declaring the string
    string s = "Hello!";
    string t = "Bye!";
    // printing the integer
    printf ("%i %i %i %i %i %i %i\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
    printf ("%i %i %i %i %i %i %i\n", t[0], t[1], t[2], t[3], t[4], t[5], t[6]);
    // printing the string
    printf ("%s\n", s);
    printf ("%s\n", t);
    // declaring the array
    string words[2];
    words[0] = "Hello";
    words[1] = "World";
    // printing the array
    printf ("%s\n", words[0]);
    printf ("%s\n", words[1]);
    // printing the array
    printf ("%s %s\n", words[0], words[1]);
    // printing the array by accessing the characters in the array
    printf("%c%c%c%c%c\n", words[0][0], words[0][1], words[0][2], words[0][3], words[0][4]);
    printf("%c%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3], words[1][4]); 
    // going passed first array and accessing the characters from the second array
    printf("%c%c%c%c%c\n", words[0][6], words[0][7], words[0][8], words[0][9], words[0][10]);


}