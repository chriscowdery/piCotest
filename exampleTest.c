#include "picotest.h"

void *test_two_equals_one()
{
  TEST_ASSERT("Two equals one test", 2 == 1);
  return 0;
}

void *test_one_plus_one()
{
  TEST_ASSERT("One plus one test", 1+1 == 2);
  return 0;
}


int main(int ac, char **av)
{
	initializePicotest();
	addTest(test_two_equals_one);
	addTest(test_one_plus_one);
	
	executeTestSuite();
	
	return 0;
}