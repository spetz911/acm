#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>


using namespace std;


typedef pair<int,int> tuple;

/* qsort example */
int
compare1(const void * a, const void * b)
{
	int A = *(unsigned short*)a;
	int B = *(unsigned short*)b;
	
	return ( A - B );
}

bool test(int k)
{
	
	return false;
}

unsigned short M[100500];

int
main()
{
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> M[i];
	}
	

	qsort (M, n, sizeof(unsigned short), compare1);
	
	int k,z;
	string s;
	cin >> s >> k;
	
//	cout << "s = " << s << endl;
	
	for (int i=0; i<k; i++) {
		cin >> z;
		cout << M[z-1] << endl;
	}
	
	return 0;
}

