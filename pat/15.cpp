#include <cstdio>
#include <algorithm>


using namespace std;

int main() {
	
	//freopen("in.txt","r",stdin);
	
	int n,k,m;
	double grades[10005]={0};
	scanf("%d%d%d",&n,&k,&m);
	for (int i=0;i<n;i++) {
			double sum = 0;
			double grade = 0;
			double high = 0;
			double low = 101;
		for (int j=0;j<k;j++) {
			scanf("%lf",&grade);
			if (grade > high )  high = grade;
			if (grade < low ) low = grade;
			sum += grade;
		}
		grades[i] = (sum-high-low)/(k-2);
	}
	sort(grades,grades+n);
	if (m > 0) {
		printf("%.3lf",grades[n-m]);
	}
	for (int i=n-m+1;i<n;i++){
		printf(" %.3lf",grades[i]);
	}
	
	return 0;
} 
