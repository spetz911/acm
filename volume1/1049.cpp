#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int P[9000];
int p = 0;

int gen_primes(int n)
{
	p = 0;
	for (int i=2; i<=n; i++){
		bool test = true;
		for (int j = 0; j<p; j++){
			if (i % P[j] == 0) {
				test = false;
				break;
			}
		}
		if (test)
			P[p++] = i;
	}
	return p;
}

int DIV[9000];


int
main()
{
	int a;
	
	gen_primes(10001);

	for (int i=0; i<p; ++i) DIV[i] = 0;
	int count = 1;
	
	for (int i=0; i<10; ++i) {
		cin >> a;
		for (int j=0; j<p; ++j) {
			while (a % P[j] == 0) {
				DIV[j]++;
				a /= P[j];
			}
		}
	}

	for (int i=0; i<p; ++i) {
		if (DIV[i] > 0)
			count *= (DIV[i]+1);
	}
	cout << count % 10 << endl;
	
	return 0;
}

