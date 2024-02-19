//Test program to check prime numbers program with all possible test cases.

#include <stdio.h>
#include "prime.c"
#define LENGTH 20

void showFailedTestCase(char *value)
{
	printf("%s is failed.", value);
}

void showTestCasePassedMesssage()
{
	printf("All test cases passed.");
}

void main()
{
	char *testCases[14] = {"a", " ", ",", "@", "D", "-17", "1", "0", "2", "51", "658", "71", "jaga", "24ab"};
	int expectedResult[14] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0};
	int counter;
	int isAllTestCasesPassed = 1;
	for(counter = 0; counter < 14; counter++)
	{
		
		int result = isPrimeNumber(testCases[counter]);
		if(!(result == expectedResult[counter]))
		{
			isAllTestCasesPassed = 0;
			showFailedTestCase(testCases[counter]);
		}

	}

	if(isAllTestCasesPassed)
	{
		showTestCasePassedMesssage();
	}

}

