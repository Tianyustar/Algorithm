#include <cstdio>

using namespace std;

int pe[10005]={0};
int flag[10005]={0};
int find_value(int index) {
	while(pe[index] != index) 
		index = pe[index];
	return index;
}
int UNIO(int a, int b) {
	int fa = find_value(a);
	int fb = find_value(b);
	pe[fa] = fb;
}
void init(int n) {
	for (int i=0;i<n;i++) 
	{
		pe[i] = i;
	}
}
int main()
{
	int n,k;
	int a,b;
	int count = 0;
	init(10005);
	//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&k);
		if (k>0) {
			 scanf("%d",&a);
			 if (flag[a] == 0) count++;
			 flag[a] = 1;
		}
		for (int j=1;j<k;j++) {
			scanf("%d",&b);
			if (flag[b] == 0) count++;
			flag[b] = 1;
			UNIO(a,b);
		}
	}
	int cnt=0;
	for (int i=0;i<10005;i++) {
		if (pe[i] == i && flag[i]) cnt++;
	}	
	printf("%d %d\n",count,cnt);
	scanf("%d",&n);
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (find_value(a) == find_value(b)) {
			puts("Y");
		}else 
		{
			puts("N");
		}
	}
	return 0;
}
