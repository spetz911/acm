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

int
main()
{
	int n;
	cin >> n;
	
	if (n == 0) {
		cout << 10 << endl;
		return 0;
	}
	
	
	if (n<10) {
		cout << n << endl;
		return 0;
	}
	
//	gen_primes(ceil(sqrt(n+1)));
	
	int X[10];
	
	
	for (int i=9; i>=2; i--){
		X[i] = 0;
		while (n%i == 0){
			X[i] += 1;
			n /= i;
		}
	}
	
	//~ while (X[2]>0 and X[9]>0) {
		//~ X[3] += 1;
		//~ X[6] += 1;
		//~ X[2] -= 1;
		//~ X[9] -= 1;
	//~ }
	
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
	
}

