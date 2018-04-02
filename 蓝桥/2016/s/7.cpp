#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
//  邮票不一定一笔画。 所以这是一个错误代码，正确应该是选出5个数，然后去dfs搜索，看是否是连通。 
bool isValid(int pos, int border) {
	if (pos >=0 && pos < border) return true;
	return false;
}
int res = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int flag[13] = {0};
int pos[13];
int isHave[1000000]= {0};
int tag = 0;
void dfs(int xx, int yy, int count) {
	if (count == 5) {
		if (isHave[tag] == 0) {
		//	isHave[tag] = 1;
			res++;
			printf("=======%d======\n",tag);
			sort(pos,pos+5);
			for (int i=0; i<5; i++) {
				printf("%d ",pos[i]+1);
			}
			printf("\n");
		}
		return ;
	}


	flag[xx*4 + yy] = 1;
	for (int i=0; i<4; i++) {
		int value = (xx+dx[i]) *4 + yy+dy[i];
		if (isValid(xx + dx[i],3) && isValid(yy + dy[i],4) && !flag[value]) {
			pos[count] = value;
			tag += 1<<value;
			dfs(xx+dx[i],yy+dy[i],count+1);
			tag -= 1<<value;
		}
	}
	flag[xx*4 + yy] = 0;
}
int main() {
	
	freopen("out.txt","w",stdout);
	for (int i=0; i<12; i++) {
		pos[0] = i;
		tag = 1<<i;
		dfs(i/4,i%4,1);
		cout <<"++++++++++++++++++++++++++++"<<endl;
		cout << i<< endl;
	}
	return 0;
}
