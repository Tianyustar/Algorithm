#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define N 13 
using namespace std;
 // next_permutaion �õĻ�12 Ҫ20s 
// next_permutaion ���Ҫȫ���У���ʼ���ݱ���������� 
int main(){
	
		int num[N]={0};
		for (int i=0;i<N;i++) 
			num[i] = i;
		while(next_permutation(num,num+N));
}
