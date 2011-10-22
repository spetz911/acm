#include<stdio.h>

#define abs(A) ((A<0)?(-A):(A))


int left(int pos, int out)
{
	while (pos!=out && !L[pos]) ++pos;
	return pos;
}

int left(int pos, int out)
{
	while (pos!=out && !L[pos]) --pos;
	return pos;
}

char L[2002];


int main() {
	int pos, out, n;
	pos = 1000;
	scanf("%d%d", &n, &out);
	out += 1000;
	for (int i=0; i<n; ++i) {
		scanf("%d", &L[i+1000]);
	}

	int i = right(pos, out);
	if (i == out)
		printf("%d ", abs(pos-i));
	else {
		int j = left(i, out);
		if (j == out)
			printf("%d ", abs(2*i-j));
		else {
			printf("Impossible\n");
			return 0;
		}
	}

	i = left(pos, out);
	if (i == out)
		printf("%d\n", abs(pos-i));
	else {
		int j = right(i, out);
		if (j == out)
			printf("%d\n", abs(2*i-j));
		else {
			printf("Impossible\n");
			return 0;
		}
	}
	
	
	fgets(s, 4001, stdin);
	
//	gen_table(strlen(s) - 1);
	
	solve(0, strlen(s) - 2);
	printf("%d\n", r[0][strlen(s) - 2]);
	printr(0, strlen(s) - 2);
	printf("\n");
	return 0;
} 
