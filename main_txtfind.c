#include <stdio.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30
#define ENTER 10
#define TAB 11

/**
 * The progrem received a search string and a search option, and acts accordingly.
*/

int main()
{
    char searchWord[WORD] = {0};
    get_word(searchWord);

  
    int method = getchar();
    getchar();
    getchar();

    if(method == 'a')
    {
        print_lines(searchWord);
    } 

    else if(method == 'b')
    {
        print_similar_words(searchWord);
    } 
  
    return 0;
}