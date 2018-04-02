#include<stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

//  简单的bfs遍历,不光要判断颜色是否重复，还要判断是否是要求的颜色 
int Map[501][501]= {0};
int color_map[501]= {0};
int visited[501]= {0};
vector<int> next;
int v,e,k;
int dfs(int start) {
	visited[start] = 1;
	for (int i=1; i<=v; i++) {
		
		if (Map[start][i] && visited[i]==0) {
			printf("---- %d----%d\n",start,i);
			printf("---color- %d----%d\n",color_map[i],color_map[start]);
			if (color_map[i] == color_map[start]) {
				puts("------same------");
				return 0;
			} else {
				return dfs(i);
			}
		}
	}
	return 1;
}
int main() {
	freopen("in.txt","r",stdin);
	set<int> count_color;
	scanf("%d%d%d",&v,&e,&k);
	int a,b;
	for (int i=0; i<e; i++) {
		scanf("%d%d",&a,&b);
		Map[a][b] = 1;
		Map[b][a] = 1;
	}
	int n;
	scanf("%d",&n);
	while(n--) {
		memset(visited,0,sizeof(int)*500);
		for (int i=1; i<=v; i++) {
			scanf("%d",&color_map[i]);// 存储颜色
			count_color.insert(color_map[i]);
		}
		int flag = 1;
		if (count_color.size() > k) {
			puts("No");
			continue;
		}
		for (int i=1; i<=v; i++) { // 考虑到图可能不是连通的
			if (visited[i] == 0) {
				if ( dfs(i) == 0) {
					flag = 0;
					break;
				}
			}
		}
		if(flag == 0) {
			puts("No");
		} else puts("Yes");

	}

	return 0;
}
