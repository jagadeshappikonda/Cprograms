//Program to find a number is prime or not.

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define LENGTH 20

int isAllDigits(char *value)
{
	while(*value)
	{
		if(!isdigit(*value))
		{
			return 0;
		}
		value++;
	}
	return 1;
}

int isPrimeNumber(char *value)
{
	int isDigit = isAllDigits(value);
	if(isDigit)
	{
		int number = atoi(value);
		if(number == 2)
		{
			return 1;
		}
		else if(number <= 1 || (number % 2 == 0))
		{
			return 0;
		}
		else
		{
			int counter = 3;
			double squareRoot = sqrt(number);
			while(counter <= squareRoot)
			{
				if(number % counter == 0)
				{
					return 0;
				}
				counter += 2;
			}
		}
		
		return 1;
	}
	else
	{
		return 0;
	}
}

