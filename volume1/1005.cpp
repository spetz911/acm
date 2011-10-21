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
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> M[i];
	}

//	sort(M, n);
	int min = 100000;
	
	for(int i=0; i<(1<<n); i++){
		long long sum = 0;
		for(int j=0; j<n; j++){
			if ((i&(1<<j)) == 0)
				sum += M[j];
			else
				sum -= M[j];
			if (abs(sum > 100000)) {break;}
		}
		sum = abs(sum);
		if (sum < min)
			min = sum;
	}
	


	
	
//	for(int i=0; i<n; i++){
//		cout << M[i] << " ";
//	}

	cout << min << endl;


	
//	cout << M[0] << endl;
	
//	cin >> m >> n >> k;
//	printf("%d\n", 2*m*n*k );
	
	return 0;
}

