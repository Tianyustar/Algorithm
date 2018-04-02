#include <cstdio>
#include <vector>
#include <cmath>
#include<cstring>

using namespace std;


int calculated(int num, int position,int index) {
	int ret = num*pow(10,position)*pow(2,index);
	for (int i=0;i<position;i++) {
		ret +=  num*pow(10,position-i-1)*pow(2,i)*pow(2,index);
		ret = ret%1000000007;
	}
	return ret;
}
int main()
{
	int t;
	int ret = 0;
	char num[10];
	scanf("%d",&t);
	getchar();
	while(t--) {
		gets(num);
		int len = strlen(num);
		ret = 0;
		for (int i=0;i<len;i++){
			ret =(ret + calculated(num[i]-'0',len-1-i,i))%1000000007;
		}
		printf("%d\n",ret);
	}
	return 0;
	
} 
