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
	
	getline(cin, s);
	
	for (int i=0; i<n; ++i) {
		getline(cin, s);
		++wordcounts[s];
	}

	map<string,int>::const_iterator end = wordcounts.end();
	map<string,int>::const_iterator begin = wordcounts.begin();
	map<string,int>::const_iterator it;

	int max = 0;
	map<string,int>::const_iterator mpos;
	
	for (it = begin; it != end; ++it) {
		if (it->second > max) {
			max = it->second;
			mpos = it;
		}
	}
	std::cout << mpos->first << endl;
}
