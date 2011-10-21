#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long ipow( int a, int n)
{
	long long z = 1;
	for (int i=0; i<n; i++) {
		z*=a;
	}
	return z;
}

int M[20];

int
main()
{
	long long n, k;
	cin >> n >> k;
	M[0] = 1;
	M[1] = k-1;

	for (int i=2; i<=n; i++) {
		M[i] = (k-1) * (M[i-1]+M[i-2]);
	}

	cout << M[n] << endl;

	return 0;
}

