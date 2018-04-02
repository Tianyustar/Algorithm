#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int sets[10]={0,1,2,3,4,5,6,7,8,9};
bool check(int pos) {
	
	// 计算位置
	int xx = (pos+1)/4;//  计算i坐标
	int yy = (pos+1)%4; //  计算j坐标 
	int dx[4]={0,0,1,-1};
	int dy[4]={1,-1,0,0};
	//printf("check pstiont x = %d, y= %d\n",xx,yy);
	for (int i=0;i<4;i++) {
		int position = (xx+dx[i])*4 + (yy+dy[i]) -1;
	//	printf("check xiangling position  = %d\n",position);
		if (position >= 0 && position < 10) {
			if (abs(sets[pos]-sets[position]) == 1) return false;
		}
	}
	return true;
}
int main() {
	
	freopen("out.txt","w",stdout);
	int count = 0;
	do {
		int flag = 0;
		for (int i=0;i<10;i++) {
			if (!check(i))  {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			count ++;
			
//			for (int i=0;i<10;i++) {
//				printf("%d ",sets[i]);
//			}
//			printf("\n");
		} 
	}while(next_permutation(sets,sets+10));
	
	printf("%d \n",count);
	return 0;
}
