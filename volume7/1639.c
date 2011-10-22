#include <stdio.h>

int main()
{
	int m,n;
	scanf("%d%d", &m, &n);
	if ((m*n)%2)
		printf("[second]=:]\n");
	else
		printf("[:=[first]\n");
	return 0;
}
