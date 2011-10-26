#include <iostream>


using namespace std;



int
main()
{
	int a, da, b, db;
	cin >> a >> da >> b >> db;
	int i = 0;
	
	while (a < b) {
		if (i%2 == 0)
			a += da;
		else
			b -= db;
		++i;
	}
	
	if (i%2 == 0)
		cout << a << endl;
	else
		cout << b << endl;
	

	return 0;
}
