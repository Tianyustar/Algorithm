#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
// ����ƿ�ӣ�������
// ��ʲô˼·ȥд��������
// ̰�ģ� ��ƿ�ӽ�������ȷ��λ�ã� 
// ʹ�����ִ��� �������һ�����Ե����ȥ 
int main() {
	
	
	int bott[10005];
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&bott[i]);
	}
	// ̰�ģ� ���ν���λ��, ��ƿ�ӻ�����ȷ��λ��
	int flag = 1;
	int count = 0;

		for (int i=1;i<=n;i++) {
			while (bott[i]!=i) {
				swap(bott[i],bott[bott[i]]);
				flag = 1;
				count++;
			}
	}  
	printf("%d\n",count);
	return 0;
} 
