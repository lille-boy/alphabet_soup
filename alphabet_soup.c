/**************************************************************************************************
 *
 * Take the str string parameter being passed and return the string with the letters
 * in alphabetical order (ie. hello becomes ehllo).
 * Assume numbers and punctuation symbols will not be included in the string.
 *
 *************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alphabet_soup.h"

/******************************************************************************
 * Swaps two letters
 *****************************************************************************/
static void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

/******************************************************************************
 * Sorts the input word recursively
 *****************************************************************************/
static void alphabet_sort(char *word, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) {
        if (word[i] > word[i + 1]) {
            swap(&word[i], &word[i+1]);
            alphabet_sort(&word[0], i + 1);
        }
    }
}

/******************************************************************************
 *
 *****************************************************************************/
void alphabet_soup(char *word)
{
    unsigned int size = strlen(word) - 1;

    alphabet_sort(word, size);
    printf("%s\n", word);
}
