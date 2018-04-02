#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define N 13 
using namespace std;
 // next_permutaion 用的话12 要20s 
// next_permutaion 如果要全排列，初始数据必须是有序的 
int main(){
	
		int num[N]={0};
		for (int i=0;i<N;i++) 
			num[i] = i;
		while(next_permutation(num,num+N));
}
