#include <stdio.h>

using namespace std;

#define clean(A) (0x7fffffff & A)

#define set1(A) (0x80000000 | A)


int num[100001];
unsigned short prev[100001];
int p = 0;

int last[1001];

inline int index(int i)
{
	if (num[i] < 0)
		return 0x10000 | (int)prev[i];
	else
		return (int)prev[i];
}

void push(int key, int val)
{
	int a = last[key];

	num[p] = val;

	prev[p] = a & 0xffff;
	if (a>>16) {num[p] = set1(num[p]);}
	else {num[p] = clean(num[p]);}
	
	last[key] = p;
	p++;
}

int pop(int key)
{
	int a = last[key];
	int a1 = index(a);
	if (a1>>16) {num[a1] = set1(num[a1]);}
	else {num[a1] = clean(num[a1]);}
	last[key] = a1;

	return clean(num[a]);
}



char s[10];

int main()
{
	int n, b, a;
	scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		scanf("%s", s);
		if (s[1] == 'U') {
			scanf("%d%d", &a, &b);
			push(a, b);
		} else { //! POP
			scanf("%d", &a);
			printf("%d\n", pop(a));
		}
	}
}
