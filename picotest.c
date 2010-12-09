#include <stdio.h>

#define RUN_TEST(test) do { char *output = test(); tests_run++; \
                               if (output) return output; } while (0)
#define TEST_ASSERT(message, test) do { tests_run++; if (!(test)) { tests_failed++; printf("FAIL \t %s\n",message);} else { tests_passed++; printf("PASS \t %s\n",message);} } while (0)

#define MAX_TESTS 99

extern int tests_run;
extern int tests_passed;
extern int tests_failed;

void* tests[MAX_TESTS];

int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

int numTests = 0;

void addTest(void* test)
{
	void (*tempTest) = test;
	tests[numTests] = tempTest;
	numTests++;
}

int executeTestSuite()
{
	printf("Test Results\n===============================================================================\n");
	
	int i;
	for (i = 0; i < numTests; i++)
	{
		void (*tempTest)() = tests[i];
		tempTest();
	}
	
	printf("\n--\nNumber of tests run: %d\n", tests_run);
	printf("Number of tests passed: %d\n", tests_passed);
	printf("Number of tests failed: %d\n\n", tests_failed);
	
	return 0;
}
