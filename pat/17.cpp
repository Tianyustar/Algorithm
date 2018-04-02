
// 同辈还是不行的  必须要用bfs

/*
 要注意的是  测试数据中可能包含某个人的父亲 ， 所以要把父亲母亲的性别也标记一下 
 测试数据里面会有判断父母的
  
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

// 利用优先搜索搜索5层
void isOk(int IdA, int IdB, People *pe) {
	set<int> setid;
	int level[100005] = {0};
	queue<int> q;// 可以两个一起遍历
	q.push(IdA);
	q.push(IdB);
	while(! q.empty() ) {
		int top = q.front();
		q.pop(); // 出栈
		int bsize = setid.size();
		setid.insert(top);
		if (bsize == setid.size()) { // 有重复元素
		//	printf(" -- %d \n",top);
			puts("No");
			return ;
		}
		// bfs
		if (pe[top].father == -2 ) continue; //  如果这个人是不存在的

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
	for (int i=0; i<n; i++) { // 输入信息
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
