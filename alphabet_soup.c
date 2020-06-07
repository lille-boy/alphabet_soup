/**************************************************************************************************
 *                                                                         ___    ____
 * Take the string parameter being passed and return the string           /   |  / __ \
 * with the letters in alphabetical order (ie. hello becomes ehllo).     / /| | / /_/ /
 * Assume numbers and punctuation symbols will not be included          / ___ |/ ____/
 * in the string.                                                      /_/  |_/_/
 * Make sorting case-sensitive.
 *
 *************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
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
 * Comparison function for case independent sorting
 *****************************************************************************/
static int compare_case_independent(const void *first_letter, const void *second_letter)
{
    char c1 = *(char *)first_letter;
    char c2 = *(char *)second_letter;
    char u1 = toupper(c1);
    char u2 = toupper(c2);

    if (u1 != u2) {
        return (u1 > u2) - (u1 < u2);
    }

    return (c1 > c2) - (c1 < c2);
}

/******************************************************************************
 * Sorts the letters of a input word in alphabetical order
 *****************************************************************************/
void alphabet_soup(char *word, char *option)
{
    if (strcmp(option, IGNORE_CASE) == 0) {
        unsigned int size = strlen(word) - 1;
        alphabet_sort(word, size);
    }
    else if (strcmp(option, DEFAULT) == 0) {
        qsort(word, strlen(word), sizeof(char), compare_case_independent);
    }
    else {
        printf("Unknown option\n");
    }
}
