#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string,int> wordcounts;
	std::string s;
	int n;
	cin >> n;

	for (int i=0; i<n; ++i) {
		cin >> s;
		++wordcounts[s];
	}

	map<string,int>::const_iterator end = wordcounts.end();
	map<string,int>::const_iterator begin = wordcounts.begin();
	map<string,int>::const_iterator it;

	for (it = begin; it != end; ++it) {
		if (it->second > 1)
			std::cout << it->first << endl;
	}
}
