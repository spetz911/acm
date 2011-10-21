#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;


typedef pair<int,int> tuple;

/* qsort example */
int
compare1(const void * a, const void * b)
{
	return ( ((tuple*)a)->first - ((tuple*)b)->first  );
}

int
compare2(const void * a, const void * b)
{
	return ( ((tuple*)a)->second - ((tuple*)b)->second  );
}

bool test(int k)
{

	return false;
}

tuple M[100500];

const double PI = acos(-1.0);

int
main()
{
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> M[i].first;
		M[i].second = i;
	}

	qsort (M, n, 2*sizeof(int), compare1);

	
	int k = 0;
	long long z = 1;
	for (int i=0; ; i++) {
		z += i;
		while (z >= M[k].first) {
			if (z == M[k].first) {
				M[k++].first = 1;
			} else if (z > M[k].first) {
				M[k++].first = 0;
			}
		if (k >= n)	break;
		}
	if (k >= n)	break;
	}

	qsort (M, n, 2*sizeof(int), compare2);

	for (int i=0; i<n; i++) {
		cout << M[i].first << " ";
	}
	cout << endl;
	
	
	return 0;
}

