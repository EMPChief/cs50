#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// Declare functions count_letters, count_words, and count_sentences to count the number of letters,
// words, and sentences in the text
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    int grade = round(index);
    // Print the grade level if it's less than 1
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    // Print the grade level if it's between 1 and 16
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    // Print the grade level if it's greater than 16
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count_letters(string text)
{
    // Declare a variable to store the number of letters
    int count = 0;
    // declare n as the length of the text
    int n = strlen(text);
    // Use a for loop to count the number of letters
    for (int i = 0; i < n; i++)
    {
        // If the character is a letter, increment the count
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    // Declare a variable to store the number of words
    int count = 0;
    // declare n as the length of the text
    int n = strlen(text);
    // Use a for loop to count the number of words
    for (int i = 0; i < n; i++)
    {
        // If the character is a space, increment the count
        if (isspace(text[i]))
        {
            count++;
        }
    }
    // Increment the count by 1 to account for the last word
    return count + 1;
}

int count_sentences(string text)
{
    // Declare a variable to store the number of sentences
    int count = 0;
    // declare n as the length of the text
    int n = strlen(text);
    // Use a for loop to count the number of sentences
    for (int i = 0; i < n; i++)
    {
        // If the character is a period, exclamation point, or question mark, increment the count
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
