#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

unsigned char A[1000001];
unsigned char B[1000001];

unsigned long long ipow(int a, int z)
{
	unsigned long long res = 1;
	for (int i=0;i<z;i++) {
		res *=a;
	}
	return res;
}

int
main()
{
	int n;
	cin >> n;
	
	int a, b;
	
	for (int i=0; i<n; ++i) {
			cin >> a >> b;
			A[i] = a;
			B[i] = b;
	}
	
	int shift = 0;
	for (int i=n; i>=0; --i) {
		A[i] += B[i] + shift;
		shift = A[i] / 10;
		A[i] = A[i] % 10 + '0';
	}
	
	A[n] = '\0';
	
	cout << A;
	
	cout << endl;
	
	return 0;
}

