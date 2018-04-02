//��������״���������⣬����ÿ����Ԫ����ջʱ �Ͱ��±�λ�ã���״��+1
// ��ôsum��x���ͱ���˲�����x��Ԫ�صĸ��� 

// question  ����ͨ�ļ�¼Ȼ������ȣ��ٶȿ죿  ���鿪����ô��Ҫά������״������ȻҲ�ʹ󣬲���ķѿ����� 
//  �ٶ�Ӧ��ʱ��sum��x�� ��������x��Ԫ�صĸ������ٶ� 
//  �����ǰ׺��ȥ����ͣ���ôЧ��Ҳ��ܵͣ���Ϊ��Ԫ�ظ���

#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack> 
#include <string.h>
#define MAX 10000

using namespace std;
int N;
int  bittree[MAX + 10];// ��״����
 
inline int lowbit(int x) { // ʹ���������ӿ��ٶ� 
	return x&(-x); 
}

void add(int pos, int x){
	
	for (int i=pos;i<MAX;i += lowbit(i)) {
			bittree[i] += x;
	}
}

int sum(int pos) {
	
	int res = 0;
	for (int i=pos; i>0 ; i -= lowbit(i)) {
		res += bittree[i];
	//	printf(" i = %d\n",i);
	}
	return  res;
}

//bool check(int x , int size) {
//	if (N&2) return sum(x) >= (size+1)/2;
//	return sum(x) >= size/2;
//	
////	puts("have return ");
//}

bool check(int x,int size)  
{  
    if(N&2 == 0)  
        return sum(x) >= size/2;   
    else return sum(x) >= (size+1)/2;  
}  

int main() {
	
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	stack<int> num_stack;
	char command[10]={0};
	N = n;
	while(n--) {
		scanf("%s",command);
		if (strstr(command,"Pop")){
			if (num_stack.empty()) {
				puts("Invalid");
			}else {
				int value = num_stack.top();
				num_stack.pop();
				add(value,-1);// �±�λ�ü�ȥ1 
				printf("%d\n",value);
			}
		}else if (strstr(command,"Push")) {
			int value;
			scanf("%d",&value);
			num_stack.push(value);
			add(value,1); // �±�λ�ü���1  λ����״���� 
		} else {
			if (num_stack.empty())  {
				
				puts("Invalid");
				continue;
			}
			int l = 0, r = MAX;// MAX ʵ���Ͽ��Ա���С���������Ǹо��ò���ʧ��û�б�Ҫ
			
			while(l< r) {
			//	 puts("-------");
				int m = (l+r)/2 ; //  ����
			//	printf("size %d  \n", num_stack.size());
				if (check(m, num_stack.size())) {
					r = m;
				//	 puts("++++++++");
				} else {
				//	puts("++++++++++");
					l=m+1; 
				}
				  
				  
				 // puts("-------");
			}// ֮���Բ�����Ϊ�ҵ�֮���ֹͣ ����Ϊ�����ҵ����ڵ��Ǹ�ֵ
			printf("%d\n",l); 
			
		} 
	}
	
	return 0;
}
