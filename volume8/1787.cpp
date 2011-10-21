#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int
main()
{
	int n, k;
	int summ, z;
	cin >> k >> n;
	summ = 0;
	for(int i=0; i<n; i++) {
		cin >> z;
		summ += z;
		summ -= k;
		if (summ < 0) summ = 0;
	}
	cout << summ << endl;
	
	return 0;
}

