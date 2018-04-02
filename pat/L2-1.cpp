/*
   使用spfa算法实现最短路径计算
*/

#include <iostream >
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
#define inf 0x7fff  // 最大 
using namespace std;

int main() {


	freopen("in.txt","r",stdin);
	int n,m,s,d;
	int map[500][500]= {0};
	int flag[500] = {0} ; // 记录
	int aid[500]= {0}; // 救援队数目
	int pre[500]= {0}; // 前一个节点 用于记录路径
	int path_num[500]= {0}; // 到点i有几条路可以走
	int value[500] = {0}; //  到点i的救援数目
	int path[500]= {0}; // 最短路径长度
	queue<int> Queue;
	cin >> n >> m >> s >> d; // 输入n,m,s,d;
	int a,b,len;
	memset(path,inf,sizeof(path));
	for (int i=0; i<n; i++) {
		cin>>aid[i];
	}
	for (int i=0; i<m; i++) {
		cin>> a >> b >> len;
		map[a][b] = len;
		map[b][a] = len;
	}
	Queue.push(s);  // 起点入队
	flag[s] = 1;
	while(!Queue.empty()) {

		int pos = Queue.front();
		Queue.pop();
		flag[pos] = 0;
		printf("pos = %d \n",pos);
		for (int i=0; i<n; i++) {
			if (map[pos][i] != 0) {
				printf("pos = %d i = %d \n",pos,i);
				if (map[pos][i] + path[pos] < path[i]) { // 更新路径
					path[i] = map[pos][i] + path[pos];
					path_num[i] = 1;// 计算有几条路径
					value[i] = aid[i] + value[pos];// 更新救援数数目
					pre[i] = pos;
					if (flag[i] == 0) {
						puts("push");
						Queue.push(i);  // 入队
						flag[i] = 1;
					}
				} else if (map[pos][i] + path[pos] == path[i]) { // 长度相等 实际上是不需要更新，但是需要更新救援数目
					// 问题 是否还需要再次入队？？？？？？ 如果不入队的话  救援数目会不会收到影响？
					//  思考结果:  如果入队会出现错误，  但是我认为不入队也会出现错误  等会提交看看
					path_num[i] += path_num[pos];//  更新最短路径长度
					if (value[i] < aid[i] + value[pos]) { // 更新
						value[i] = aid[i] + value[pos];
						pre[i] = pos; //  更新前驱路径
					}
				}
			}
		}

	}

	stack<int> res;
	int cur = d;
	while(d!=s) {
		res.push(d);
		d = pre[d];
	}

	cout << path_num[cur] << " " <<aid[cur]<<endl;
	cout<<res.top();
	res.pop();
	while(!res.empty()) {
		cout<<" "<<res.top();
		res.pop();
	}

	return 0;
}
