#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, bool> store;

int main()
{
	std::string s;
	
	int n;
	cin >> n;
	getline(cin, s);
	int sum = 0;

	for (int i=0; i<n; ++i) {
		getline(cin, s);
		if (store[s])
			sum++;
		else
			store[s] = true;
	}
	
	cout << sum << endl;
}
