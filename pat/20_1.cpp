#include<stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

//  �򵥵�bfs����,����Ҫ�ж���ɫ�Ƿ��ظ�����Ҫ�ж��Ƿ���Ҫ�����ɫ 
//  �жϵ�͵�֮����ɫ�Ƿ�һ��
 //  ��һ����һ���ر�ӵĵط���������ɫ�����ǵ���k�ģ���������Ϊ��С��k������¼�Ȼ�ܹ���������ô���ھ�Ҳһ���ǿ��Ե�
  // ����ͼ�п����л��Σ����ǲ��ǻ�·���� dfsֻ�������������е㣬���ǲ�һ���ܱ������б�
   
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
			scanf("%d",&color_map[i]);// �洢��ɫ
			count_color.insert(color_map[i]);
		}
		int flag = 1;
	//	printf("--- count_color %d\n",count_color.size());
		if (count_color.size() != k) {
			puts("No");
			continue;
		}
		for (int i=1; i<=v; i++) { // ���ǵ�ͼ���ܲ�����ͨ��
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
