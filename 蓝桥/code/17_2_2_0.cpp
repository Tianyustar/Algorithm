#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int flag[10]= {0};
int judge(int num) {
	
	int count = 0;
	int dig;
	if (num < 1000) dig = 3 ;else dig = 5;
	while(count < dig) {
		int pos = num%10;
		if ( ++flag[pos] > 2 )
			return 0;
		num = num/10;
		count++;
	}
	return 1;
}
int judge_ab(int a, int b) {
	
	if (a*b > 100000) return 0;
	if (!judge(a*b)) return 0;
	int bit[3];
	bit[0]=b/100;
	b = b%100;
	bit[1] = b/10;
	b = b%10;
	bit[2] = b;
	for (int i=0; i<3; i++) {
		if (!judge(bit[i]*a)) return 0;
	}

	
	return 1;
}
int main() {
	for (int a=112; a<=998; a++) {
		for (int b=112; b<=998; b++) {
			if (judge(a) && judge(b)) {
			//	cout << a <<endl;
			//	cout << b <<endl;
			//	cout << "---" <<endl;
				if (judge_ab(a,b)) {
					cout << a <<endl;
					cout << b <<endl;
					cout << a*b << endl;
					for (int i=0;i<10;i++)  
					 cout << flag[i] << endl;
					return 0;
				}
			}
			memset(flag,0,sizeof(flag));
		}
	}
	return 0;
}
