#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<long long> M;
	M.resize(3);
	cin >> M[0] >> M[1] >> M[2];
	
	vector<long long> deltas;
	
	unsigned int i,j;
	
	int counter = 0;
	for (;;) {
		++counter;
		deltas.clear();
		deltas.resize(0);
		for (i=0; i<M.size(); i++)
			for (j=i+1; j<M.size(); j++)
				deltas.push_back(labs(M[i] - M[j]));
				
		long long m = *min_element(deltas.begin(), deltas.end());
		if (m == 0) {
			cout << counter << endl;
			return 0;
		} else {
			M.push_back(m);
		}
	}
	
	return 0;
}
