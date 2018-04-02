
//  这种做法十分的耗时！！！！ 跑了很久都没有抛出结果 
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int flag[10]= {0};
int set[20]={1,3,2,4,6,5,7,8,0,1,2,3,4,5,6,7,8,9,9,0};
int number[6]= {0};
int getNum(int pos,int index) {
	int num=0;
	for (int i = 0; i < index ; i++) {
		num += pow(10,index-1-i)*set[pos+i];
	}
	return num;
}

void printNum() {

	for (int i=0; i<6; i++) {
		cout << number[i] << endl;
	}
	cout << "---------" << endl;
}
int main() {

//	for (int i=0; i<10; i++) {
//		set[i] = i;
//		set[i+10] = i;
//	}
	
	do {
		for (int i=0;i<3;i++)  if (set[i+3] == 0) continue;
		for (int i=0; i<5; i++) {
			number[i] = getNum(3*i,3);
		}
		number[5] = getNum(15,5);
		int tag = 0;

		//printNum();

		for (int i=0; i<3; i++) {
			if (set[3+i]*number[0] != number[4-i])  {
				tag = 1;
				break;
			}
		}
		if (tag == 0) {
			if (number[0]*number[1] == number[5]) {
				printNum();
				return 0;
			}
		}
	}	while(next_permutation(set, set+20));
	return 0;
}
