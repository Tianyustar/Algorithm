#include<stdio.h>

int  find(int *set, int x) {
	while(set[x]!=x)
		x = set[x];
	return x;
}
void unio(int *set, int x, int y) {
	int fx = find(set, x);
	int fy = find(set, y);
	set[fx] = fy;
} 
int countCity(int *set, int n) {
	int count = 0;
	for (int i=0;i<n;i++) {
		if (set[i] == i)
			count++;
	}
	return count;
} 
void init(int *set, int n) {
		for (int i=0;i<n;i++)  {
		if (set[i] != -1)
			set[i] = i;// 初始化
	}
}
int main()
{
	int map[501][501]={0};
	int set[5001]={0};
	int n,m;
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init(set,n); 
	for (int i=0;i<m;i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
		unio(set, x, y);
	}
	int before = countCity(set, n);
	int k;
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int cityNum;
		scanf("%d",&cityNum);
		for (int i=0;i<n;i++)  {
			map[i][cityNum] = 0;
			map[cityNum][i] = 0;
		}
		set[cityNum] = -1;
		init(set,n);
		for (int i=1;i<n;i++) {
			for (int j=0; j<i ;j++) {
				if (map[i][j]) {
					unio(set,i,j);
				}
			}
		}
		int nowCity = countCity(set,n);
		if (nowCity ==  before || (nowCity == before-1 && nowCity) ){ // 很显然并没有改变城市的连通性 
			printf("City %d is lost.\n",cityNum);
		}else if (nowCity > before){
			printf("Red Alert: City %d is lost!\n",cityNum);
		}else if (nowCity == 0) {
			printf("City %d is lost.\n",cityNum);
			printf("Game Over.\n");
		}
		before = nowCity;
	}
	return 0;
} 


