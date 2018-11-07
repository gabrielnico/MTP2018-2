/* P4.c */
/* Gabriel Nogueira Nico */
/* 11811EEL012 */

#include <stdio.h>

int recursion(int m, int n);

int main()
{
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	
	printf("\n%d", recursion(m, n));
	return 0;
}

int recursion(int m, int n)
{
	if(m == 0)
		return (n + 1);
	else if(m > 0 && n == 0)
		recursion(m - 1, 1);
	else
		recursion(m - 1, recursion(m, n - 1));
}
