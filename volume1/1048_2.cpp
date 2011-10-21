#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long A[1000000];
unsigned long long B[1000000];



unsigned long long ipow(int a, int z)
{
	unsigned long long res = 1;
	for (int i=0;i<z;i++) {
		res *=a;
	}
	return res;
}

const int K = 2;
const unsigned long long POW = ipow(10, K);


int
main()
{
	int n;
	cin >> n;
	
	int a, b;
//	long long z;
	
	for (int i=0; i<n;) {
		A[i] = 0;
		B[i] = 0;
		for (unsigned long long t = 1; t < POW; t *= 10) {
			cin >> a >> b;
			A[i] += a*t;
			B[i] += b*t;
			i++;
			if (i == n) break;
		}
	}
	
	int shift = 0;
	
	for (int i=n; i>=0; i--) {
		A[i] += B[i] + shift;
		shift = A[i] / POW;
		A[i] %= POW;
	}
	
	for (int i=0; i<= n/K; ++i) {
		cout << A[i];
	}
//	cout << A[n/K + 1] / (n%K) << endl;
	cout << endl;
	
	return 0;
}

