#include <iostream>
#include <cmath>

using namespace std;

int
main()
{
	long long ir, ix, iy, summ;
	long double x, y, r;
	summ = 0;

	cin >> ir;
	r = ir;

	for (ix = 0; ix<ir; ix++) {
		x = ix;
		y = sqrt(r-x)*sqrt(r+x);
		iy = ceil(y)-29;
		if (iy<0) iy = 0;
		while (ix*ix < (ir-iy)*(ir+iy)) ++iy;
		summ += iy;
	}
	cout << 4*summ << endl;

	return 0;
}
