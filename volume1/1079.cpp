#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double M[100500];
int m = 0;

long long test(int n)
{
	long long max = 1;
	m = 0;
	M[m++] = 0;
	M[m++] = 1;
	
	for (int i=1; i<=n/2; i++) {
		M[m++] = M[i];
		M[m++] = M[i] + M[i+1];
	}
	
	for (int i=1; i<=n; i++) {
		if (max<M[i]) {max = M[i];}
	}
	return max;
}


int
main()
{
	int n;
	cin >> n;
	while(n != 0) {
		cout << test(n) << endl;
		cin >> n;
	}

	return 0;
}

