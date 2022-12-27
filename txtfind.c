#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30
// #define ENTER 10
// #define TAB 11

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
    for (i = 0; i < WORD && (c = getchar()) != EOF && c != '\n' && c != ' ' && c != '\t'; i++)
    {
        w[i] = c;
    }
    if(i == 0 && c != ' ' && c != '\t'){
        i++;
    }
    w[i] = '\0';
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
    // if (!memcmp(s, t, size))
    // if ((strlen(s) != (strlen(t) + n)) || (strlen(s) != strlen(t)))
    // {
    //     return 0;
    // }
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
    // return diff==n;
    if (diff == 0 || diff == n)
    {
        return 1;
    }
    return 0;
}

int similarT(char *s, char *t, int n)
{
    int i;
    int saveN = n;
    int indexT = 0;
    for (i = 0; i < strlen(s) && indexT < strlen(t) && n >= 0; i++)
    {
        if (*(s + i) != *(t + indexT))
        {
            n--;
        }
        else
        {
            indexT++;
        }
    }

    printf("n = %d\n", n);
    printf("i = %d\n", i);
    printf("strlen(s) = %d\n", (int)strlen(s));
    printf("indexT = %d\n", indexT);
    printf("strlen(t) = %d\n", (int)strlen(t));

    if (n == 0 && i == strlen(s) && indexT == strlen(t))
    {
        return 1;
    }

    if (i < strlen(s) && n != 0)
    {
        while (i < strlen(s))
        {
            n--;
            i++;
        }
        if (n == 0)
        {
            return 1;
        }
    }

    if (n == saveN && i == strlen(s) && indexT == strlen(t))
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
            // printString(word, lenWord);
            printf("%s", word);
        }
        //getchar();
        // word[WORD] = {0};
        lenWord = get_word(word);
    }
}

void print_similar_wordst(char *str)
{
    char word[WORD] = {0};
    get_word(word);
    while (*word != '\0')
    {
        if (similar(word, str, 1))
        {
            printf("%s", word);
        }
        get_word(word);
    }
}
