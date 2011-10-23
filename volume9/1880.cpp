#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> A, B, C;

int main()
{
	int m, n, k, z;
	
	cin >> n;
	for (int i=0; i<n; ++i)
	{
		cin >> z;
		A.push_back(z);
	}
	cin >> m;
	for (int i=0; i<m; ++i)
	{
		cin >> z;
		B.push_back(z);
	}

	vector<int> R1;
	vector<int>::iterator it, ip;

//!	set_intersection(A.begin(),A.end(),, R1.begin());
	for (it = A.begin(); it != A.end(); it++) {
		if (binary_search(B.begin(), B.end(), *it))
			R1.push_back(*it);
	}

	cin >> k;
	for (int i=0; i<k; ++i)
	{
		cin >> z;
		C.push_back(z);
	}
	
	vector<int> R2;
//	R2.resize(R1.size());
	
//!	set_intersection(R1.begin(), it, C.begin(), C.end(), R2.begin());
	for (it = R1.begin(); it != R1.end(); it++) {
		if (binary_search(C.begin(), C.end(), *it))
			R2.push_back(*it);
	}


	cout << R2.size() << endl;

}
