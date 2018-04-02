/*
   ʹ��spfa�㷨ʵ�����·������
*/

#include <iostream >
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
#define inf 0x7fff  // ��� 
using namespace std;

int main() {


	freopen("in.txt","r",stdin);
	int n,m,s,d;
	int map[500][500]= {0};
	int flag[500] = {0} ; // ��¼
	int aid[500]= {0}; // ��Ԯ����Ŀ
	int pre[500]= {0}; // ǰһ���ڵ� ���ڼ�¼·��
	int path_num[500]= {0}; // ����i�м���·������
	int value[500] = {0}; //  ����i�ľ�Ԯ��Ŀ
	int path[500]= {0}; // ���·������
	queue<int> Queue;
	cin >> n >> m >> s >> d; // ����n,m,s,d;
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
	Queue.push(s);  // ������
	flag[s] = 1;
	while(!Queue.empty()) {

		int pos = Queue.front();
		Queue.pop();
		flag[pos] = 0;
		printf("pos = %d \n",pos);
		for (int i=0; i<n; i++) {
			if (map[pos][i] != 0) {
				printf("pos = %d i = %d \n",pos,i);
				if (map[pos][i] + path[pos] < path[i]) { // ����·��
					path[i] = map[pos][i] + path[pos];
					path_num[i] = 1;// �����м���·��
					value[i] = aid[i] + value[pos];// ���¾�Ԯ����Ŀ
					pre[i] = pos;
					if (flag[i] == 0) {
						puts("push");
						Queue.push(i);  // ���
						flag[i] = 1;
					}
				} else if (map[pos][i] + path[pos] == path[i]) { // ������� ʵ�����ǲ���Ҫ���£�������Ҫ���¾�Ԯ��Ŀ
					// ���� �Ƿ���Ҫ�ٴ���ӣ����������� �������ӵĻ�  ��Ԯ��Ŀ�᲻���յ�Ӱ�죿
					//  ˼�����:  �����ӻ���ִ���  ��������Ϊ�����Ҳ����ִ���  �Ȼ��ύ����
					path_num[i] += path_num[pos];//  �������·������
					if (value[i] < aid[i] + value[pos]) { // ����
						value[i] = aid[i] + value[pos];
						pre[i] = pos; //  ����ǰ��·��
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
