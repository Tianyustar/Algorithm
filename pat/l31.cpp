#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int res[10004]= {0};
int money[10005]= {0};
int res_pos;
int n, aim;
int flag = 0;
// 如何进行有效剪枝？ // 暂时没有想到有效的剪枝 
int empty[1005]={0};  // 记录被放弃的纸币
 
void choose(int pos, int money_pos, int money_value) { // 选择第几个


	if (flag == 1 || money_value > aim) return ;
	
	if (money_value == aim) {
		flag = 1;
	//	cout << "---12---" <<endl;
		res_pos = pos;
		return ; // 不需要继续递归
	}
	if (money_pos >=  n)  return ;
	// 选择
	
	if (money_value+money[money_pos] <= aim) {  // 如果背包容量够那么装入 
		choose(pos+1,money_pos+1,money_value+money[money_pos]);
		res[pos] = money[money_pos] ;
		// 因为数据已经排好顺序 如果连本次选择也会超过背包容量，那么没有必要再进项其他枚举
		choose(pos,money_pos+1,money_value);
	}

}
int main() {


	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&aim);
	for (int i=0; i<n; i++) {
		scanf("%d",&money[i]);
	}
	sort(money,money+n);
	// 可以用搜索？ 如何进行有效减枝？？ 
	choose(0,0,0);
	if (flag==1) {
		printf("%d",res[0]);
		for (int i=1; i<res_pos; i++) {
			printf(" %d",res[i]);
		}
	} else
		puts("No Solution");

	return 0;
}
