#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
int main() {
	
	int res = 0;
	int number = 1;
	for (int step = 1; step <= 100 ;step++) {
			res += number;
			number += step+1;
			cout << number << endl;
	}
	cout << res <<endl;
	return 0;
}
