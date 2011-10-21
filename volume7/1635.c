#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[4010];
short r[4010][4010];
short d[4010][4010];
int p[4010][4010];

int test(int i, int j)
{
	if (p[i][j]>=0) return p[i][j];
	
	if (j<=i) return (p[i][j] = 1);
	
	if (s[i] == s[j])
		p[i][j] = test(i+1,j-1);
	else
		p[i][j] = 0;
	
	return p[i][j];
}


void gen_table(int n)
{
	int i,j;
	for (i=0;i<n;++i)
		for (j=0;j<n;++j)
			p[i][j] = -1;

//	for (i=0;i<n;++i)
//		for (j=0;j<n;++j)
//			test(i,j);
}

inline char is_palindr(int i, int j)
{
	return p[i][j];
}

char is_palindr2(int i, int j) {
//	if (p[i][j]>=0) return p[i][j];
	short a = i, b = j;
	while(i < j) {
		if(s[i] != s[j]) {
//		p[i][j] = 0;
//		p[a][b] = 0;
		return 0;
		}
		i++; j--;
	}
//	p[a][b] = 1;
	return 1;
}

short solve(int i, int j) {
	if(r[i][j] > 0) return r[i][j];
	
	if(is_palindr2(i, j)) {
		r[i][j] = 1;
		d[i][j] = -1;
		return 1;
	}
	int kt, k = -1;
	short lt, l = 4010;
	for(kt=i;kt<j;kt++) {
		lt = solve(i, kt) + solve(kt+1, j);
		if(lt < l) {
			l = lt;
			k = kt;
			if(l == 1) {
				break;
			}
		}
	}
	r[i][j] = l;
	d[i][j] = k;
	return r[i][j];

}

void printr(int i, int j) {
int k;
if(d[i][j] == -1) {
	for(k=i;k<=j;k++) {
		printf("%c", s[k]);
	}
} else {
		printr(i, d[i][j]);
		printf(" ");
		printr(d[i][j] + 1, j);
	}
}
int main() {
	fgets(s, 4001, stdin);
	
//	gen_table(strlen(s) - 1);
	
	solve(0, strlen(s) - 2);
	printf("%d\n", r[0][strlen(s) - 2]);
	printr(0, strlen(s) - 2);
	printf("\n");
	return 0;
} 
