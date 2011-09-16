#ifndef PICOTEST_H
#define PICOTEST_H

#include <stdio.h>

void addTest(void* test);
int executeTestSuite();
void initializePicotest();

#define RUN_TEST(test) do { char *output = test(); tests_run++; \
                               if (output) return output; } while (0)
#define TEST_ASSERT(message, test) do { tests_run++; if (!(test)) { tests_failed++; printf("FAIL \t %s\n",message);} else { tests_passed++; printf("PASS \t %s\n",message);} } while (0)

#define MAX_TESTS 99

extern int tests_run;
extern int tests_passed;
extern int tests_failed;

void* tests[MAX_TESTS];

int tests_run;
int tests_passed;
int tests_failed;

int numTests;

#endif