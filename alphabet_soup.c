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
 * Comparison function for ignored case sorting
 *****************************************************************************/
static int compare_ignore_case(const void *first_letter, const void *second_letter)
{
    char c1 = *(char *)first_letter;
    char c2 = *(char *)second_letter;
    char u1 = toupper(c1);
    char u2 = toupper(c2);

    return (u1 > u2) - (u1 < u2);
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
        qsort(word, strlen(word), sizeof(char), compare_ignore_case);
    }
    else if (strcmp(option, DEFAULT) == 0) {
        qsort(word, strlen(word), sizeof(char), compare_case_independent);
    }
    else {
        printf("Unknown option\n");
    }
}
