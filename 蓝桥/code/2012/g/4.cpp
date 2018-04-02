#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int count = 0;
char p_heap[500][500];

void print(int step) {
	for (int i=0;i<=step;i++) {
		for (int j=0;j<=step;j++) {
			cout<<p_heap[i][j]<<' ';
		}
		cout<<""<<endl;
	}
	cout<<"---------"<<endl;
}
void find(int a, int b, int xx, int yy) { // a的数量， b的数量， 人的位置， 塔的层数
	if (a==0 && b==0) {
//		print(xx);
		count++;
	} else if (a < 0 || b < 0) {
		
		return ;
	}
	// 判断换行
	if (xx < yy) {
		xx++;
		yy=0;
	}
	// 以a开头
	if (yy == 0) { //  开头第一个,可以写a 也 可以写b
		p_heap[xx][yy] = 'A';// 填A
		find(a-1, b, xx, yy+1);
		p_heap[xx][yy] = 'B';// 填B
		find(a, b-1, xx, yy+1);
	} else { // 不是第一个
		if (p_heap[xx-1][yy-1] == 'A')  p_heap[xx][yy] = p_heap[xx][yy-1]; // 如果头是a，那么应该和前一个一样
		if (p_heap[xx-1][yy-1] == 'B')  p_heap[xx][yy] = (p_heap[xx][yy-1] == 'A' ? 'B' : 'A'); // 如果头是b 应和前一个不一样
		
		if (p_heap[xx][yy] == 'A') find(a-1,b,xx,yy+1);
		if (p_heap[xx][yy] == 'B') find(a, b-1, xx, yy+1); 
	}

}
int main() {
	// 暴力递归？
	int n,m;
	cin>>n; // a
	cin>>m; // b
	
	int sum = n+m;
	int step = sqrt(n+m+n+m);
	if (step*(step+1)/2 == sum)
			find(n,m,0,0);
	cout<< count <<endl; 
}
