#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
// 交换瓶子？？？？
// 用什么思路去写？？？？
// 贪心？ 把瓶子交换到正确的位置？ 
// 使用这种代码 会有最后一个测试点过不去 
int main() {
	
	
	int bott[10005];
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&bott[i]);
	}
	// 贪心， 依次交换位置, 把瓶子换到正确的位置
	int flag = 1;
	int count = 0;

		for (int i=1;i<=n;i++) {
			while (bott[i]!=i) {
				swap(bott[i],bott[bott[i]]);
				flag = 1;
				count++;
			}
	}  
	printf("%d\n",count);
	return 0;
} 
