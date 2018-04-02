#include<cstdio>
#include <vector>
#include <hash_map>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
//  mapµÄÊ¹ÓÃ 
typedef struct {
	char name[5];
	int value;
}INFO;
using namespace std; 
int main() {
	
//	freopen("in.txt","r",stdin);
	int n,m;
	INFO info[10000];
	char name[5];
	vector<string> concer;
	map<string, int> list;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%s",name);
		list[name] = 1;
	}
	scanf("%d",&m);
	int sum = 0;
	double aver = 0 ;
	for (int i=0;i<m;i++) {
		scanf("%s %d",info[i].name, &info[i].value);
		sum += info[i].value;
	}
	aver = sum*1.00/m;
	int flag = 1;
	for (int i=0;i<m;i++) {
		if (info[i].value > aver && !(list[info[i].name])){
		//	puts(info[i].name);
			concer.push_back(info[i].name);
			flag = 0;
		}
	}
	sort(concer.begin(),concer.end());
	for (int i=0;i<concer.size();i++){
		puts(concer[i].c_str());
	}
	if (flag) puts("Bing Mei You");
	
	return 0;
} 
