#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int
main()
{
	long long n;
//	unsigned char c;
	cin >> n;
	
	int k = 0;
	getchar();
	while(getchar() == '!'){
		k++;
	}

	int z = 1;

	for(int i=n; (i>=n%k)and(i>0); i-=k)
		z *= i;
	
	cout << z << endl;

	return 0;
}

