40096

#include <bits/stdc++.h>
using namespace std;
int n;
int a[6];
int pd(){
	int p[20]={0};
	for(int i=0;i<6;i++){
		int k=0;
		while(a[i]){
			p[a[i]%10]++;
			if(p[a[i]%10]>2)return 0;
			a[i]/=10;
			k++;
		}
		if(k<3) return 0;
	}
	return 1;
}
int main()
{
	for(int i=100;i<=999;i++)
		for(int j=100;j<=999;j++){
			a[0]=(j%10)*i;a[1]=(j/10%10)*i;  //a保存每一个状态的信息
			a[2]=(j/100)*i;a[3]=i*j;
			a[4]=i;a[5]=j;
			if(pd()){  //判断是否满足条件
				cout<<i*j<<" ";
			}
		}
	
	
	return 0;
} 
