#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
int main() {
	
	int sum[100]={0};
	for (int i=1;i<=100;i++) {
		sum[i] = sum[i-1]+i;
	//	cout << sum[i] <<endl;
	}
	for (int i=2;i<100;i++) {
		for (int j=i+1;j<100;j++) {
			if (sum[j]- sum[i] == 236) {
				cout<<i+1<<endl;
				cout<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
