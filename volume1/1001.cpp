#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double M[256000];

int
main()
{
	int m = 0;
	while(cin >> M[m++]){}
	int i;
	for(i=m-2; i>=0; i--)
	{
		printf("%.4lf\n", sqrt(M[i]));
	}
	
	return 0;
}

