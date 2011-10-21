#include <iostream>
#include <math>

using namespace std;

int
main()
{
	double M[128000];
	int m = 0;
	while(scanf("%lf", &M[m++])!=EOF){}
	int i;
	for(i=m-2; i>=0; i--)
	{
		printf("%.4lf\n", sqrt(M[i]));
	}
	
	return 0;
}
