#include <iostream>
#include <cstring>


using namespace std;

char s[9000];
int Pal[9000];
int p = 0;

bool M[4000][4000];

bool
test(int a, int b)
{
	for (int i=0; i<(b-a)/2; i++) {
		if(s[a+i] != s[b-i-1])
			return false;
	}
	return true;
}

void
test2(int a, int b)
{
	int n = b-a;
	for (int l = n; l>0; --l) {
		for(int j = a; j<=b-l; j++) {
			if(test(j, j+l)) {
				test2(a, j);
				Pal[p++] = j+l;
				test2(j+l, b);
				return;
			}
		}
	}
	return;
}


void
insert(int a, int b)
{
	for (int i=0; i<p; i++) {
		if (Pal[i] == a) {
			Pal[i] = a;
			p = i+1;
			Pal[p++] = b;
			return;
		}
	}
	return;
}

void
show(int n)
{
	int j = 1;
	for (int i=0; i<n; i++) {
		cout << s[i];
		if (i+1 == Pal[j]) {
			cout << ' ';
			j++;
		}
	}
	cout << endl;
}

int
main()
{
	int n;
	cin.getline(s, 9000);
	n = strlen(s);
	
	//~ for (int i=0; i<n; i++)
		//~ for (int j=i; j<n; j++)
			//~ M[i][j] = false;
	//~ for (int i=0; i<n; i++)
			//~ M[i][i] = true;
	//~ 
	//~ int max = 0;
	//~ int row = 0;
	//~ for (int i=0; i<n; i++) {
		//~ int sum = 0;
		//~ for (int j=i; j<n; j++)
			//~ if (test(i,j)) sum++;
		//~ if (sum > max) {
			//~ max = sum;
			//~ row = i;
		//~ }
	//~ }
//~ 
	//~ 
	//~ for (int i=0; i<n; i++)
		//~ for (int j=0; j<n; j++)
			//~ M[i][j] = false;
	
	
	
	
	
	
//	cout << n << endl;
	
//	return 0;
	
	int j = n;
	
	Pal[p++] = 0;
	Pal[p++] = 1;
	
	for (int i=1; i<=n; i++) {
		for (int j=0; j<i; j++) {
			if (test(j, i)) {
				insert(j, i);
				break;
			}
		}
	}
	
	//~ while (i<n) {
		//~ for (j=n; j>i; --j) {
			//~ if (test(i,j)) break;
		//~ }
		//~ Pal[p++] = j;
		//~ i = j;
	//~ }
	 
//	test2(0,n);
	
//	for (int i=0; i<p; i++) {
		cout << p-1 << endl;
//	}
	
	show(n);

	return 0;
}
