/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int d=0, m=0, y=0,d1=0,m1=0,y1=0,i=0,count=0;
	
			d = d + ((*(date + 0) - '0')*10);
			d = d + (*(date + 1) - '0');
			m = m + ((*(date + 3) - '0') * 10);
			m = m + (*(date + 4) - '0');
			y = y + ((*(date + 6) - '0') * 1000);
			y = y + ((*(date + 7) - '0') * 100);
			y = y + ((*(date + 8) - '0') * 10);
			y = y + ((*(date + 9) - '0') * 1);


	for(i = 0; i < len; i++)
	{
		d1 = 0;
		m1 = 0;
		y1 = 0;
		d1 = d1 + (((Arr[i].date[0]) - '0') * 10);
		d1 = d1 + ((Arr[i].date[1]) - '0');
		m1 = m1 + (((Arr[i].date[3]) - '0') * 10);
		m1 = m1 + ((Arr[i].date[4])- '0');
		y1 = y1 + (((Arr[i].date[6]) - '0') * 1000);
		y1 = y1 + (((Arr[i].date[7]) - '0') * 100);
		y1 = y1 + (((Arr[i].date[8]) - '0') * 10);
		y1 = y1 + ((Arr[i].date[9]) - '0');

		if (y1 > y)
			count++;
		else if (y1 == y&&m1 > m)
			count++;
		else if (y1 == y&&m1 == m&&d1 > d)
			count++;
	}
	return count;

}
