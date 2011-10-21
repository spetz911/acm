#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long P[15001];
int p = 0;

void gen_primes(int n)
{
	p = 0;
	for (long long i=2; ; i++) {
		bool test = true;
		for (int j = 0; j<p; j++) {
			if (i % P[j] == 0) {
				test = false;
				break;
			}
		}
		if (test)	P[p++] = i;
		if (p == n) return;
	}
}

int
main()
{
	gen_primes(15001);
	int n, k;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		cin >> k;
		cout << P[k-1] << endl;
	}
	
	return 0;
}

