#include <iostream>
#include <string>
#include <map>

using namespace std;

int mult[6] = {10, 50, 100, 500, 1000, 5000};

int summ(int v[6])
{
	int res = 0;
	for (int i=0; i<6; ++i) res += mult[i]*v[i];
	return res;
}

int main()
{
	int k[6], m;
	
	int pos = -1;
	for (int i=0; i<6; ++i) {
		cin >> k[i];
		if (k[i] > 0 && pos == -1) pos = i;
	}
	cin >> m;
	
	int max = summ(k)/m;
	--k[pos];
	int min = summ(k)/m;

	cout << max-min << endl;
	for (int i=min+1; i<=max; ++i)
		cout << i << " ";
	cout << endl;
	
//	cout << "pos = " << pos << endl;
//	cout << "min = " << min << endl;
//	cout << "max = " << max << endl;
	
	return 0;
}
