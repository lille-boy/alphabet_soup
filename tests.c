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
			printf("%s: fail - %s\n", test_name, output);
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
    alphabet_soup(output, DEFAULT);

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
    alphabet_soup(output, DEFAULT);

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
    alphabet_soup(output, DEFAULT);

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
    alphabet_soup(output, DEFAULT);

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
    alphabet_soup(output, DEFAULT);

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
    alphabet_soup(output, DEFAULT);

    test_result("test_PROGRAMMING", output, "AGGIMMNOPRR");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_you_know_who(void)
{
    const char *input = "you-know-who";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, DEFAULT);

    test_result("test_you_know_who", output, "--hknooouwwy");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_AirFrance1(void)
{
    const char *input = "AirFrance1";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, DEFAULT);

    test_result("test_AirFrance1", output, "1AaceFinrr");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_TomAndJerry(void)
{
    const char *input = "Tom&Jerry";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, DEFAULT);

    test_result("test_TomAndJerry", output, "&eJmorrTy");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_long_string(void)
{
    const char *input = "PvpxixCDvgnkLHQLlBvsJzgQLDmBxUeIhyUMvDiVpjCYvOshnaEvupb";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, DEFAULT);

    test_result("test_long_string", output, "aBBbCCDDDEeggHhhIiiJjkLLLlMmnnOPpppQQssUUuVvvvvvvxxxYyz");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_cbaBAC(void)
{
    const char *input = "cbaBAC";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, IGNORE_CASE);

    test_result("test_cbaBAC", output, "ABCabc");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_Casing(void)
{
    const char *input = "Casing";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, IGNORE_CASE);

    test_result("test_Casing", output, "Cagins");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_ILoveParis(void)
{
    const char *input = "ILoveParis";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, IGNORE_CASE);

    test_result("test_ILoveParis", output, "ILPaeiorsv");

    free(output);
}

/******************************************************************************
 * test
 *****************************************************************************/
static void test_longer_string(void)
{
    const char *input = "RvpxiCDgnkLHQlBsJzgQLmBxUeSIhyUMvADiVjCYOshnaEvub";
    size_t size = strlen(input) + 1;
    char *output = (char*)malloc(size * sizeof(char));
    memcpy(output, input, size);
    alphabet_soup(output, IGNORE_CASE);

    test_result("test_longer_string", output, "ABBCCDDEHIJLLMOQQRSUUVYabegghhiijklmnnpssuvvvxxyz");

    free(output);
}

/******************************************************************************
 * Run all tests and display the results
 *****************************************************************************/
void tests_all(void)
{
    /* DEFAULT option */
    test_alphabet();
    test_Sensitive();
    test_encyclopedia();
    test_Windows();
    test_WordReference();
    test_PROGRAMMING();
    test_you_know_who();
    test_AirFrance1();
    test_TomAndJerry();
    test_long_string();
    /* IGNORE_CASE option*/
    test_cbaBAC();
    test_Casing();
    test_ILoveParis();
    test_longer_string();

    printf("Tests Passed:   %d\n", pass);
    printf("Tests Failed:   %d\n", fail);
    printf("Tests Executed: %d\n", executed);
}
