#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int M[200][200];

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

int
main()
{
	int n;
	cin >> n;
	
	if (n<10) {
		cout << n << endl;
		return 0;
	}
	
	gen_primes(ceil(sqrt(n+1)));
	
	int X[10];
	
	
	for (int i=9; i>=2; i--){
		X[i] = 0;
		while (n%i == 0){
			X[i] += 1;
			n /= i;
		}
	}
	
	if (n != 1) {
		cout << -1 << endl;
		return 0;
	}
	
	for (int i=2; i<=9; i++){
		for (int j=0; j<X[i]; j++)
			cout << i;
	}
	cout << endl;
		
	
	return 0;

	
	for(int j=0; j<p; j++)
		cout << P[j] << " ";
	cout << endl;
	

	int a = 1;

	for(int i=-n; i<n; i++){
		for(int j=-n; j<n; j++)
			if ((i+j<n)and(i+j>=0) and (i-j>=0) and (i-j<n))
				M[i+j][i-j] = a++;
		for(int j=-n; j<n; j++)
			if ((i+j<n)and(i+j>=0) and (i-j+1>=0) and (i-j+1<n))
				M[i+j][i-j+1] = a++;
	}

	for(int i=0; i<n; i++){
		for(int j=n-1; j>=0; j--)
			cout << M[i][j] << "\t";
		cout << endl;
	}

	return 0;

	
	for(int i=0; i<a; i++)
		cout << M[i] << " ";
	cout << endl;
	
	
	return 0;
}

