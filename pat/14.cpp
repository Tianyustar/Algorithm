/*
本道题目可以转化为最长上升子序列的题目
这题主要是根据Dilworth定理（最少下降子序列数等于最长上升子序列长度）
// 使用贪心算法维护一个最优序列，但是此序列并不是最终的结果

*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
// 使用stl的二分查找,用自己写的二分就有毛病  emm？ what fuck？ 

int main() { // 求最长上升子序列？
	vector<int> train;
	vector<int> upLines;
	int n;
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	train.resize(n+1);
	scanf("%d",&train[0]);
	upLines.push_back(train[0]);// 将0压进
	int count = 0;
	for (int i=1; i<n; i++) {
		scanf("%d",&train[i]);
		if(train[i] > upLines[count]) {
			upLines.push_back(train[i]);
			count++;
		} else {
			vector <int>::iterator Iter1, Result1;
			Iter1 =  upper_bound(upLines.begin(),upLines.end(),train[i]);
			//printf("--- %d  %d\n",*Iter1, train[i]);
			*Iter1= train[i];

		}
	}
	printf("%d\n",upLines.size());


}
