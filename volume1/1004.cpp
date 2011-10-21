#include <iostream>
#include <cstdio>
#include <cmath>



using namespace std;

void INVARIANT(bool A)
{
	if(!A) cerr << "FAIL" << endl;
}

const int SIZE = 100;

struct cross {
	int R[SIZE];
	int r;
	bool mark;
	cross()
	:r(0), mark(false)
	{}
	void append(int i)
	{
		R[r++] = i;
	}
};


long long M[SIZE][SIZE];
cross P[SIZE];

int marker[SIZE];

int len(int a, int b, int l)
{
	if (M[a][b] != 0) return M[a][b];

	if (marker[a] == 1) return 0;
	marker[a] = 1;
	
	int min = 1000000000;
	int p_min = -1;
	for (int i=0; i<P[a].r; i++)
	{
		int p2 = P[a].R[i];
		long long way;
		if (p2 == b) {
			if (l>1) return M[a][p2];
			else continue;
		}
		if (marker[p2] == 1) continue;
		int dist = len(p2, b, l+1);
		way = M[a][p2] + dist;
		if ((dist>0) and (way < min)) {
			INVARIANT(way != 0);
			min = way;
			p_min = p2;
		}
	}
	
	
	if (p_min != -1) {
		M[a][b] = min;
		M[b][a] = min;
		return min;
	} else {
		M[a][b] = -1;
		M[b][a] = -1;
		return -1;
	}
}

int Way[100];
int way = 0;


bool find_way(int start, int finish, int size)
{
	if (size < 0)
		return false;

	if ((start == finish)and(size == 0)) {
		Way[way++] = start;
		return true;
	}

	
	for (int i=0; i<P[start].r; i++)
	{
		int p2 = P[start].R[i];
		
		INVARIANT(M[start][p2] > 0);
		if (find_way(p2, finish, size - M[start][p2])) {
			Way[way++] = p2;
			return true;
		}
	}
	return false;
}



void
print_m(long long M[SIZE][SIZE], int n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout << M[i][j] << '\t';
		cout << endl;
	}
}

void clean_marks(int n) {
	for (int j=0; j<n; j++)
			marker[j] = 0;
}

int
test()
{
	long long n, m;
	int a,b,c;
	cin >> n;
	if (n == -1) return -1;
	cin >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j] = 0;
	
	for (int i=0; i<m; i++) P[i].r = 0;
	
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
//		cout << "SHHI " << a << ' ' << b << ' ' << c << endl;
		a--; b--;
		if (M[a][b] > 0){
			if (c<M[a][b]) {
				M[a][b] = c;
				M[b][a] = c;
			}
		} else {
			M[a][b] = c;
			M[b][a] = c;
			P[a].append(b);
			P[b].append(a);
		}
	}
	
	print_m(M,n);
	
	
	int res = len(0,0,0);
	cout << "res = " << res << endl;
	
	print_m(M,n);
	
	clean_marks(n);
	int min = len(0,0,0);
	int index = 0;
	
	for (int i=0; i<n; i++) {
		clean_marks(n);
		int dist = len(i,i,0);
		if (dist < min) {
			min = dist;
			index = i;
		}
	}
	
	if (min == -1) {
		cout << "No solution." << endl;
		return 0;
	}
	//!else
	way = 0;
	find_way(index, index, min);
	for (int i=way; i>0; --i)
		cout << Way[i] << " ";
	cout << endl;
	

//	cout << ((z==10000)?"YES":"NO") << endl;

	return 0;
}

int main()
{
	while(test() != -1) {}
	return 0;
}

