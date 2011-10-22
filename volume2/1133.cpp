#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


long long F[3000];
bool T[3000];

inline void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

long long left(int n)
{
	if (T[n]) return F[n];
	F[n] = -left(n-1) + left(n-2);
	T[n] = true;
	return F[n];
}

long long right(int n)
{
	if (T[n]) return F[n];
	F[n] = right(n+2) + right(n+1);
	T[n] = true;
	return F[n];
}


long long test(int i, int j, int n)
{
	if (n == i) return F[i];
	if (n == j) return F[j];
	
	if (n > j) return left(n);
	if (n < i) return right(n);
	//! else
	return right(n-1) + left(n+1);

}

int
main()
{
	int n,i,j,fi,fj;
	cin >> i >> fi >> j >> fj >> n;
	
	if (i>j) swap(fi, fj); swap(i,j);
	i += 1000;
	j += 1000;
	n += 1000;
	
	F[i] = fi; T[i] = true;
	F[j] = fj; T[j] = true;
	
	cout << test(i, j, n) << endl;

	return 0;
}

