/*
������Ŀ����ת��Ϊ����������е���Ŀ
������Ҫ�Ǹ���Dilworth���������½�����������������������г��ȣ�
// ʹ��̰���㷨ά��һ���������У����Ǵ����в��������յĽ��

*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
// ʹ��stl�Ķ��ֲ���,���Լ�д�Ķ��־���ë��  emm�� what fuck�� 

int main() { // ������������У�
	vector<int> train;
	vector<int> upLines;
	int n;
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	train.resize(n+1);
	scanf("%d",&train[0]);
	upLines.push_back(train[0]);// ��0ѹ��
	int count = 0;
	for (int i=1; i<n; i++) {
		scanf("%d",&train[i]);
		if(train[i] > upLines[count]) {
			upLines.push_back(train[i]);
			count++;
		} else {
			vector <int>::iterator Iter1, Result1;
			Iter1 =  upper_bound(upLines.begin(),upLines.end(),train[i]);
			//printf("--- %d  %d\n",*Iter1, train[i]);
			*Iter1= train[i];

		}
	}
	printf("%d\n",upLines.size());


}
