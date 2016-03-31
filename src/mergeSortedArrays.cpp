/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *temp;
	temp = (struct transaction*)malloc((ALen+BLen)*sizeof(struct transaction));
    int i=0,j=0,d=0,m=0,y=0,d1=0,m1=0,y1=0,k=0;

	if (A == NULL || B == NULL)
		return NULL;

	for (k = 0;i<ALen&&j<BLen;k++)
	{
		d = 0;
		m = 0;
		y = 0;
		d = d + (((A[i].date[0]) - '0') * 10);
		d = d + ((A[i].date[1]) - '0');
		m = m + (((A[i].date[3]) - '0') * 10);
		m = m + ((A[i].date[4]) - '0');
		y = y + (((A[i].date[6]) - '0') * 1000);
		y = y + (((A[i].date[7]) - '0') * 100);
		y = y + (((A[i].date[8]) - '0') * 10);
		y = y + ((A[i].date[9]) - '0');

		    d1 = 0;
			m1 = 0;
			y1 = 0;
			d1 = d1 + (((B[j].date[0]) - '0') * 10);
			d1 = d1 + ((B[j].date[1]) - '0');
			m1 = m1 + (((B[j].date[3]) - '0') * 10);
			m1 = m1 + ((B[j].date[4]) - '0');
			y1 = y1 + (((B[j].date[6]) - '0') * 1000);
			y1 = y1 + (((B[j].date[7]) - '0') * 100);
			y1 = y1 + (((B[j].date[8]) - '0') * 10);
			y1 = y1 + ((B[j].date[9]) - '0');

			if (y < y1)
			{
				*(temp + k) = *(A + i);
				i++;
			}
			else if (m<m1&&y == y1)
			{
				*(temp + k) = *(A + i);
				i++;
			}
			else if (d<d1&&m == m1&&y == y1)
			{
				*(temp + k) = *(A + i);
				i++;
			}
			else if (d == d1&&m == m1&&y == y1)
			{
				*(temp + k) = *(A + i);
				k++;
				*(temp + k) = *(B + j);
				i++;
				j++;
			}
			else
			{
				*(temp + k) = *(B + j);
				j++;
			}

}
	if (i<ALen)
	for (; k < ALen + BLen; k++)
	{
		*(temp + k) = *(A + i);
		i++;
	}
	else if (j<BLen)
		for (; k < ALen + BLen; k++)
		{
			*(temp + k) = *(B + j);
			j++;
		}
		

	return temp;
}