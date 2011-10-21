#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;


int A[100500];
int B[100500];



int
main()
{
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++) A[i] = 0;
	for (int i=0; i<n; i++) B[i] = 0;
	
	int a,b,c;
	for (int i=0; i<=n; i++) {
		cin >> a >> b >> c;
		A[a-1] += c;
		B[b-1] += c;
//		if ((a+i <= n)and(b+i > n)) summ += c;
	}


	
	long long summ = 0;
	for (int i=0; i<n; i++) {
		summ += A[i];
		cout << summ << " ";
		summ -= B[i];
	}
	cout << endl;
	
	return 0;
}

