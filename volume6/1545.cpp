#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<std::string> words;
	std::string s;
	std::string pattern;
	
	int n;
	cin >> n;

	for (int i=0; i<n; ++i) {
		cin >> s;
		words.push_back(s);
	}
	cin >> pattern;
	
	sort(words.begin(), words.end());

	vector<std::string>::const_iterator it;
	
	for(it = words.begin(); it != words.end(); ++it)
	{
		if ((*it)[0] == pattern[0])
			cout << *it << endl;
	}

}
