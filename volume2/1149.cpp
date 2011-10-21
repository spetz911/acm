#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long P[15001];
int p = 0;

void write_ak(int k, int n)
{
	if (k == n) {
		cout << "sin(" << n << ")";
		return;
	}
	
	unsigned char c = (k%2==0)?'+':'-';
	cout << "sin(" << k << c;
	write_ak(k+1, n);
	cout << ')';
	return;
}

void write_sk(int k, int n)
{
	if (k == n) {
		write_ak(1, n-k+1);
		cout << '+' << k;
		return;
	}

	cout << '(';
	write_sk(k+1, n);
	cout << ')';

	write_ak(1, n-k+1);
	
	cout << '+' << k;
	return;
}



int
main()
{
	int n;
	cin >> n;
//	write_ak(1, n);
//	cout << endl;

	write_sk(1, n);
	cout << endl;

	return 0;
}

