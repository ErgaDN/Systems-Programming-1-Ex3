#include <stdio.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30
#define ENTER 10
#define TAB 11

int main()
{

    // char word1[WORD] = {0}; 
    // get_word(word1); //cat
    // printf("%s ", word1);


    // char line[LINE] = {0};
    // get_line(line); //b
    // get_line(line); //b
    // printf("%s", line);
    // printf("\n");

    // char word[WORD] = {0};
    // get_word(word); // \n
    // printf("%s", word);
    // printf("\n");

    // print_similar_words(word1);
    // printf("\n\n");

    // char word3[WORD] = {0};
    // get_word(word3);
    // printf("%s", word3);
    // // printf("\n");

    char cat[] =  "cat";
    print_similar_words(cat);

    // printf( "%d",similar("cat", "catj", 1));
    printf("\n");
   

    // for (int i = 0 ; i < 10 ; i++){
        char word1[WORD] = {0}; 
        
        // get_word(word1); //cat
        // printf("%s", word1);
    //     printf("\n");
        
    // }
   





    //////// Main start/////////
    // char searchWord[] = {0};
    // get_word(searchWord);

    // char trush = getchar();
    // char method = getchar();
    // trush = getchar();

    // // char a[] = {0};
    // // get_line(a);

    // if(method == 'a')
    // {
    //     print_lines(searchWord);
    // } 

    // else if(method == 'b')
    // {
    //     print_similar_words(searchWord);
    // } 

    //////// Main end /////////



    /// check 1,2

    // char s[WORD];
    // int lenLine = get_line(s);
    // printf("%d\n", lenLine);

    // for(int i = 0; i<lenLine; i++)
    // {
    //     printf("%c ,", s[i]);
    // } 
    // printf("\n");

    /// check 3

    // char c1[] = "abcdefg";
    // char c2[] = "deg";
    // printf("%d\n", substring(c1,c2));

    /// check 4

    // char t[] = "cat";
    // char s[] = "catc";
    // printf("%d\n", similar( s, t, 1));

    /// check 5

    // char c[] = {"ab"};
    // print_lines(c);

    /// check 6

    // char w[] = {"cat"};
    // print_similar_words(w);

   
    return 0;
}