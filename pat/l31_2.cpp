#include <stdio.h>
#include <iostream>
#include <set> 
#include <vector>
#include <algorithm>
using namespace std;

#define MINX -10000000 // ��С��int������ 
//  ʹ�ñ����㷨 ,

// ����pre�ڵ��ӡӲ��, ��¼���������·���㷨��ͬ��֮ζ 
void print(int *pre, int *ans, int m){ //  �ݹ��ӡ 
	
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
	int m,n;//  ��������Ϊ m,��Ʒ����Ϊ n��ÿ��Ӳ�ҵ���ֵΪm����������Ϊ1��Ҫ����ǹ̶�������װ����Ӳ�� ��������С���У� 
	scanf("%d%d",&n,&m);
	// ���˼·Ϊ ����i����Ʒʱ ���������ֱ�Ϊjʱ
	// ��0����Ʒ�� ��������Ϊ0
	for (int i=1; i<=1004; i++)
		dp[i] = -10000000;
	dp[0]=0;
	
	for (int i=1; i<=n; i++) {
		scanf("%d",&coin[i]);
	}
	sort(coin+1, coin+n+1);  // ����Ҫ��Ӳ�����򣬲�Ȼ�ᵼ��Ӳ���ظ�ʹ�õ�bug ����Ϊcoin��pre���������µģ� ��һ��״̬������ȫ�����Ż� 
	for (int i=1; i<=n; i++) { // �Ե�i-i-1����Ʒ����
		for (int j=m; j>=coin[i]; j--) { // ������Ϊm��...
			//	cout << dp[j] << endl;
			if (dp[j] <= dp[j-coin[i]]+1) { // ����ĵ��ھ��Բ����٣���ΪҪ��Ӳ�Ҿ����ܵĶ� 
					dp[j] = dp[j-coin[i]]+1;     // �ȽϷţ����߲���
					pre[j] = j-coin[i]; // ��¼��һ������Ѱ��
					ans[j] = coin[i]; // ��¼�ŵ�Ӳ�� 
					
				//	printf("j= %d coint = %d\n",j,coin[i]);
			}
			
			//	cout << dp[j] << endl;
		}
	}

	// ���֪����Ҫ�ŵ�����Щ��Ʒ��
	if (dp[m] > 0)
	print(pre,ans,m);
	else 
	puts("No Solution");
	return 0;
}
