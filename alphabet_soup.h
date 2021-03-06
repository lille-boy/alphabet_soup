/**************************************************************************************************
 *                                                                         ___    ____
 * Take the str string parameter being passed and return the string       /   |  / __ \
 * with the letters in alphabetical order (ie. hello becomes ehllo).     / /| | / /_/ /
 * Assume numbers and punctuation symbols will not be included          / ___ |/ ____/
 * in the string.                                                      /_/  |_/_/
 * Make sorting case-sensitive.
 *
 *************************************************************************************************/
#ifndef ALPHABET_SOUP_H
#define ALPHABET_SOUP_H

/* Options */
#define TEST "-t"
#define DEFAULT ""
#define IGNORE_CASE "-f"

/******************************************************************************
 * Description:
 * - sorts the letters of a input word in alphabetical order.
 * Parameter:
 * - word: one word without space character
 * - option: DEFAULT does case-independent sorting, IGNORE_CASE sorts in
 * ascending ASCII values
 * Return:
 * - variable word contains the sorted string
 *****************************************************************************/
void alphabet_soup(char *word, char *option);

#endif /* ALPHABET_SOUP_H */
