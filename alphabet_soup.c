/**************************************************************************************************
 *                                                                         ___    ____
 * Take the str string parameter being passed and return the string       /   |  / __ \
 * with the lettersin alphabetical order (ie. hello becomes ehllo).      / /| | / /_/ /
 * Assume numbers and punctuation symbols will not be included          / ___ |/ ____/
 * in the string.                                                      /_/  |_/_/
 * Make sorting case-sensitive.
 *
 *************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
 *
 *****************************************************************************/
static bool upper_case(char letter)
{
    if (letter >= 'A' && letter <= 'Z') {
        return true;
    }

    return false;
}

/******************************************************************************
 *
 *****************************************************************************/
static bool swap_condition(char first_letter, char second_letter)
{
    bool condition_ok = false;

    if (upper_case(first_letter) && upper_case(second_letter)) {
        if (first_letter > second_letter) {
            condition_ok = true;
        }
    }
    else if (upper_case(first_letter)) {
        if ((first_letter + 0x20) > second_letter) {
            condition_ok = true;
        }
    }
    else if (upper_case(second_letter)) {
        if (first_letter >= (second_letter + 0x20)) {
            condition_ok = true;
        }
    }
    else {
        if (first_letter > second_letter) {
            condition_ok = true;
        }
    }

    return(condition_ok);
}

/******************************************************************************
 * Sorts the input word recursively
 *****************************************************************************/
static void alphabet_sort(char *word, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) {
        if (swap_condition(word[i], word[i+1])) {
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
