#include <stdio.h>

int digit(int num, int d)
{
	while (d>0) {
		num /= 10;
		--d;
	}
	return num % 10;
}

int test(int a)
{
	int i, count = 0;
	for (i=0; i<3;++i)
		count += digit(a, i);
	for (i=3; i<6;++i)
		count -= digit(a, i);
	return !count;
}



int
main()
{
	int a = 445219;
	scanf("%d", &a);
	if (test(a+1) || test(a-1))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
