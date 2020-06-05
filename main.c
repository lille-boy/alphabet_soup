/**************************************************************************************************
 *                                                                         ___    ____
 * Main Program                                                           /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "alphabet_soup.h"
#include "tests.h"


/******************************************************************************
 * Main
 *****************************************************************************/
int main(int argc, char *argv[])
{
    if (argc > 1) {
        char *option = argv[1];
        if (argc > 2) {
            if (strcmp(option, IGNORE_CASE) == 0) {
                alphabet_soup(argv[2], option);
                printf("%s\n", argv[2]);
            }
        }
        else {
            if (strcmp(option, TEST) == 0) {
                tests_all();
            }
            else {
                alphabet_soup(argv[1], DEFAULT);
                printf("%s\n", argv[1]);
            }
        }
    }
    else {
        printf("provide a string\n");
    }

    return 0;
}
