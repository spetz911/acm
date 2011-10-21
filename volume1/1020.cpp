#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct point {
	double x;
	double y;
};

inline double
sqr(double x)
{
	return x*x;
}

double
distance(double x[2], double y[2])
{
	return sqrt( sqr(x[0] - y[0]) + sqr(x[1] - y[1]));
}

double
angle(double x[2], double y[2], double z[2])
{
	double a[2];
	double b[2];
	
	a[0] = x[0] - y[0];
	a[1] = x[1] - y[1];
	
	b[0] = y[0] - z[0];
	b[1] = y[1] - z[1];
	
//	double v_prod = a[0]*b[1] - a[1]*b[0];
	double s_prod = a[0]*b[0] + a[1]*b[1];
	
	double d1 = distance(x,y);
	double d2 = distance(y,z);
	
	
	
	return acos(s_prod / (d1*d2));
}



double M[200][2];
int m = 0;

const double PI = acos(-1.0);

int
main()
{
	int n;
	cin >> n;
	double r;
	cin >> r;
	
//	cout << angle(a, b, c) << endl;
	
	for (int i=0; i<n; i++) {
		cin >> M[i][0] >> M[i][1];
	}
	M[n][0] = M[0][0];
	M[n][1] = M[0][1];
	
	double z = 0;
	for (int i=0; i<n; i++) {
		z += distance(M[i], M[i+1]);
	}
	
	printf("%.2lf\n", z + 2*PI*r);
	
	return 0;
}

