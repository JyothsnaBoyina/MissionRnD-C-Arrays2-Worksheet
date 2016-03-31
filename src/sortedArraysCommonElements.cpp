/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *temp;
	temp = (struct transaction*)malloc(sizeof(struct transaction));
	int i = 0, j = 0, d = 0, m = 0, y = 0, d1 = 0, m1 = 0, y1 = 0, k = 0;

	if (A == NULL || B == NULL)
		return NULL;

	for (; i < ALen&&j < BLen;)
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

		if (y<y1)
			i++;
		else if (m < m1&&y == y1)
			i++;
		else if (d < d1&&m == m1&&y == y1)
			i++;
		else if (d == d1&&m == m1&&y == y1)
		{
			*(temp + k) = *(A + i);
			i++;
			j++;
			k++;
		}
		else
			j++;
	}
	if (k>0)
		return temp;
	else
		return NULL;
}