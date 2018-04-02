// �߶�������������sum�ĺ����ǲ�����x�ĸ�����ÿ��popһ��Ԫ�أ������߶����±�-1  ������
// ÿ��pushһ��Ԫ�� ��Ӧ�߶��� �±�+1 ������

#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>
#define MAX 100005

using namespace std;

typedef struct node {
	int left;
	int right;
	int value;
} NODE;

NODE line_tree[4*MAX+10];

void push_up(int index) { //  ����
	line_tree[index].value = line_tree[index<<1].value + line_tree[index<<1|1].value;// ���Ʋ��� +1
}

// ����

void build(int left , int right ,int index) {

	line_tree[index].left = left;
	line_tree[index].right = right;
	if (left == right) return ;// Ҷ�ӽڵ�  ʵ����Ӧ����Ҫ��ӣ������������ǵ��߶�����һ�ų�ʼȫΪ0���� ���Բ���Ҫ����Ҷ��
	int mid = (left + right)  >> 1;
	build(left,mid,index<<1);//  ����
	build(mid+1,right,index<<1|1);// ����
	// push_up(index);//  ������£��������ڳ�ʼΪ0 ����û�б�Ҫȥ����
}

// ����


//  �о�������º���֡���������Ϊ�кܶ಻��Ҫ�Ķ���
//void update(int left, int right, int index, int pos, int value) // ����  index �����±�, posΪĿ���ַ
//{
//	if (line_tree[index].left == line_tree[index].right && index == pos ) { // ֻ������һ���ڵ㣿��������
//		line_tree[index].value += value;
//		return ;
//	}
//	int mid = (line_tree[index].left + line_tree[index].right) >> 1; //��
//	if  (mid >= pos) {
//		update(left, mid, index<<1, pos, value);// ���mid >= pos  ��ô˵����������
//	} else {
//		update(mid+1, right, index<<1|1,pos, value) ; // ���mind  <= pos ��ô˵����������
//	}
//	line_tree[index].value += line_tree[index<<2].value + line_tree[index<<2|1].value;// ���¸��ڵ�
// }
//
// ����
void Update(int index, int pos, int value) {

//	printf("index = %d pos = %d value  = %d\n ",index, pos, value);
//	printf("left = %d  right = %d  value = %d\n ",line_tree[index].left, line_tree[index].right, line_tree[index].value);
	if (line_tree[index].left == line_tree[index].right && line_tree[index].right == pos) {
		line_tree[index].value += value;
		return ; // һ��Ҫ�ǵ�return
	}
	//  ���pos <= ������ ��right
	if (pos <= line_tree[index<<1].right)  {
		Update(index<<1,pos,value);
	} else {
		Update(index<<1|1,pos,value);// ȥ������
	}
	line_tree[index].value = line_tree[index<<1].value + line_tree[index<<1|1].value;

}

// ��ѯλ��

int query(int index,int sum )  { // i �����߶����ĵ�i���ڵ㣬 sum����Ҫ��ѯ�ĵ�k�����

	//printf("index = %d sum =  %d\n",index, sum);
	//printf("index = %d left = %d right = %d value = %d\n",
	    //   index, line_tree[index].left, line_tree[index].right, line_tree[index].value);
	if (line_tree[index].left == line_tree[index].right) {

		return line_tree[index].left;
	}
	if (sum <= line_tree[index<<1].value) { // ���С�ڵ�����������ֵ ����ô�������� ��Ҫע���������һ��Ҫ�ӵ��ں�
		return 	query(index<<1, sum);
	} else
		return  query(index<<1|1, sum-line_tree[index<<1].value); // ���ұ߲�ѯ Ҫ��ȥ��������ֵ 
}
int main() {
	int n;
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	stack<int> num_stack;
	char command[10]= {0};
	build(0,MAX,1); // ��1 �� MAX ������ ,1Ϊ���
	while(n--) {
		scanf("%s",command);
		if (strstr(command,"Pop")) {
			if (num_stack.empty()) {
				puts("Invalid");
			} else {
				int value = num_stack.top();
				num_stack.pop();
				Update(1,value,-1);  // ��������
				printf("%d\n",value);
			}
		} else if (strstr(command,"Push")) {
			int value;
			scanf("%d",&value);
			num_stack.push(value);
			Update(1,value,1) ;// �±�λ�ü���1  λ����״����
		} else {
			if (num_stack.empty())  {
				puts("Invalid");
				continue;
			}
			int len = num_stack.size();
			//printf("len = %d \n",len);
			if (len%2) {
				//	puts("mod 1");
				printf("%d\n",query(1,(len+1)/2));
				//	printf("len +1 /2 = %d \n",(len+1)/2);
			} else {
				//	puts("mod 2");
				printf("%d\n",query(1,len/2));
			}


		}
	}
	return 0;
}
