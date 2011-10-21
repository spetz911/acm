#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int
main()
{
	int m = 0;
	cin >> m;
	if (m > 0){
		printf("%d\n", m*(m+1)/2 );
	} else {
		printf("%d\n", m*(-m+1)/2 + 1);	
	}
	
	return 0;
}

