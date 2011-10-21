#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double M[256000];

long long test(int z, int sum, int digit)
{
	if (digit == 0)
		return (z == sum);
	
	long long count = 0;
	for (int i=0; i<10; i++)
		count += test(z+i, sum, digit -1);
	return count;
}

int dec(int z)
{
	int count = 0;
	
	while (z>0) {
		count += z%10;
		z /= 10;
	}
	return count;
}

long long ipow(int a, int z)
{
	long long res = 1;
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
	
	int m = n/2;
	
	long long count = 0;
	
	for (int i=0; i < ipow(10, m); i++)
		count += test(0, dec(i), m);
	
	if (n%2 == 0){
		cout << count << endl;
	} else {
		cout << count*10 << endl;
	}
	
	return 0;
}

