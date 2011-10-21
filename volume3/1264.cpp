#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int M[9000];

inline void swap(int &a, int &b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void sort(int A[], int n)
{
	int count = 1;
	while(count > 0){
		count = 0;
		for(int i=0; i<n-1; i++){
			if (A[i] > A[i+1]){
				swap(A[i], A[i+1]);
				count++;
			}
		}
	}
}

int summ(int A[], int m, int n)
{
	int count = 0;
	for(int i=m; i<n; i++){
		count += A[i]/2 + 1;
	}
	return count;
}


int
main()
{
	long long m, n;
	char c;
	cin >> n >> c;
	
	int k = 0;
	c = '!';
	while(c == '!'){
		cin >> c;
		k++;
	}

//	sort(M, n);

	
	
//	for(int i=0; i<n; i++){
//		cout << M[i] << " ";
//	}
	
	cout << "k =" << k << endl;


	
//	cout << M[0] << endl;
	
//	cin >> m >> n >> k;
//	printf("%d\n", 2*m*n*k );
	
	return 0;
}

