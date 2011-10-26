#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a%2==0 || b%2==1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
