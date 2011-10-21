#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct mars
{
	int pos;
	int M[100];
	int m;
	int num;
	mars()
	:m(0)
	{}
	mars(int p)
	:pos(p), m(0), num(p)
	{}
	void append(int z)
	{
		M[m++] = z;
	}
	
	int child(mars *A[], int j)
	{
		return A[M[j]]->pos;
	}
	
};

mars *A[100];

inline void swap(int &a, int &b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}


void my_sort(int n)
{
	int count = 1;
	while(count > 0){
		count = 0;
		for (int i=0; i<n; i++) {
			int min = A[i]->pos;
			int place = i;
			for (int j = 0; j < A[i]->m; ++j) {
				int child_pos = A[i]->child(A, j);
				if (child_pos < min) {
					min = child_pos;
					place = A[i]->M[j];
				}
			}
			if (place != i) {
				count += 1;
				swap(A[i]->pos, A[place]->pos);
	//			swap(A[i], A[min]);
			}
		}
	}
}

int
find_ch(int pos, int n)
{
	for (int i=0; i<n; i++) {
		if (A[i]->pos == pos) return i;
	}
	return 0;
}



int
main()
{
	int n, z;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		A[i] = new mars(i);
		cin >> z;
		while (z != 0) {
			A[i]->append(z-1);
			cin >> z;
		}
		A[i]->append(0);
		A[i]->m--;
	}
	
	my_sort(n);
	
	for (int i=0; i<n; i++) {
		cout << find_ch(i, n) + 1 << " ";
	}
	cout << endl;
	return 0;
}
