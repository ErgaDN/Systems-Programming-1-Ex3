#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30

/**The function receives a line and stores it in the string s.
 * The function will return the amount of chars actually received.*/
int get_line(char s[])
{
    int c, i;
    for (i = 0; i < LINE && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    return i;
}

/**The function receives a word and stores it in the string w.
 * The function will return the amount of chars actually received.*/
int get_word(char w[])
{
    int c, i;
    for (i = 0; i < WORD ; i++)
    {
        c = getchar();
        w[i] = c;
        if (w[i] == '\n' || w[i] == ' ' || w[i] == '\t' || w[i] == '\r' || w[i] == EOF)
        {
            w[i] = '\0';
            break;
        }
    }
    return i;
}

// The function receives two strings, str1 and str2, and checks whether str2 is contained in str1.
int substring(char *str1, char *str2)
{
    if (strstr(str1, str2) != NULL)
    {
        return 1;
    }
    return 0;
}

/**The function will receive two strings t s and a number n.
 * The function will check if it is possible to get from the string S to the string t by omitting n characters.*/
int similar(char *s, char *t, int n)
{
    int diff = 0;
    int i, j = 0;
    for (i = 0; i < strlen(s) && j < strlen(t); i++)
    {
        if (s[i] != t[j])
        {
            diff++;
        }
        else
        {
            j++;
        }
    }
    if (j < strlen(t))
    {
        return 0;
    }
    while (i < strlen(s))
    {
        diff++;
        i++;
    }
    if (diff == n)
    {
        return 1;
    }
    return 0;
}

/**The function receives an array and a length and prints the array with the desired length*/
void printString(char *str, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

/**The function receives a string, picks up the lines of text, and prints the lines in which the string appears*/
void print_lines(char *str)
{
    char line[LINE] = {0};
    int lenline = get_line(line);
    while (lenline)
    {
        if (substring(line, str))
        {
            printString(line, lenline);
        }
        lenline = get_line(line);
    }
}

/**The function receives a string, picks up the words of the text and prints the words similar to the search string up to the 
 * omission of one letter from the words that appear in the text, including words identical to the search string.*/
void print_similar_words(char *str)
{
    char word[WORD] = {0};
    int lenWord = get_word(word);
    while (lenWord)
    {
        if (similar(word, str, 1) || similar(word, str, 0))
        {
            printf("%s\n", word);
        } 
        lenWord = get_word(word);
    }
}

