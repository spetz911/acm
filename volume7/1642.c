#include<cstdio>

#define true 1
#define false 0

int abs9(int a)
{
	if (a<0) return -a;
	else return a;
}


char L[2002];



int right(int pos, int out)
{
	while (pos!=out && !L[pos]) ++pos;
	return pos;
}

int left(int pos, int out)
{
	while (pos!=out && !L[pos]) --pos;
	return pos;
}

int main() {
	int pos, out, n, i, z;
	pos = 1000;
	scanf("%d%d", &n, &out);
	out += 1000;
	for (i=0; i<n; ++i) {
		scanf("%d", &z);
		L[z+1000] = true;
	}

	i = right(pos, out);
	if (i == out)
		printf("%d ", abs9(pos-out));
	else {
		int j = left(i-1, out);
		if (j == out)
			printf("%d ", abs9(pos-i)+abs9(i-out));
		else {
			printf("Impossible\n");
			return 0;
		}
	}

	i = left(pos, out);
	if (i == out)
		printf("%d\n", abs9(pos-i));
	else {
		int j = right(i+1, out);
		if (j == out)
			printf("%d\n", abs9(pos-i)+abs9(i-j));
		else {
			printf("Impossible\n");
			return 0;
		}
	}

	return 0;
} 
