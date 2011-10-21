#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int M[200][200];


int
main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> M[i][j];

	for(int i=-n; i<n; i++){
		for(int j=-n; j<n; j++)
			if ((i+j<n)and(i+j>=0) and (i-j>=0) and (i-j<n))
				cout << M[i-j][i+j] << " ";
		for(int j=-n; j<n; j++)
			if ((i+j+1<n)and(i+j+1>=0) and (i-j>=0) and (i-j<n))
				cout << M[i-j][i+j+1] << " ";
	}
	cout << endl;
	
	return 0;
}

