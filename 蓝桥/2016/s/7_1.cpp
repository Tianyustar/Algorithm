#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
//  �ȴ�1-12 ��ѡ��12�����֣� Ȼ���ٽ���dfs/ bfs ���������ܷ��ѵ�5
int map[4][5]= {0};
int flag[13]= {0}; //  ����Ҫflag
int save[6]= {0};
int cnt = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int xx, int yy) {
	
	//printf("xx= %d, yy=%d\n",xx,yy);
	map[xx ][yy] = 0;  //   ѭ�����Ⱥ��ϵ Ҫע�� 
	cnt++;
	for (int i=0; i<4; i++ ) {
		
		if (map[dx[i] +xx ][dy[i] +yy] == 1) {
			dfs(xx+dx[i], yy+dy[i]);
		}
	}
}


void findNum(int pos, int count) {
	if (count == 5)  {
		
		int xx, yy;
		
		memset(map,0,sizeof(int)*4*5);
		for (int i=0; i<5; i++) {
			map[(save[i]-1)/4+1][(save[i]-1)%4 + 1] = 1;
		//	printf("%d ",save[i]);
		}
		cnt = 0;
		dfs((save[0]-1)/4+1,(save[0]-1)%4+1);
		if (cnt == 5) { // ?  Ϊʲô�����6 ��һ���±� 
			for (int i=0; i<5; i++) {
				printf("%d ",save[i]);
			}
				printf("\n");
				
		}
	
		return ;//  ������5����, ��С�����ȥ����
	}
	for (int i=pos; i<=12; i++) {
		save[count] = i;
		findNum(i+1,count+1);
	}
}
int main() {

   	freopen("out.txt","w",stdout);
	findNum(1,0);
	return 0;
}
