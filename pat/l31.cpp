#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int res[10004]= {0};
int money[10005]= {0};
int res_pos;
int n, aim;
int flag = 0;
// ��ν�����Ч��֦�� // ��ʱû���뵽��Ч�ļ�֦ 
int empty[1005]={0};  // ��¼��������ֽ��
 
void choose(int pos, int money_pos, int money_value) { // ѡ��ڼ���


	if (flag == 1 || money_value > aim) return ;
	
	if (money_value == aim) {
		flag = 1;
	//	cout << "---12---" <<endl;
		res_pos = pos;
		return ; // ����Ҫ�����ݹ�
	}
	if (money_pos >=  n)  return ;
	// ѡ��
	
	if (money_value+money[money_pos] <= aim) {  // ���������������ôװ�� 
		choose(pos+1,money_pos+1,money_value+money[money_pos]);
		res[pos] = money[money_pos] ;
		// ��Ϊ�����Ѿ��ź�˳�� ���������ѡ��Ҳ�ᳬ��������������ôû�б�Ҫ�ٽ�������ö��
		choose(pos,money_pos+1,money_value);
	}

}
int main() {


	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&aim);
	for (int i=0; i<n; i++) {
		scanf("%d",&money[i]);
	}
	sort(money,money+n);
	// ������������ ��ν�����Ч��֦���� 
	choose(0,0,0);
	if (flag==1) {
		printf("%d",res[0]);
		for (int i=1; i<res_pos; i++) {
			printf(" %d",res[i]);
		}
	} else
		puts("No Solution");

	return 0;
}
