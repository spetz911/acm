#include <iostream>

using namespace std;

const int MAX = 33;

unsigned int M[182][MAX];

void sum(int a, int b, int c)
{
	unsigned int z = 0;
	for (int i=0; i<MAX; i++) {
		z += M[a][i] + M[b][i];
		M[c][i] = z % 100000000;
		z /= 100000000;
	}
}

char s[20];

int
main()
{
	int n, k;
	cin >> n >> k;
	M[1][0] = 1;
	M[2][0] = k-1;
	int i,j;
	for (i=3; i<=n+1; i++) {
//!		M[i][0] = (k-1)*(M[i-1][0] + M[i-2][0]);
		sum(i-1, i-2, 0);
		for (j=0; j<k-1; j++)
			sum(i, 0, i);
	}
	bool ok = false;
	for (int i= MAX-1; i>=0; --i) {
		if(ok) {
			for (int j=7; j>=0; j--) {
				s[j] = M[n+1][i]%10 + '0';
				M[n+1][i] /= 10;
			}
			s[8] = '\0';
			cout << s;
		}
		if(M[n+1][i]>0) {
			cout << M[n+1][i];
			ok = true;
		}
	}
	cout << endl;

	return 0;
}

