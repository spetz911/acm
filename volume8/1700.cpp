#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print_vec(vector<string>::const_iterator the_begin,
               vector<string>::const_iterator the_end)
{
	vector<string>::const_iterator iv;
	for (iv = the_begin; iv != the_end; ++iv)
		cout << *iv << " ";
	cout << endl << "___" << endl;
}



vector<string>::const_iterator
set_to_vec(set<string>::const_iterator begin1,
           set<string>::const_iterator end1,
           vector<string>::iterator begin2)
{
	while (begin1 != end1) {
		*begin2 = *begin1;
		++begin1;
		++begin2;
	}
	return begin2;
}

int main()
{
	int n;
	map<string, set<string> > association;
	
	
	vector<string> res, C;
	
	set<string> s0;
	set<int> A, B;
	
	string s;
	
	cin >> n;
	getline(cin, s);
	
	for (int i=0; i<n; ++i) {
		getline(cin, s);
		string s1 = s.substr(0, s.find(':'));
		association[s1].clear();
		s = s.substr(s.find(' '));

		int a = 0;
		for (;;) {
			s = s.substr(a+1);
			a = s.find(' ');
			if (a == -1) {
				association[s1].insert(s.substr(0,a));
				//cout << s << ';' << endl;
				break;
			} else {
				association[s1].insert(s.substr(0,a));
				//cout << s.substr(0, a) << ';' << endl;
				
			}
		}
	}
	
	map<string, set<string> >::iterator it;
	set<string>::iterator is;
	
	
	//~ for (it = association.begin(); it != association.end(); ++it) {
		//~ cout << "assoc with " << it->first << ":";
		//~ for (is = it->second.begin(); is != it->second.end(); ++is)
			//~ cout << *is << " ";
		//~ cout << endl;
	//~ }
	
	cin >> n;
	//~ cout << "n = " << n << endl;
	getline(cin, s);
	for (int i=0; i<n; ++i) {
		getline(cin, s);
		res.clear();
		res.resize(1000);
		vector<string>::const_iterator the_end = res.begin();
		vector<string>::const_iterator the_begin = res.begin();
		
		int a = -1;
		for (;;) {
			s = s.substr(a+1);
			a = s.find(' ');
			
			if (a == -1) {
				if (the_begin == the_end) {
					res.resize(association[s].size());
					the_end = set_to_vec(association[s].begin(), association[s].end(), res.begin());
//					print_vec(the_begin, the_end);
				} else {
				the_end = set_intersection(association[s].begin(), association[s].end(),
				                            the_begin, the_end, res.begin());
				//cout << s << ';' << endl;
				break;
				}
			} else {
				string s1 = s.substr(0,a);
				if (the_begin == the_end) {
					res.resize(association[s1].size());
					the_end = set_to_vec(association[s1].begin(), association[s1].end(), res.begin());
//					print_vec(the_begin, the_end);
				} else {
				the_end = set_intersection(association[s1].begin(), association[s1].end(),
				                           the_begin, the_end, res.begin());
				//cout << s.substr(0, a) << ';' << endl;
				//s.substr(a);
				}
			}
		}
		if (the_begin == the_end)
			cout << "No solution." << endl;
		else {
			while (the_begin != the_end) {
				cout << *the_begin << ' ';
				++the_begin;
			}
			cout << endl;
		}
		
	}
	

//	cout << ((res == C.begin())?"NO":"YES") << endl;
	return 0;
}
