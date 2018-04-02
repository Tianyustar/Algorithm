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
void find(int a, int b, int xx, int yy) { // a�������� b�������� �˵�λ�ã� ���Ĳ���
	if (a==0 && b==0) {
//		print(xx);
		count++;
	} else if (a < 0 || b < 0) {
		
		return ;
	}
	// �жϻ���
	if (xx < yy) {
		xx++;
		yy=0;
	}
	// ��a��ͷ
	if (yy == 0) { //  ��ͷ��һ��,����дa Ҳ ����дb
		p_heap[xx][yy] = 'A';// ��A
		find(a-1, b, xx, yy+1);
		p_heap[xx][yy] = 'B';// ��B
		find(a, b-1, xx, yy+1);
	} else { // ���ǵ�һ��
		if (p_heap[xx-1][yy-1] == 'A')  p_heap[xx][yy] = p_heap[xx][yy-1]; // ���ͷ��a����ôӦ�ú�ǰһ��һ��
		if (p_heap[xx-1][yy-1] == 'B')  p_heap[xx][yy] = (p_heap[xx][yy-1] == 'A' ? 'B' : 'A'); // ���ͷ��b Ӧ��ǰһ����һ��
		
		if (p_heap[xx][yy] == 'A') find(a-1,b,xx,yy+1);
		if (p_heap[xx][yy] == 'B') find(a, b-1, xx, yy+1); 
	}

}
int main() {
	// �����ݹ飿
	int n,m;
	cin>>n; // a
	cin>>m; // b
	
	int sum = n+m;
	int step = sqrt(n+m+n+m);
	if (step*(step+1)/2 == sum)
			find(n,m,0,0);
	cout<< count <<endl; 
}
