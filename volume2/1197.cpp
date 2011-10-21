#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int M[200][200];

bool
letter(char c)
{
	if ((c>='a') and (c<='h'))
		return true;
	else
		return false;
}

int P[8][2] =   {{-2,-1},
				 {-2, 1},
				 {-1,-2},
				 {-1, 2},
				 { 1, 2},
				 { 1,-2},
				 { 2,-1},
				 { 2, 1}};

bool
on_board(int a, int b)
{
	if ((0<=a) and (a<8) and (0<=b) and (b<8))
		return true;
	else
		return false;
}

int
test(int a, int b)
{
//	-2, -1, 1, 2
	int counter = 0;
	for (int i=0; i<8;i++){
		if (on_board(a+P[i][0], b+P[i][1]))
			counter++;
	}
	return counter;
}

int
main()
{
	int n;
	unsigned char c;
	cin >> n;
	for(int i=0; i<n; i++){
		while (not letter((c = getchar()))){}
		int a = c - 'a';
		int b = getchar() - '1';
		cout << test(a, b) << endl;
	}

	return 0;
}

