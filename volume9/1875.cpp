#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;


const int N = 5;
const double eps = 1e-10;

double sqr(double a) {return a*a;}
double abs9(double a) {return (a<0)?(-a):(a);}


struct point {
	int x;
	int y;
	bool killed;
	
	point(int _x, int _y)
		:x(_x), y(_y), killed(false){}
	
	bool
	operator<(const point &P1) const
	{
		return (x < P1.x);
	}
};

class parabola {
public:
	double a;
	double b;
	double c;
	parabola(point P1, point P2)
		:c(0.0)
	{
	//	point P0;
	//	if (P2 < P1) {P0 = P1; P1 = P2; P2 = P0;}
		double x1 = P1.x;
		double x2 = P2.x;
		double y1 = P1.y;
		double y2 = P2.y;
		
		a = (x1*y2 - x2*y1) / (x1*x2*(x2 - x1));
		if (a>0) {a = 0;}
		b = (y2 - a*sqr(x2)) / x2;
	}
	bool
	on_line(const point &P0)
	{
		if ((P0.killed)||(fabs(a) < eps)||(fabs(b) < eps)) return false;
		return ( fabs(a * sqr(P0.x) + b * P0.x + c - P0.y) < eps);
	}
	bool
	is_fail() const
	{
		return (fabs(a) < eps)||(fabs(b) < eps);
	}

};

void
print_p(parabola &p)
{
	cout << "p: a = " << p.a << " b = " << p.b  << endl;
}


vector<parabola> Parabolas;
vector<point> Points;



int test(parabola &P)
{
	int count = 0;
	vector<point>::const_iterator it;
	for (it = Points.begin(); it != Points.end(); it++)
		if (P.on_line(*it)) {count += 1;}
	
	return count;
}

bool isnt_killed(const point &P)
{
	return !P.killed;
}

int
main()
{
	int count_all = 0;
	int a,b;
	for (int i=0; i<N; ++i) {
		cin >> a >> b;
		Points.push_back(point(a,b));
	}
	vector<point>::iterator it;
	for (it = Points.begin(); it != Points.end(); ++it) {
		if (it->x == 0) {
			it->killed = true;
			count_all = 1;
		}
	}
	
	sort(Points.begin(), Points.end());
	
	for (int i=0; i<N; ++i) {
		for (int j=i+1; j<N; ++j) {
			if (isnt_killed(Points[i]) && isnt_killed(Points[j]))
				Parabolas.push_back(parabola(Points[i], Points[j]));
		}
	}
	vector<int> count_cross;
	count_cross.resize(Parabolas.size());
	int max1 = 1;
	
	while (max1 != 0) {
	//BEGIN
		for (unsigned int ip=0; ip<Parabolas.size(); ip++)
		{
			count_cross[ip] = test(Parabolas[ip]);
		}

		max1 = 0;
		int pos_m = 0;
		for (unsigned int i=0; i<count_cross.size(); ++i) {
			if (count_cross[i] > max1) {
				max1 = count_cross[i];
				pos_m = i;
			}
		}
		
		for (it = Points.begin(); it != Points.end(); ++it) {
			if (Parabolas[pos_m].on_line(*it)) {
				it->killed = true;
			}
		}
		
		count_all += 1;
	} //END
	
	
	// kill chickens that not kills by parabolas
	
	
	int rest = 0;
	for (unsigned int i=0; i<Points.size(); i++) {
		if (!Points[i].killed) rest++;
	}

//	vector<int>::const_iterator it1;
//	for (it1 = count_cross.begin(); it1 != count_cross.end(); ++it1) {
//		cout << *it1 << endl;
//	}
	
//	for_each(Parabolas.begin(), Parabolas.end(), print_p);
	
	
	
	cout << count_all + rest - 1 << endl;
	return 0;
}
