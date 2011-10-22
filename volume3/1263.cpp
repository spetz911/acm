#include <cstdio>
#include <map>

using namespace std;

map<int,int> votecounts;

int main()
{
	int n, a, m;
	scanf("%d", &m);
	scanf("%d", &n);
	
	for (int i=0; i<n; ++i) {
		scanf("%d", &a);
		++votecounts[a-1];
	}

	char c = '%';
	
	for (int i=0; i<m; ++i) {
		printf("%.2f%c\n", 100.0 * votecounts[i] / n, c);
	}

	return 0;
}
