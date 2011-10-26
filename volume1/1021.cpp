#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, z;
	set<int> A, B;
	vector<int> C;
	
	cin >> n;
//	A.inset(n);
	for (int i=0; i<n; ++i) {
		cin >> z;
		A.insert(-z);
	}
	
	cin >> n;
//	B.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> z;
		B.insert(z - 10000);
	}
	
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
	
	C.resize(A.size());
	vector<int>::const_iterator res;
	res = set_intersection(A.begin(), A.end(), B.begin(), B.end(), C.begin());
//	C.resize(res - C.begin());
	
	

	
	cout << ((res == C.begin())?"NO":"YES") << endl;
	return 0;
}
