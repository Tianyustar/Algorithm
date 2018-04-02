#include <stdio.h>
#include <iostream>
#include <set> 
#include <vector>
#include <algorithm>
using namespace std;

#define MINX -10000000 // 最小的int类型数 
//  使用背包算法 ,

// 利用pre节点打印硬币, 记录方法和最短路径算法有同工之味 
void print(int *pre, int *ans, int m){ //  递归打印 
	
	if (!pre[m]){
		printf("%d",ans[m]);
		return ;
	}
	print(pre,ans,pre[m]);
	printf(" %d",ans[m]);
}
int main() {
	
	freopen("in.txt","r",stdin);
	int  dp[1005] ;
	int coin[10005]={0};
	int pre[10005] = {0};
	int ans[10005] = {0};
	int m,n;//  背包容量为 m,物品个数为 n，每个硬币的面值为m，假设重量为1，要求的是固定体积里，能装最多的硬币 数量（最小序列） 
	scanf("%d%d",&n,&m);
	// 大概思路为 当有i个物品时 背包容量分别为j时
	// 有0个物品， 背包容量为0
	for (int i=1; i<=1004; i++)
		dp[i] = -10000000;
	dp[0]=0;
	
	for (int i=1; i<=n; i++) {
		scanf("%d",&coin[i]);
	}
	sort(coin+1, coin+n+1);  // 必须要对硬币排序，不然会导致硬币重复使用的bug ，因为coin的pre必须是最新的， 上一个状态必须是全局最优化 
	for (int i=1; i<=n; i++) { // 对第i-i-1个物品操作
		for (int j=m; j>=coin[i]; j--) { // 背容量为m到...
			//	cout << dp[j] << endl;
			if (dp[j] <= dp[j-coin[i]]+1) { // 这里的等于绝对不能少，因为要让硬币尽可能的多 
					dp[j] = dp[j-coin[i]]+1;     // 比较放，或者不放
					pre[j] = j-coin[i]; // 记录上一个方便寻找
					ans[j] = coin[i]; // 记录放的硬币 
					
				//	printf("j= %d coint = %d\n",j,coin[i]);
			}
			
			//	cout << dp[j] << endl;
		}
	}

	// 如何知道，要放的是哪些物品？
	if (dp[m] > 0)
	print(pre,ans,m);
	else 
	puts("No Solution");
	return 0;
}
