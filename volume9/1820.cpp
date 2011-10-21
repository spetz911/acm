#include <iostream>
#include <cstring>


using namespace std;

void
test(int a)
{
	if (a < 5) cout << "few" << endl;
	else if (a < 10) cout << "several" << endl;
	else if (a < 20) cout << "pack" << endl;
	else if (a < 50) cout << "lots" << endl;
	else if (a < 100) cout << "horde" << endl;
	else if (a < 250) cout << "throng" << endl;
	else if (a < 500) cout << "swarm" << endl;
	else if (a < 1000) cout << "zounds" << endl;
	else cout << "legion" << endl;
}

char s[1000];

int
main()
{
	int n;
	cin >> n;
	test(n);	
	return 0;
}
