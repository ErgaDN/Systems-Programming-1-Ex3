#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30

int get_line(char s[])
{
    int c, i;
    for (i = 0; i < LINE && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    return i;
}

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

int substring(char *str1, char *str2)
{
    if (strstr(str1, str2) != NULL)
    {
        return 1;
    }
    return 0;
}

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
    if (diff == 0 || diff == n)
    {
        return 1;
    }
    return 0;
}


void printString(char *str, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

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

void print_similar_words(char *str)
{
    char word[WORD] = {0};
    int lenWord = get_word(word);
    while (lenWord)
    {
        if (similar(word, str, 1))
        {
            printf("%s\n", word);
        } 
        lenWord = get_word(word);
    }
}

