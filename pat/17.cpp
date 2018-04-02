
// ͬ�����ǲ��е�  ����Ҫ��bfs

/*
 Ҫע�����  ���������п��ܰ���ĳ���˵ĸ��� �� ����Ҫ�Ѹ���ĸ�׵��Ա�Ҳ���һ�� 
 ����������������жϸ�ĸ��
  
*/
#include <stdio.h>
#include <set>
#include <queue>
using namespace std;
typedef struct Node {
	int father;
	int mather;
	char sex;
} People;

// ����������������5��
void isOk(int IdA, int IdB, People *pe) {
	set<int> setid;
	int level[100005] = {0};
	queue<int> q;// ��������һ�����
	q.push(IdA);
	q.push(IdB);
	while(! q.empty() ) {
		int top = q.front();
		q.pop(); // ��ջ
		int bsize = setid.size();
		setid.insert(top);
		if (bsize == setid.size()) { // ���ظ�Ԫ��
		//	printf(" -- %d \n",top);
			puts("No");
			return ;
		}
		// bfs
		if (pe[top].father == -2 ) continue; //  ���������ǲ����ڵ�

		if (level[top] < 4) {
			if (pe[top].father != -1)  {
				level[pe[top].father] = level[top] + 1;
				q.push(pe[top].father);
			}
			if (pe[top].mather != -1) {
				level[pe[top].mather] = level[top] +1;
				q.push(pe[top].mather);
			}
		}
	}

	puts("Yes");
}
int main() {
	People pe[100010];
	int n,id , fId, mId;
	char sex;
		freopen("in.txt","r",stdin);
	scanf("%d",&n);
	// chushihua
	for (int i=0; i<100010; i++) {
		pe[i].father = -2;
		pe[i].mather = -2;
		pe[i].sex = 'N';
	}
	for (int i=0; i<n; i++) { // ������Ϣ
		scanf("%d %c %d %d",&id,&sex,&fId, &mId);
		pe[id].father = fId;
		pe[id].mather = mId;
		pe[id].sex = sex;
		pe[fId].sex = 'M';
		pe[mId].sex = 'F' ;
	}
	int k;
	scanf("%d",&k);
	while(k--) {
		int id1, id2;
		scanf("%d%d",&id1,&id2);
		if (pe[id1].sex == pe[id2].sex) {
			puts("Never Mind");
		} else {
			isOk(id1,id2,pe);
		}
	}

	return 0;
}
