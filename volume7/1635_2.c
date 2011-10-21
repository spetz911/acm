#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[4010];
short r[4010][4010];
short d[4010][4010];
char is_palindr(int i, int j) {
while(i < j) {
if(s[i] != s[j]) {
return 0;
}
i++; j--;
}
return 1;
}
short solve(int i, int j) {
if(r[i][j] > 0) {
return r[i][j];
} else {
if(is_palindr(i, j)) {
r[i][j] = 1;
d[i][j] = -1;
return 1;
} else {
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
}
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
solve(0, strlen(s) - 2);
printf("%d\n", r[0][strlen(s) - 2]);
printr(0, strlen(s) - 2);
printf("\n");
return 0;
} 
