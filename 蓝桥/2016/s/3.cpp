#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

void getNum(int *num, int * single) {
	
	for (int i=0;i<3;i++) num[i] = single[i];
	num[3] = single[3]*100 + single[4]*10 +single[5];
	num[4] = single[6]*100 + single[7]*10 + single[8];
} 

int main(){
	
	int single[9]={1,2,3,4,5,6,7,8,9};
	int num[5]={0};// 5 ¸öÊý
	int count = 0;
	do{
		getNum(num,single);
		double b = (num[1]*num[4] + num[2]*num[3])*1.0/(num[2]*num[4]);
		if (num[0] + b == 10) {
				count++;
			for (int i=0;i<5;i++) {
				cout<<num[i] <<" " ;
			
			}
				cout<<endl;
		}
		
	}while(next_permutation(single,single+9));
	cout<< count << endl;
	return 0;
}
