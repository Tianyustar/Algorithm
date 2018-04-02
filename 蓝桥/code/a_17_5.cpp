#include <bits/stdc++.h>
using namespace std;
double r;
int n;
double sol(double x){
	int a=(x+0.005)*100;
	return a/100.0;
}
int main()
{
	cin>>r>>n;
	double money=10000.0/n;     //从最小开始枚举
	money=sol(money);           //精确到分 四舍五入
	double ans,minn=10000000;     //ans 答案  minn保存最近答案的数
	for(;1;money+=0.01){        //每次递增0.01
		double total=10000;     //初始化金钱
		for(int i=0;i<n;i++){     //算n个月过后还剩多少钱
			double lx=total*(0.01*r/12);
			total+=-money+lx;
			total=sol(total);
		}
		if(total<0){   //小于就退出
			if(fabs(total)<minn)
				ans=money;
			break;
		}
		ans=money;
	}
	cout<<(int)(ans*100)<<endl;
	return 0;
}

