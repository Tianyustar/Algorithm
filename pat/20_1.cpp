#include<stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

//  简单的bfs遍历,不光要判断颜色是否重复，还要判断是否是要求的颜色 
//  判断点和点之间颜色是否一样
 //  这一题有一个特别坑的地方，就是颜色必须是等于k的，但是我认为在小于k的情况下既然能够做到，那么大于就也一定是可以的
  // 无向图有可能有环形（但是不是回路）。 dfs只能做到遍历所有点，但是不一定能遍历所有边
   
int Map[501][501]= {0};
int color_map[501]= {0};
int visited[505]= {0};
vector<int> next;
int v,e,k;
int dfs(int start) {
	visited[start] = 1;
	for (int i=0; i<=v; i++) {
		if (Map[start][i] && (color_map[i] == color_map[start]))  return 0;
		
		if (Map[start][i] && visited[i]==0) {
		//	printf("---- %d----%d\n",start,i);
		//	printf("---color- %d----%d\n",color_map[i],color_map[start]);
				return dfs(i);
		}
	}
	return 1;
}
int main() {
//	freopen("in.txt","r",stdin);
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
		count_color.clear();
		memset(visited,0,sizeof(int)*505);
		memset(color_map,0,sizeof(color_map));
		for (int i=1; i<=v; i++) {
			scanf("%d",&color_map[i]);// 存储颜色
			count_color.insert(color_map[i]);
		}
		int flag = 1;
	//	printf("--- count_color %d\n",count_color.size());
		if (count_color.size() != k) {
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
