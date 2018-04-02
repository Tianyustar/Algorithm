#include <stdio.h>
#include <string.h>
#include <set>
#include <iostream>
#define MAX 100000

//  暴力搜索要注意越界 
using namespace std;

int primes[MAX];

void init() { // 计算一个素数序列 
	for (int i=2;i<MAX;i++) {
		if (primes[i] == 0) {
			//cout << i <<endl;
		for (int j=2*i;j<MAX;j=j+i){
			primes[j] = 1;
		}
	}
	}
}
int nextPrime(int start) {
	
	while(start+1<MAX && primes[start+1]) {
		start++;
	} 
	return start+1;
}

int main()
{
	init();
	int count = 0;
	
	for (int start = 2;start < MAX; start = nextPrime(start)) {
				
			for (int d = 10;d<10000;d++) {
				int n=0;
				for (n = 1;n<10;n++) {
					if (n*d + start  < MAX) {
						if ( primes[n*d+start]) break;
					}
					 	
				}
				if (n >= 10) {
					cout << d << endl;
					cout <<  (n-1)*d+start <<endl;
					return 0;
				}
			}
	}
	return 0;
}
