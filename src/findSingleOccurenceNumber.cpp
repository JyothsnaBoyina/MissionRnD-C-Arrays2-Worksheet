/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdlib.h>
int findSingleOccurenceNumber(int *A, int len) {
	int i = 0,big,*p;

	if (A==NULL)
		return -1;
	big = A[0];
	for (i = 0; i < len; i++)
	{
		if (A[i]>big)
			big = A[i];
	}

	p = (int*)calloc(big+1, sizeof(int));

	for (i = 0; i < len; i++)
	{
		*(p + (A[i])) = *(p + (A[i]))+1;
	}
	for (i = 0; i < big+1; i++)
	{
		if (*(p + i) == 1)
		{
			return i;
			break;
		}
	}
	return -1;
}