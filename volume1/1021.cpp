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

int A[100500];
int a = 0;
int B[100500];
int b = 0;

int
main()
{
	long long n, m;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> A[a++];
	}

	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> B[b++];
	}
	
	int z = 0;
	while ((z != 10000)and(a>=0)and(b>=0)and false) {
		z = A[a] + B[b];
		int z1 = A[a] + B[b-1];
		int z2 = A[a-1] + B[b];
		if (abs(z2-10000) < abs(z1-10000)) a--;
		else b--;
	}
	
	for (int i=0; i<a; i++) {
		j = 0;
		while(A[i] + B[j++] < 10000)
			if ( )
	
	}
	
	
	

	cout << ((z==10000)?"YES":"NO") << endl;

	return 0;
}
