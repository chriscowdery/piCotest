#include "picotest.h"

void initializePicotest()
{
	tests_run = 0;
	tests_passed = 0;
	tests_failed = 0;
	numTests = 0;
}

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
