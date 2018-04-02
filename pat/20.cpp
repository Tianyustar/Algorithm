#include<stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 一直有得分点拿不到 ??  但是思路没有什么毛病？ 
// 
typedef struct node {
	int index;
	double value;
} Conf;
vector<vector<Conf> > info;
double flag[100005]={0};
double sumValue = 0;
void count(Conf older,double  r){
	
	queue<Conf> q;
	q.push(older);
	while(!q.empty()) {
		
		Conf conf = q.front();
		q.pop(); 
		int id = conf.index;
		if (flag[id])  {
			conf.value = conf.value*flag[id];
			sumValue += conf.value;
		}
		for (int i=0;i<info[id].size();i++){
			
			Conf follower = info[id][i];
			follower.value = conf.value*r;
		//	printf("%d %d %lf\n",conf.index,follower.index,follower.value);
			q.push(follower);		
		}		
		
	}

}
int main() {
	
	int num;
	double z;
	double r;
	int k;
	int id;
//	freopen("in.txt","r",stdin);
	Conf conf,older;
	scanf("%d %lf %lf",&num,&z,&r);
	older.index = 0;
	older.value = z;
	double dou;
	info.resize(num+1);// 初始化
	for (int i=0; i<num; i++) {
		scanf("%d",&k);
		if (k==0) {// 得道
			scanf("%lf",&dou); // 第i个人是一个得道者，
			flag[i] = dou; 	
		}else{
			for (int j=0;j<k;j++) {
				scanf("%d",&id);
				conf.index = id;
				conf.value = 0;
				info[i].push_back(conf);
			}
		}
	}
	count(older,(100-r)/100);
	printf("%d\n",(int)sumValue);
	return 0;
}
