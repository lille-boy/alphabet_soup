/**************************************************************************************************
 *                                                                         ___    ____
 * Tests                                                                  /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alphabet_soup.h"
#include "tests.h"

unsigned int pass = 0;
unsigned int fail = 0;
unsigned int executed = 0;

/******************************************************************************
 * Count the results
 *****************************************************************************/
static void test_result(const char *test_name, const char *output, const char *expected)
{
	if (strcmp(output, expected) == 0) {
		pass++;
		if(DEBUG >= 2) {
			printf("%s: pass\n", test_name);
		}
	}
	else {
		fail++;
		if(DEBUG >= 1) {
			printf("%s: fail - ", test_name);
		}
	}

	executed++;
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_alphabet(void)
{
    const char *input = "alphabet";
	size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
	memcpy(output, input, size);
    alphabet_soup(output);

    test_result("test_alphabet", output, "aabehlpt");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_Sensitive(void)
{
    const char *input = "Sensitive";
	size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
	memcpy(output, input, size);
    alphabet_soup(output);

    test_result("test_Sensitive", output, "eeiinSstv");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_encyclopedia(void)
{
    const char *input = "encyclopedia";
	size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
	memcpy(output, input, size);
    alphabet_soup(output);

    test_result("test_encyclopedia", output, "accdeeilnopy");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_Windows(void)
{
    const char *input = "Windows";
	size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
	memcpy(output, input, size);
    alphabet_soup(output);

    test_result("test_Windows", output, "dinosWw");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_WordReference(void)
{
    const char *input = "WordReference";
	size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
	memcpy(output, input, size);
    alphabet_soup(output);

    test_result("test_WordReference", output, "cdeeeefnoRrrW");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_PROGRAMMING(void)
{
    const char *input = "PROGRAMMING";
	size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
	memcpy(output, input, size);
    alphabet_soup(output);

    test_result("test_PROGRAMMING", output, "AGGIMMNOPRR");

    free(output);
}

/******************************************************************************
 * Run all tests and display the results
 *****************************************************************************/
void tests_all(void)
{
    test_alphabet();
	test_Sensitive();
	test_encyclopedia();
	test_Windows();
	test_WordReference();
	test_PROGRAMMING();

    printf("Tests Passed:   %d\n", pass);
	printf("Tests Failed:   %d\n", fail);
	printf("Tests Executed: %d\n", executed);
}
