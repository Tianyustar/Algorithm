#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	long long  diff=0;
	
	//freopen("in.txt","r",stdin);
	vector<int> vec;
	scanf("%d",&n);
	vec.resize(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&vec[i]);
	}
	sort(vec.begin(), vec.end());
	for(int i=0;i<n/2;i++) {
		diff += vec[n/2+i] - vec[i];
	}
	if (n%2) diff += vec[n-1];
	printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %ld",(n+1)/2,n/2,diff); 
	return 0;
} 
