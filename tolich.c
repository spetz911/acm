#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[4010];
char buf[4010];
char ds[8020];
int r[4010], p[4010];
char ip[4010][4010];

char is_palindr(int i, int j) {
	char res = (s[i] == s[j]);
	if(j - i > 1) {
		res = res && ip[i+1][j-1];
	}
	ip[i][j] = res;
	return res;
}

int main() {
	int i, j, l, dsl;
	fgets(buf, 4001, stdin);
	i=0; l=0;
	while('a' <= buf[i] && buf[i] <= 'z') {
		s[++l] = buf[i];
		i++;
	}
	for(i=1;i<=l;i++) {
		ip[i][i] = 1;
	}
	r[0] = 0; p[0] = 0;
	r[1] = 1; p[1] = 0;
	for(i=2;i<=l;i++) {
		int d = i - 1, dt = r[i-1] + 1;
		for(j=i-1;j>=1;j--) {
			if(is_palindr(j, i)) {
				if(r[j-1] + 1 < dt) {
					dt = r[j-1] + 1;
					d = j - 1;
				}
			}
		}
		r[i] = dt; p[i] = d;
	}
	printf("%d\n", r[l]);
	j = p[l];
	dsl = 0;
	for(i=l;i>=1;i--) {
		if(i == j) {
			ds[dsl++] = ' ';
			j = p[i];
		}
		ds[dsl++] = s[i];
	}
	for(i=dsl-1;i>=0;i--) {
		printf("%c", ds[i]);
	}
	printf("\n");
	return 0;
}
