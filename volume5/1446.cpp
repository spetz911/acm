#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

void pr(const string &s)
{
	cout << s << endl;
}

int main()
{
	map<string, vector<string> > wordcounts;
	std::string name, faq;
	
	int n;
	cin >> n;
	getline(cin, name);

	for (int i=0; i<n; ++i) {
		getline(cin, name);
		getline(cin, faq);
		wordcounts[faq].push_back(name);
	}
	
	cout << "Slytherin:" << endl;
	for_each (wordcounts["Slytherin"].begin(), wordcounts["Slytherin"].end(), pr);
	cout << endl;
	cout << "Hufflepuff:" << endl;
	for_each (wordcounts["Hufflepuff"].begin(), wordcounts["Hufflepuff"].end(), pr);
	cout << endl;
	cout << "Gryffindor:" << endl;
	for_each (wordcounts["Gryffindor"].begin(), wordcounts["Gryffindor"].end(), pr);
	cout << endl;
	cout << "Ravenclaw:" << endl;
	for_each (wordcounts["Ravenclaw"].begin(), wordcounts["Ravenclaw"].end(), pr);
	cout << endl;
	
}
